#include <iostream>
#include "Complex.h"
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ios;
using std::ofstream;
using std::ostream;

int main()
{
    ofstream out;
    COMPLEX c1, c2, cresult;
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

    out.open("Complex.txt");

    out << "===========Operator addition==========" << endl;
    cresult = c1 + c2; // addition operator COMPLEX + COMPLEX
    out << "Result of " << (c1);
    out << " + "
        << "(" << c2 << ")";
    out << " = " << (cresult);
    out << endl;

    cresult = c1 + num; // addition operator COMPLEX + double
    out << "Result of " << (c1);
    out << " + "
        << "(" << num << ")"
        << " = " << (cresult);
    out << endl;

    cresult = num + c1; // addition operator double + COMPLEX
    out << "Result of "
        << "(" << num << ")"
        << " + "
        << "(" << c1 << ")";
    out << " = "
        << (cresult);
    out << endl;
    out << "\n\n";

    out << "=======Operator Subtraction==========" << endl;
    cresult = c1 - (c2); // Subtraction operator COMPLEX -  COMPLEX
    out << "Result of "
        << (c1);
    out << " - "
        << "(" << c2 << ")";
    out << " = "
        << (cresult);
    out << endl;

    cresult = c1 - num; // Subtraction operator COMPLEX -  double
    out << "Result of "
        << (c1);
    out << " - "
        << "(" << num << ")"
        << " = "
        << (cresult);
    out << endl;

    cresult = num - c1; // Subtraction operator double -  COMPLEX
    out << "Result of "
        << "(" << num << ")"
        << " - "
        << "(" << c1 << ")";
    out << " = "
        << (cresult);
    out << endl;
    out << "\n\n";

    out << "=======Operator Multiplication==========" << endl;
    cresult = c1 * c2; // multiply operator COMPLEX * COMPLEX
    out << "Result of "
        << (c1);
    out << " * "
        << "(" << c2 << ")";
    out << " = "
        << (cresult);
    out << endl;

    cresult = c1 * num; // multiply operator COMPLEX * double
    out << "Result of "
        << (c1);
    out << " * "
        << "(" << num << ")"
        << " = "
        << (cresult);
    out << endl;

    cresult = num * c1; // multiply operator double * COMPLEX
    out << "Result of "
        << "(" << num << ")"
        << " * "
        << "(" << c1 << ")";
    out << " = "
        << (cresult);
    out << endl;
    out << "\n\n";

    out << "===========Operator Division==========" << endl;
    cresult = c1 / c2; // divide operator CPMLEX / COMPLEX
    out << "Result of "
        << (c1);
    out << " / "
        << "(" << c2 << ")";
    out << " = "
        << (cresult);
    out << endl;

    cresult = c1 / num; // divide operator COMPLEX / double
    out << "Result of "
        << (c1);
    out << " / "
        << "(" << num << ") = "
        << (cresult);
    out << endl;

    cresult = num / (c2); // divide operator double / COMPLEX
    out << "Result of "
        << "(" << num << ")";
    out << " / "
        << "(" << c2 << ")";
    out << " = "
        << (cresult);
    out << endl;

    return 0;
}
