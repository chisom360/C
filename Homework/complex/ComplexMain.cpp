#include <iostream>
#include "Complex.h"
using namespace std;

int main()
{
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

    cout << "===========Operator addition==========" << endl;
    cresult = c1 + c2; // addition operator COMPLEX + COMPLEX
    cout << "Result of ";
    print(c1);
    cout << " + ";
    print(c2);
    cout << " = ";
    print(cresult);
    cout << endl;

    cresult = c1 + num; // addition operator COMPLEX + double
    cout << "Result of ";
    print(c1);
    cout << " + "
         << "(" << num << ")"
         << " = ";
    print(cresult);
    cout << endl;

    cresult = num + c1; // addition operator double + COMPLEX
    cout << "Result of "
         << "(" << num << ")"
         << " + ";
    print(c1);
    cout << " = ";
    print(cresult);
    cout << endl;
    cout << "\n\n";

    cout << "=======Operator Subtraction==========" << endl;
    cresult = c1 - c2; // Subtraction operator COMPLEX -  COMPLEX
    cout << "Result of ";
    print(c1);
    cout << " - ";
    print(c2);
    cout << " = ";
    print(cresult);
    cout << endl;

    cresult = c1 - num; // Subtraction operator COMPLEX -  double
    cout << "Result of ";
    print(c1);
    cout << " - "
         << "(" << num << ")"
         << " = ";
    print(cresult);
    cout << endl;

    cresult = num - c1; // Subtraction operator double -  COMPLEX
    cout << "Result of "
         << "(" << num << ")"
         << " - ";
    print(c1);
    cout << " = ";
    print(cresult);
    cout << endl;
    cout << "\n\n";

    cout << "=======Operator Multiplication==========" << endl;
    cresult = c1 * c2; // multiply operator COMPLEX * COMPLEX
    cout << "Result of ";
    print(c1);
    cout << " * ";
    print(c2);
    cout << " = ";
    print(cresult);
    cout << endl;

    cresult = c1 * num; // multiply operator COMPLEX * double
    cout << "Result of ";
    print(c1);
    cout << " * "
         << "(" << num << ")"
         << " = ";
    print(cresult);
    cout << endl;

    cresult = num * c1; // multiply operator double * COMPLEX
    cout << "Result of "
         << "(" << num << ")"
         << " * ";
    print(c1);
    cout << " = ";
    print(cresult);
    cout << endl;
    cout << "\n\n";

    cout << "===========Operator Division==========" << endl;
    cresult = c1 / c2; // divide operator CPMLEX / COMPLEX
    cout << "Result of ";
    print(c1);
    cout << " / ";
    print(c2);
    cout << " = ";
    print(cresult);
    cout << endl;

    cresult = c1 / num; // divide operator COMPLEX / double
    cout << "Result of ";
    print(c1);
    cout << " / "
         << "(" << num << ") = ";
    print(cresult);
    cout << endl;

    cresult = num / c2; // divide operator double / COMPLEX
    cout << "Result of "
         << "(" << num << ")";
    cout << " / ";
    print(c2);
    cout << " = ";
    print(cresult);
    cout << endl;

    return 0;
}
