#include <algorithm>
#include <cstring>
#include <iostream>
#include <random>

using namespace std;

// checks if all characters are digits
bool allDigits(const string &stringOfDigits) {
  return all_of(stringOfDigits.begin(), stringOfDigits.end(),
                [](char digit) { return (digit >= '0' && digit <= '9'); });
}

// shuffles the string and returns the result
string shuffleString(string stringOfDigits) {
  auto length = stringOfDigits.length();

  // creates the random number generator
  random_device randomDevice;
  mt19937 randomNumberGenerator(randomDevice());

  // swaps based on random number
  all_of(stringOfDigits.begin(), stringOfDigits.end(), [&](char &current) {
    uniform_int_distribution<int> dist(0, static_cast<int>(length) - 1);
    int randomNumber = dist(randomNumberGenerator);

    swap(current, stringOfDigits[randomNumber]);

    return true;
  });

  return stringOfDigits;
}

// prints stringOfDigits in a 3x3 grid
/*  +-------+
    | # # # |
    | # # # |
    | # # # |
    +-------+
*/
void print3x3(string stringOfDigits) {
  cout << "+-------+" << endl;
  for (int iterator = 0; iterator < stringOfDigits.length(); iterator++) {
    if (iterator % 3 == 0) {
      cout << "| " << stringOfDigits[iterator];
    } else if (iterator % 3 == 1) {
      cout << " " << stringOfDigits[iterator];
    } else {
      cout << " " << stringOfDigits[iterator] << " |" << endl;
    }
  }
  cout << "+-------+" << endl;
}

// checks if the array has only integers (use for command line arguments)
bool isInteger(const char array[]) {
  int size = strlen(array);
  for (int i = 0; i < size; i++) {
    if (!isdigit(array[i])) {
      return false;
    }
  }
  return true;
}

int main(int argCount, char *argValue[]) {

  // checks if there is a command line argument && it is a digit
  if (argCount != 2 || !isInteger(argValue[1])) {
    cerr << "Invalid command line argument." << endl;
    return 1;
  }

  // converts command line argument into a integer
  int numberOfShuffles = atoi(argValue[1]);

  // checks that command line argument is a single digit
  if (numberOfShuffles >= 10) {
    cerr << "Invalid number. Please enter a number less than 10" << endl;
    return 1;
  }

  // gathers input, loops if input not accepted
  string input;
  do {
    if (input.length() > 0) { // this happens if this do-while loops
      cout << "Invalid number. ";
    }
    cout << "Please input 9 digits to be randomly shuffled: ";
    cin >> input;
    cout << endl;
    if (!allDigits(input)) { // makes sure all inputed values are digits
      input = "0";           // if not all digits ensures the loop repeats
    }
  } while (input.length() != 9);

  // preserves input, shuffles, and prints each shuffle
  string next = input;
  string loopNames[] = {"first", "second",  "third",  "fourth", "fifth",
                        "sixth", "seventh", "eighth", "ninth"};
  for (int i = 0; i < numberOfShuffles; i++) {
    cout << "The " << loopNames[i] << " shuffled output is: " << endl;
    next = shuffleString(next);
    print3x3(next);
  }

  cout << "Done." << endl;

  return 0;
};