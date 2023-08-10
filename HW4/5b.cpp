// LeetCode 205: Isomorphic Strings using one to one comparison and hashmap

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.length(); //save length for expediency
        if(len != t.length()) { //if strings differ in length
            return false;
        }

        unordered_map<char, char> sMap; //saves mapping
        unordered_map<char, char> tMap;
        for(int i = 0; i < len; i++) { //traverse through string
            if(sMap.contains(s[i]) && tMap.contains(t[i])) { // if already seen character
                if(sMap.find(s[i])->second != t[i] || tMap.find(t[i])->second != s[i]) { // check mapping
                    return false; // returns false if it doesn't match mapping
                }
                continue; 
            } else if(sMap.contains(s[i]) || tMap.contains(t[i])) { 
                return false; // maps don't match
            }
            
            sMap.insert({s[i], t[i]}); // marks as seen
            tMap.insert({t[i], s[i]});
        }

        return true;
    }
};
