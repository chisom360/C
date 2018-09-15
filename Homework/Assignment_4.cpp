#include <iostream>
using namespace std;

struct COMPLEX
{
  double Re;
  double Im;
};

// Addition function prototypes
COMPLEX Add(COMPLEX a, COMPLEX b);
COMPLEX Add(COMPLEX a, double b);
COMPLEX Add(double a, COMPLEX b);

//Subtraction function prototypes
COMPLEX SUB(COMPLEX a, COMPLEX b);
COMPLEX SUB(COMPLEX a, double b);
COMPLEX SUB(double a, COMPLEX b);

//Multiplication function prototypes
COMPLEX Mult(COMPLEX a, COMPLEX b);
COMPLEX Mult(COMPLEX a, double b);
COMPLEX Mult(double a, COMPLEX b);

//Division function prototype
COMPLEX DIV(COMPLEX a, COMPLEX b);
COMPLEX DIV(COMPLEX a, double b);
COMPLEX DIV(double a, COMPLEX b);

//Print function prototype
void print(COMPLEX c);

int main()
{
  COMPLEX c1, c2, cresult;
  double num = 0;

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
  cout << "Enter a constant double number:";
  cin >> num;
  while (cin.fail())
  {
    cout << "\nIncorrect value entered for constant double. Try again" << endl;
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Enter a constant double number:";
    cin >> num;
  }

  cresult = Add(c1, c2);
  cout << "================Addition===============" << endl;
  cout << "Result of ";
  print(c1);
  cout << " + ";
  print(c2);
  cout << " = ";
  print(cresult);
  cout << endl;

  cresult = Add(c1, num);
  cout << "Result of ";
  print(c1);
  cout << " + "
       << "(" << num << ")"
       << " = ";
  print(cresult);
  cout << endl;

  cresult = Add(num, c2);
  cout << "Result of "
       << "(" << num << ")"
       << " + ";
  print(c2);
  cout << " = ";
  print(cresult);
  cout << endl;
  cout << "\n\n";

  //subtraction printout for COMPLEX SUB(COMPLEX a, COMPLEX b)
  cout << "=============Subtraction==============" << endl;
  cresult = SUB(c1, c2);
  cout << "Result of ";
  print(c1);
  cout << " - ";
  print(c2);
  cout << " = ";
  print(cresult);
  cout << endl;

  //subtraction printout for COMPLEX SUB(COMPLEX a, double b)
  cresult = SUB(c1, num);
  cout << "Result of ";
  print(c1);
  cout << " - "
       << "(" << num << ")"
       << " = ";
  print(cresult);
  cout << endl;

  //subtraction printout for COMPLEX SUB(double a, COMPLEX b)
  cresult = SUB(num, c2);
  cout << "Result of "
       << "(" << num << ")"
       << " - ";
  print(c2);
  cout << " = ";
  print(cresult);
  cout << endl;
  cout << "\n\n";

  //Multiplication printout for Mult(COMPLEX a, COMPLEX b)
  cout << "=============Multiplication==============" << endl;
  cresult = Mult(c1, c2);
  cout << "Result of ";
  print(c1);
  cout << " * ";
  print(c2);
  cout << " = ";
  print(cresult);
  cout << endl;

  //Multiplication printout for Mult(COMPLEX a, COMPLEX b)
  cresult = Mult(c1, num);
  cout << "Result of ";
  print(c1);
  cout << " * ";
  cout << "(" << num << ")"
       << " = ";
  print(cresult);
  cout << endl;

  //Multiplication printout for COMPLEX Mult(double a, COMPLEX b)
  cresult = Mult(num, c2);
  cout << "Result of "
       << "(" << num << ")"
       << " * ";
  print(c2);
  cout << " = ";
  print(cresult);
  cout << endl;
  cout << "\n\n";

  //Division printout for DIV(COMPLEX a, COMPLEX b)
  cout << "=================Division=================" << endl;
  cresult = DIV(c1, c2);
  cout << "Result of ";
  print(c1);
  cout << "/";
  print(c2);
  cout << " = ";
  print(cresult);
  cout << endl;

  //Division printout for DIV(double a, COMPLEX b)
  cresult = DIV(num, c2);
  cout << "Result of "
       << "(" << num << ")";
  cout << "/";
  print(c2);
  cout << " = ";
  print(cresult);
  cout << endl;

  //Division printout for DIV(COMPLEX a, double b)
  cresult = DIV(c1, num);
  cout << "Result of ";
  print(c1);
  cout << " / ";
  cout << "(" << num << ")"
       << " = ";
  print(cresult);
  cout << endl;

  return 0;
}

