#ifndef FUNC_H
#define FUNC_H

#include <iostream>
using namespace std;

const int SLEN = 30;

struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

// getinfo() has two arguments : a pointer to the first element of
// an array of student structures and an int representing the
// number of elements of the array. The function solicits and
// stores data about students. It terminates input upon filling
// the array or upon encountering a blank line for the student
// name. The function returns the actual number of array elements
// filled.
int getinfo(student pa[], int n);

// display1() takes a student structure as an argument
// and displays its contents
void display1(student st);

// display2() takes the address of student structure as an
// argument and displays the structure's contents
void display2(const student *ps);

// display3() takes the address of the first element of an array
// of student structures and the number of array elements as
// arguments and displays the contents of the structures
void display3(const student pa[], int n);

void display1(student st)
{
    cout << "This prints out Display()1" << endl;
    cout << "Student fullname is: " << st.fullname << endl;
    cout << "Student hobby is: " << st.hobby << endl;
    cout << "students OOP level is: " << st.ooplevel << endl;
    cout << "\n\n";
}

void display2(const student *ps)
{
    cout << "This prints out Display2()" << endl;
    cout << "Student fullname is: " << ps->fullname << endl;
    cout << "Student hobby is: " << ps->hobby << endl;
    cout << "students OOP level is: " << ps->ooplevel << endl;
    cout << "\n\n";
}

void display3(const student pa[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << "This prints out Display3()" << endl;
        cout << "Student fullname is: " << (i + 1) << "\n";
        cout << "Student hobby is: " << pa[i].fullname << "\n";
        cout << "students OOP level is: " << pa[i].ooplevel << "\n";
        cout << "\n\n";
    }
}

int getinfo(student pa[], int n)
{
    int studentIndex = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter student " << (studentIndex + 1) << " name: ";
        cin.getline(pa[i].fullname, SLEN);

        if (pa[i].fullname[0] == '\0')
            break;
        cout << "Enter student " << (studentIndex + 1) << " hobby: ";
        cin.getline(pa[i].hobby, SLEN);

        cout << "Enter student " << studentIndex++ << " oopLevel: ";
        (cin >> pa[i].ooplevel).get();
        cout << '\n';
    }
    return studentIndex;
}

#endif
