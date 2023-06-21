#include <iostream>

using namespace std;

int main(int argCount, char *argValue[])
{
    // checks if there is a command line argument
    if (argCount < 2)
    {
        cerr << "Missing command line argument." << endl;
        return 1;
    }

    // converts command line argument into a integer
    int numberOfShuffles = atoi(argValue[1]);

    // checks that command line argument is a single digit
    if (numberOfShuffles >= 10)
    {
        cerr << "Invalid number. Please enter a number less than 10" << endl;
        return 1;
    }

    string input;
    do
    {
        if (input.length() > 0)
        { // this happens if this do-while loops
            cout << "Invalid number. ";
        }
        cout << "Please input 9 digits to be randomly shuffled:";
        cin >> input;
        if (!AllDigits(input))
        {                         // makes sure all inputed values are digits
            input = "0000000000"; // if not all digits ensures the loop repeats
        }
    } while (input.length() > 9);

    string next = input;
    while (numberOfShuffles > 0)
    {
        next = shuffleString(next);
        print3x3(next);
    }
    return 0;
}

bool AllDigits(string s)
{
    for (char c : s)
    {
        if (!(c >= '0' && c <= '9'))
        {
            return false;
        }
    }
    return true;
}

string shuffleString(string s)
{
    for (int i = 0; i < s.length(); i++)
    {

        srand(time(0));
        int randomNumber = rand() % s.length();

        char temp = s[i];
        s[i] = s[randomNumber];
        s[randomNumber] = temp;
    }
    return s;
}

void print3x3(string s)
{
    cout << "+-------+" << endl;
    for (int i = 0; i < s.length(); i++)
    {
        if (i % 3 == 0)
        {
            cout << "| " << s[i];
        }
        else if (i % 3 == 1)
        {
            cout << " " << s[i];
        }
        else
        {
            cout << " " << s[i] << " |" << endl;
        }
    }
    cout << "+-------+" << endl;
}