#include <iostream>
#include "Complex.h"
using namespace std;

ostream &signon(ostream &os)
{
    os.setf(ios::showpos);
    return os;
}

ostream &signoff(ostream &os)
{
    os.unsetf(ios::showpos);
    return os;
}

ostream &operator<<(ostream &os, const COMPLEX &c)
{
    os << c.Re << signon << c.Im << signoff << "i";

    return os;
}

// print function definition
void print(COMPLEX c)
{
    cout << "(" << c.Re;

    // checks to see if the imaginary part is a negative number
    if (c.Im < 0)
    {
        // if Im is -Ve, make it positive (-*1) then insert a -ve sign
        // this is just to make the output look better
        cout << " - " << -1 * c.Im << "i)";
    }
    else
        cout << " + " << c.Im << "i)";
}

// overload definition for case Complex + complex
COMPLEX COMPLEX::operator+(const COMPLEX &b) const
{
    COMPLEX result;
    result.Re = Re + b.Re;
    result.Im = Im + b.Im;
    return result;
}
//overload definition for case Complex + double
COMPLEX COMPLEX::operator+(const double &b) const
{
    COMPLEX result;
    result.Re = Re + b;
    result.Im = Im;
    return result;
}

// overload definitionfor case double + complex
COMPLEX operator+(const double &x, const COMPLEX &b)
{
    COMPLEX result;

    result.Re = b.Re + x;
    result.Im = b.Im;

    return result;
}

//overload definition for case Complex  complex
COMPLEX COMPLEX::operator-(const COMPLEX &b) const
{
    COMPLEX result;
    result.Re = Re - b.Re;
    result.Im = Im - b.Im;
    return result;
}

// overload definition for case Complex - double
COMPLEX COMPLEX::operator-(const double &b) const
{
    COMPLEX result;
    result.Re = Re - b;
    result.Im = Im;
    return result;
}
// overload definition for case double - complex
COMPLEX operator-(const double &x, const COMPLEX &b)
{
    COMPLEX result;
    result.Re = x - b.Re;
    result.Im = -b.Im;
    return result;
}

// overload definition for case Complex * complex
COMPLEX COMPLEX::operator*(const COMPLEX &b) const
{
    COMPLEX result;
    result.Re = Re * b.Re - Im * b.Im;
    result.Im = Re * b.Im + Im * b.Re;
    return result;
}
// overload definition for case Complex * double
COMPLEX COMPLEX::operator*(const double &x) const
{
    COMPLEX result;
    result.Re = Re * x;
    result.Im = Im * x;
    return result;
}
// overload definition for case double * complex
COMPLEX operator*(const double &x, const COMPLEX &c)
{
    COMPLEX result;
    result.Re = c.Re * x;
    result.Im = c.Im * x;
    return result;
}
// overload definition for case Complex / complex
COMPLEX COMPLEX::operator/(const COMPLEX &b) const
{
    COMPLEX result;
    double DeNominator;
    result.Re = (Re * b.Re) + (Im * b.Im);
    result.Im = (Im * b.Re) - (Re * b.Im);
    DeNominator = (b.Re * b.Re) + (b.Im * b.Im);
    result.Re = result.Re / DeNominator;
    result.Im = result.Im / DeNominator;
    return result;
}
// overload definition for case Complex / double
COMPLEX COMPLEX::operator/(const double &x) const
{
    COMPLEX result;
    double DeNominator;
    result.Re = Re;
    result.Im = Im;
    DeNominator = x;
    result.Re = result.Re / DeNominator;
    result.Im = result.Im / DeNominator;
    return result;
}
// overload definition for case double / complex
COMPLEX operator/(const double &x, const COMPLEX &b)
{
    COMPLEX result;
    double DeNominator;
    result.Re = (x * b.Re);
    result.Im = -(x * b.Im);
    DeNominator = (b.Re * b.Re) + (b.Im * b.Im);
    result.Re = result.Re / DeNominator;
    result.Im = result.Im / DeNominator;
    return result;
}
