#include <iostream>

int main()
{
    int scores[] = {84, 92, 76, 81, 56};
    const int numStudents = sizeof(scores) / sizeof(scores[0]);

    int maxIndex = 0; // keep track of index of our largest score

    // now look for a larger score
    for (int student = 0; student < numStudents; ++student)
        if (scores[student] > scores[maxIndex])
            maxIndex = student;

    std::cout << "The best score was " << scores[maxIndex] << '\n';

    return 0;
}