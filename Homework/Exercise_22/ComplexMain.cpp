#include <iostream>
#include <vector>
#include "Complex.h"

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::vector;

int main()
{
     COMPLEX c1, c2;
     double num = 0;

     //all the while loop does is to check whether the input value is correct
     // if not correct, prompt the user to try again
     // exit while when when the correct input is entered
     cout << "Enter the real and Imag part of first complex number: ";
     cin >> c1.Re >> c1.Im;
     while (cin.fail())
     {
          cout << "\nIncorrect value entered for first Complex number. Try again" << endl;
          cin.clear();
          cin.ignore(256, '\n');
          cout << "Enter the real and Imag part of first complex number: ";
          cin >> c1.Re >> c1.Im;
     }

     cout << "Enter the real and Imag part of second complex number: ";
     cin >> c2.Re >> c2.Im;
     // if the user entered an invalid character
     while (cin.fail())
     {
          cout << "\nIncorrect value entered for second Complex number. Try again" << endl;
          // reset any error flags
          cin.clear();
          // ignore any extra characters in the input buffer
          cin.ignore(256, '\n');
          cout << "Enter the real and Imag part of second complex number: ";
          cin >> c2.Re >> c2.Im;
     }
     cout << "Enter a constant double number: ";
     cin >> num;
     // if the user entered an invalid character por zero entered
     // this prevents division by zero
     while (cin.fail() || num == 0)
     {
          cout << "\nYou either entered an invalid number or you entered a zero" << endl;
          cout << "\nCannot divide by zero. Try again" << endl;
          cin.clear();
          cin.ignore(256, '\n');
          cout << "Enter a constant double number:";
          cin >> num;
     }

     /**
 * Placing some COMPLEX object inside a vector
 */
     int i;
     vector<COMPLEX> COMPLEX_vect;

     for (i = 0; i < 5; i++) // load vector
          COMPLEX_vect.push_back(COMPLEX(i * c1 + c1));

     cout << "Vector displayed: " << endl;
     for (i = 0; i < COMPLEX_vect.size(); i++) // display vector
          cout << COMPLEX_vect[i] << endl;
}
