/*
How does it work? This program uses a pointer to step through each of the elements in an array. Remember that arrays decay to pointers to the first element of the array. So by assigning ptr to name, ptr will also point to the first element of the array. Each element is dereferenced by the switch expression, and if the element is a vowel, numVowels is incremented. Then the for loop uses the ++ operator to advance the pointer to the next character in the array. The for loop terminates when all characters have been examined.

The above program produces the result:

Mollie has 3 vowels


*/

#include <iostream>
using namespace std;

int main()
{
    const int arrayLength = 7;
    char name[arrayLength] = "Mollie";
    int numVowels = 0;
    for (char *ptr = name; ptr < name + arrayLength; ++ptr)
    {
        switch (*ptr)
        {
            case 'A':
            case 'a':
            case 'E':
            case 'e':
            case 'I':
            case 'i':
            case 'O':
            case 'o':
            case 'U':
            case 'u':
                ++numVowels;
        }
    }
 
    cout << name << " has " << numVowels << " vowels.\n";
 
    return 0;
}


