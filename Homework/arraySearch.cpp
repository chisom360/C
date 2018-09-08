#include <iostream>
 
int main()
{
    // First, read in valid input from user
    int number = 0;
    do
    {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> number;
 
        // if the user entered an invalid character
        if (std::cin.fail())
            std::cin.clear(); // reset any error flags
 
        std::cin.ignore(32767, '\n'); // ignore any extra characters in the input buffer
 
    } while (number < 1 || number > 9);
 
    // Next, print the array
    int array[] = { 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    const int arrayLength = sizeof(array) / sizeof(array[0]);
 
    for (int index=0; index < arrayLength; ++index)
        std::cout << array[index] << " ";
 
    std::cout << "\n";
 
    // Then, search the array to find the matching number and print the index
    for (int index=0; index < arrayLength; ++index)
    {
        if (array[index] == number)
        {
            std::cout <<  "The number " << number << " has index " <<  index << "\n";
            break; // since each # in the array is unique, no need to search rest of array
        }
    }
 
    return 0;
}