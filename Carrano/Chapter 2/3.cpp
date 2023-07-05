/* Question 3 Given an integer n > 0, write a recursive function countDown that writes the
integers n , n – 1, . . . , 1. Hint: What task can you do and what task can you ask a friend to do
for you? */
#include <iostream>
using namespace std;

void countDown(int n)
{
    if (n == 1)
    {
        cout << 1 << "." << endl;
    }
    cout << n << ", ";
}