COMPLEX Add(COMPLEX a, COMPLEX b)
{
  COMPLEX result;
  result.Re = a.Re + b.Re;
  result.Im = a.Im + b.Im;

  return result;
}

COMPLEX Add(COMPLEX a, double b)
{
  COMPLEX result;
  result.Re = a.Re + b;
  result.Im = a.Im;
  return result;
}

COMPLEX Add(double a, COMPLEX b)
{
  return Add(b, a);
}

void print(COMPLEX c)
{

  cout << "(" << c.Re;
  if (c.Im < 0)
  {
    cout << " - " << -1 * c.Im << "i)";
  }
  else
    cout << " + " << c.Im << "i)";
}

COMPLEX SUB(COMPLEX a, COMPLEX b)
{
  COMPLEX result;
  result.Re = a.Re - b.Re;
  result.Im = a.Im - b.Im;
  return result;
}

COMPLEX SUB(COMPLEX a, double b)
{
  COMPLEX result;
  result.Re = a.Re - b;
  result.Im = a.Im;
  return result;
}

COMPLEX SUB(double a, COMPLEX b)
{
  COMPLEX result;
  result.Re = a - b.Re;
  result.Im = b.Im;
  return result;
  // return SUB(b,a);
}

COMPLEX Mult(COMPLEX a, COMPLEX b)
{
  COMPLEX result;
  result.Re = a.Re * b.Re - a.Im * b.Im;
  result.Im = a.Re * b.Im + a.Im * b.Re;
  return result;
}

COMPLEX Mult(COMPLEX a, double b)
{
  COMPLEX result;
  result.Re = a.Re * b;
  result.Im = a.Im * b;
  return result;
}

COMPLEX Mult(double a, COMPLEX b)
{
  COMPLEX result;
  result.Re = b.Re * a;
  result.Im = b.Im * a;
  return result;
}

COMPLEX DIV(COMPLEX a, COMPLEX b)
{
  COMPLEX result;
  double DeNominator;
  result.Re = (a.Re * b.Re) + (a.Im * b.Im);
  result.Im = (a.Im * b.Re) - (a.Re * b.Im);
  DeNominator = (b.Re * b.Re) + (b.Im * b.Im);
  result.Re = result.Re / DeNominator;
  result.Im = result.Im / DeNominator;
  return result;
}

COMPLEX DIV(double a, COMPLEX b)
{
  COMPLEX result;
  double DeNominator;
  result.Re = (a * b.Re);
  result.Im = -(a * b.Im);
  DeNominator = (b.Re * b.Re) + (b.Im * b.Im);
  result.Re = result.Re / DeNominator;
  result.Im = result.Im / DeNominator;
  return result;
}

COMPLEX DIV(COMPLEX a, double b)
{
  COMPLEX result;
  double DeNominator;
  result.Re = a.Re;
  result.Im = a.Im;
  DeNominator = b;
  result.Re = result.Re / DeNominator;
  result.Im = result.Im / DeNominator;
  return result;
}

/*     output: Assignment_4.cpp
Enter the real and Imag part of first complex number:  3 5
Enter the real and Imag part of second complex number:  4 9
Enter a constant double number: 9
================Addition===============
Result of (3 + 5i) + (4 + 9i) = (7 + 14i)
Result of (3 + 5i) + (9) = (12 + 5i)
Result of (9) + (4 + 9i) = (13 + 9i)


=============Subtraction==============
Result of (3 + 5i) - (4 + 9i) = (-1 - 4i)
Result of (3 + 5i) - (9) = (-6 + 5i)
Result of (9) - (4 + 9i) = (5 + 9i)


=============Multiplication==============
Result of (3 + 5i) * (4 + 9i) = (-33 + 47i)
Result of (3 + 5i) * (9) = (27 + 45i)
Result of (9) * (4 + 9i) = (36 + 81i)


=================Division=================
Result of (3 + 5i)/(4 + 9i) = (0.587629 - 0.0721649i)
Result of (9)/(4 + 9i) = (0.371134 - 0.835052i)
Result of (3 + 5i) / (9) = (0.333333 + 0.555556i)

*/