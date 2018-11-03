#ifndef COMPLEX_H
#define COMPLEX_H

struct COMPLEX
{
    double Re;
    double Im;

    // function prototypes for "+" operator overloads
    COMPLEX operator+(const COMPLEX &b) const;
    COMPLEX operator+(const double &b) const;
    friend COMPLEX operator+(const double &x, const COMPLEX &b);

    // function prototypes for "-" operator overloads
    COMPLEX operator-(const COMPLEX &b) const;
    COMPLEX operator-(const double &b) const;
    friend COMPLEX operator-(const double &x, const COMPLEX &b);

    // function prototypes for "/" operator overloads
    COMPLEX operator/(const COMPLEX &b) const;
    COMPLEX operator/(const double &b) const;
    friend COMPLEX operator/(const double &x, const COMPLEX &b);

    // function prototypes for "*" operator overloads
    COMPLEX operator*(const COMPLEX &b) const;
    COMPLEX operator*(const double &b) const;
    friend COMPLEX operator*(const double &x, const COMPLEX &b);
};

// print function prototype
void print(COMPLEX c);
#endif