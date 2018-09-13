#include <iostream>
#include <string>
#include <iomanip>

struct infoDisplay
{
    std::string Name = "Chisom Esele";
    std::string Email = "esele001@umn.edu";
    std::string highSchool = "University of Nigeria Secondary School, Nsukka";
    std::string homeTown = "Imo State, Nigeria";
    std::string currentCollege = "Normandale Community College";
    std::string currentYearInSchool = "Graduated";
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

    std::cout << "Enter the size of student information: " << std::flush;
    std::cin >> arraySize;

    // this allocates new memory space to hold the  infoDisplay Struct
    dummyPrint = new infoDisplay[arraySize];

    std::cout << std::setw(24) << "Name: " << dummyPrint->Name << std::endl;
    std::cout << std::setw(24) << "E-mail: " << dummyPrint->Email << std::endl;
    std::cout << std::setw(24) << "Hig School: " << dummyPrint->highSchool << std::endl;
    std::cout << std::setw(24) << "Home town: " << dummyPrint->homeTown << std::endl;
    std::cout << std::setw(24) << "Current College: " << dummyPrint->currentCollege << std::endl;
    std::cout << "Current year in school: " << dummyPrint->currentYearInSchool << std::endl;
    std::cout << std::setw(24) << "Age: " << dummyPrint->Age << std::endl;
    std::cout << std::setw(24) << "Age in octal: " << std::oct << dummyPrint->Age << std::endl;
    std::cout << std::setw(24) << "Age in hexadecimal: " << std::hex << dummyPrint->Age << std::endl;
    std::cout << "\n\n";

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
    std::cout << "Struct value is printed by passing the value to printInfoDisplay1 function" << std::endl;
    std::cout << std::setw(24) << "Name: " << byValue.Name << std::endl;
    std::cout << std::setw(24) << "E-mail: " << byValue.Email << std::endl;
    std::cout << std::setw(24) << "Hig School: " << byValue.highSchool << std::endl;
    std::cout << std::setw(24) << "Home town: " << byValue.homeTown << std::endl;
    std::cout << std::setw(24) << "Current College: " << byValue.currentCollege << std::endl;
    std::cout << "Current year in school: " << byValue.currentYearInSchool << std::endl;
    std::cout << std::setw(24) << "Age: " << std::dec << byValue.Age << std::endl;
    std::cout << std::setw(24) << "Age in octal: " << std::oct << byValue.Age << std::endl;
    std::cout << std::setw(24) << "Age in hexadecimal: " << std::hex << byValue.Age << std::endl;
    std::cout << "\n\n";
}

// Struct is passed to this function by refernce
void printInfoDisplay2(infoDisplay *byRefernce)
{
    std::cout << "Struct value is printed by passing the address to printInfoDisplay2 function" << std::endl;
    std::cout << std::setw(24) << "Name: " << byRefernce->Name << std::endl;
    std::cout << std::setw(24) << "E-mail: " << byRefernce->Email << std::endl;
    std::cout << std::setw(24) << "Hig School: " << byRefernce->highSchool << std::endl;
    std::cout << std::setw(24) << "Home town: " << byRefernce->homeTown << std::endl;
    std::cout << std::setw(24) << "Current College: " << byRefernce->currentCollege << std::endl;
    std::cout << "Current year in school: " << byRefernce->currentYearInSchool << std::endl;
    std::cout << std::setw(24) << "Age: " << std::dec << byRefernce->Age << std::endl;
    std::cout << std::setw(24) << "Age in octal: " << std::oct << byRefernce->Age << std::endl;
    std::cout << std::setw(24) << "Age in hexadecimal: " << std::hex << byRefernce->Age << std::endl;
    std::cout << "\n\n";
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

