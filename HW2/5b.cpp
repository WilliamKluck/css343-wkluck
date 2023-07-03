class Solution
{
public:
    // adds one to the char value at the index
    string add(const string &current, int index)
    {
        string result = current;

        // Check if the index is within the bounds of the string
        if (index >= 0 && index < result.length())
        {
            int digit = result[index] - '0';
            digit = (digit + 1) % 10;
            result[index] = digit + '0';
        }
        return result;
    }

    // subtracts one to the char value at the index
    string sub(const string &current, int index)
    {
        string result = current;

        // Check if the index is within the bounds of the string
        if (index >= 0 && index < result.length())
        {
            int digit = result[index] - '0';
            digit = (digit - 1 + 10) % 10;
            result[index] = digit + '0';
        }
        return result;
    }

    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> seen;
        // adding deadends into memoization
        for (string s : deadends)
        {
            seen.insert(s);
        }
        string current = "0000";

        // for case that lock is stuck at beginning
        if (seen.count(current) == 1)
        {
            return -1;
        }

        queue<string> q;
        q.push(current);
        int level = 0;
        int count = 0;
        int tempCount = 0;
        int qSize = -1;

        while (!q.empty())
        {
            // indicates that previous level all got stuck
            if (tempCount == qSize)
            {
                return -1;
            }
            tempCount = 0;

            qSize = q.size();

            // iterates through the current level
            for (int iter = 0; iter < qSize; iter++)
            {
                current = q.front();
                q.pop();

                // answer found!
                if (current == target)
                {
                    return count;
                }

                // check against the memoization, loop or add
                if (seen.find(current) != seen.end())
                {
                    tempCount++;
                    continue;
                }
                else
                {
                    seen.insert(current);
                }

                // inserts next level into queue (8 per string)
                for (int i = 0; i < 4; i++)
                {
                    q.push(add(current, i));
                    q.push(sub(current, i));
                }
            }
            count++;
        }
        return -1;
    }
};