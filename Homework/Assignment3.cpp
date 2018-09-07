#include <iostream>
#include "Assignment3.h"
using namespace std;

int main()
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        continue;

    student *ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete[] ptr_stu;
    cout << "Done\n";
    return 0;
}

/*        output  

bigshow360@kali:~/Documents/C++/Homework$ ./a.out 
Enter class size: 2
Enter student 1 name: Chisom Esele
Enter student 1 hobby: Weight Lifting
Enter student 0 oopLevel: 3

Enter student 2 name: Michael Jordan
Enter student 2 hobby: Basketball
Enter student 1 oopLevel: 23

This prints out Display()1
Student fullname is: Chisom Esele
Student hobby is: Weight Lifting
students OOP level is: 3


This prints out Display2()
Student fullname is: Chisom Esele
Student hobby is: Weight Lifting
students OOP level is: 3


This prints out Display()1
Student fullname is: Michael Jordan
Student hobby is: Basketball
students OOP level is: 23


This prints out Display2()
Student fullname is: Michael Jordan
Student hobby is: Basketball
students OOP level is: 23


This prints out Display3()
Student fullname is: 1
Student hobby is: Chisom Esele
students OOP level is: 3


This prints out Display3()
Student fullname is: 2
Student hobby is: Michael Jordan
students OOP level is: 23


Done
bigshow360@kali:~/Documents/C++/Homework$ 

*/