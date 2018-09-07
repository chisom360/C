#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct infoDisplay
{
    string Name = "Chisom Esele";
    string Email = "esele001@umn.edu";
    string highSchool = "University of Nigeria Secondary School, Nsukka";
    string homeTown = "Imo State, Nigeria";
    string currentCollege = "Normandale Community College";
    string currentYearInSchool = "Graduated";
    int Age = 30;
};

// inforDisplay struct is passed by value
void printInfoDisplay1(infoDisplay byValue);

// inforDisplay struct is passed by reference
void printInfoDisplay2(infoDisplay *byRefernce);

int main()
{
    int arraySize;
    infoDisplay *dummyPrint;

    cout << "Enter the size of student information: " << flush;
    cin >> arraySize;

    // this allocates new memory space to hold the  infoDisplay Struct
    dummyPrint = new infoDisplay[arraySize];

    cout << setw(24) << "Name: " << dummyPrint->Name << endl;
    cout << setw(24) << "E-mail: " << dummyPrint->Email << endl;
    cout << setw(24) << "Hig School: " << dummyPrint->highSchool << endl;
    cout << setw(24) << "Home town: " << dummyPrint->homeTown << endl;
    cout << setw(24) << "Current College: " << dummyPrint->currentCollege << endl;
    cout << "Current year in school: " << dummyPrint->currentYearInSchool << endl;
    cout << setw(24) << "Age: " << dummyPrint->Age << endl;
    cout << setw(24) << "Age in octal: " << oct << dummyPrint->Age << endl;
    cout << setw(24) << "Age in hexadecimal: " << hex << dummyPrint->Age << endl;
    cout << "\n\n";

    for (int i = 0; i < arraySize; i++)
    {
        printInfoDisplay1(dummyPrint[i]);
        printInfoDisplay2(&dummyPrint[i]);
    }

    delete[] dummyPrint;

    return 0;
}

// Struct is passed to this function by value
void printInfoDisplay1(infoDisplay byValue)
{
    cout << "Struct value is printed by passing the value to printInfoDisplay1 function" << endl;
    cout << setw(24) << "Name: " << byValue.Name << endl;
    cout << setw(24) << "E-mail: " << byValue.Email << endl;
    cout << setw(24) << "Hig School: " << byValue.highSchool << endl;
    cout << setw(24) << "Home town: " << byValue.homeTown << endl;
    cout << setw(24) << "Current College: " << byValue.currentCollege << endl;
    cout << "Current year in school: " << byValue.currentYearInSchool << endl;
    cout << setw(24) << "Age: " << dec << byValue.Age << endl;
    cout << setw(24) << "Age in octal: " << oct << byValue.Age << endl;
    cout << setw(24) << "Age in hexadecimal: " << hex << byValue.Age << endl;
    cout << "\n\n";
}

// Struct is passed to this function by refernce
void printInfoDisplay2(infoDisplay *byRefernce)
{
    cout << "Struct value is printed by passing the address to printInfoDisplay2 function" << endl;
    cout << setw(24) << "Name: " << byRefernce->Name << endl;
    cout << setw(24) << "E-mail: " << byRefernce->Email << endl;
    cout << setw(24) << "Hig School: " << byRefernce->highSchool << endl;
    cout << setw(24) << "Home town: " << byRefernce->homeTown << endl;
    cout << setw(24) << "Current College: " << byRefernce->currentCollege << endl;
    cout << "Current year in school: " << byRefernce->currentYearInSchool << endl;
    cout << setw(24) << "Age: " << dec << byRefernce->Age << endl;
    cout << setw(24) << "Age in octal: " << oct << byRefernce->Age << endl;
    cout << setw(24) << "Age in hexadecimal: " << hex << byRefernce->Age << endl;
    cout << "\n\n";
}

/*  output
               Enter the size of student information: 2
                  Name: Chisom Esele
                E-mail: esele001@umn.edu
            Hig School: University of Nigeria Secondary School, Nsukka
             Home town: Imo State, Nigeria
       Current College: Normandale Community College
Current year in school: Graduated
                   Age: 30
          Age in octal: 36
    Age in hexadecimal: 1e


Struct value is printed by passing the value to printInfoDisplay1 function
                  Name: Chisom Esele
                E-mail: esele001@umn.edu
            Hig School: University of Nigeria Secondary School, Nsukka
             Home town: Imo State, Nigeria
       Current College: Normandale Community College
Current year in school: Graduated
                   Age: 30
          Age in octal: 36
    Age in hexadecimal: 1e


Struct value is printed by passing the address to printInfoDisplay2 function
                  Name: Chisom Esele
                E-mail: esele001@umn.edu
            Hig School: University of Nigeria Secondary School, Nsukka
             Home town: Imo State, Nigeria
       Current College: Normandale Community College
Current year in school: Graduated
                   Age: 30
          Age in octal: 36
    Age in hexadecimal: 1e


Struct value is printed by passing the value to printInfoDisplay1 function
                  Name: Chisom Esele
                E-mail: esele001@umn.edu
            Hig School: University of Nigeria Secondary School, Nsukka
             Home town: Imo State, Nigeria
       Current College: Normandale Community College
Current year in school: Graduated
                   Age: 30
          Age in octal: 36
    Age in hexadecimal: 1e


Struct value is printed by passing the address to printInfoDisplay2 function
                  Name: Chisom Esele
                E-mail: esele001@umn.edu
            Hig School: University of Nigeria Secondary School, Nsukka
             Home town: Imo State, Nigeria
       Current College: Normandale Community College
Current year in school: Graduated
                   Age: 30
          Age in octal: 36
    Age in hexadecimal: 1e
    */