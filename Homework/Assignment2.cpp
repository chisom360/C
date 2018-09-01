#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    string Name = "Chisom Esele";
    string Email = "esele001@umn.edu";
    string highSchool = "University of Nigeria Secondary School, Nsukka";
    string homeTown = "Imo State, Nigeria";
    string currentCollege = "Normandale Community College";
    string currentYearInSchool = "Graduated";
    int Age = 30;

    cout << setw(24) << "Name: " << Name << endl;
    cout << setw(24) << "E-mail: " << Email << endl;
    cout << setw(24) << "Hig School: " << highSchool << endl;
    cout << setw(24) << "Home town: " << homeTown << endl;
    cout << setw(24) << "Current College: " << currentCollege << endl;
    cout << "Current year in school: " << currentYearInSchool << endl;
    cout << setw(24) << "Age: " << Age << endl;
    cout << setw(24) << "Age in octal: " << oct << Age << endl;
    cout << setw(24) << "Age in hexadecimal: " << hex << Age << endl;

    return 0;
}

/* output 


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