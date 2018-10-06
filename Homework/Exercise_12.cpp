#include <iostream>
using namespace std;

struct COMPLEX
{
  double Re;
  double Im;
  COMPLEX operator+(const COMPLEX &b) const;
  friend COMPLEX operator+(const COMPLEX &a, const double &b);
  friend COMPLEX operator+(const double &x, const COMPLEX &b);

  friend COMPLEX operator-(const COMPLEX &a, const COMPLEX &b);
  friend COMPLEX operator-(const COMPLEX &a, const double &b);
  friend COMPLEX operator-(const double &x, const COMPLEX &b);
};

//Print function prototype
void print(COMPLEX c);

int main()
{
  COMPLEX c1, c2, cresult;

  c1.Re = 8;
  c1.Im = 1;

  c2.Re = 2;
  c2.Im = 3;

  cout << "===========Operator addition==========" << endl;
  cresult = c1 + c2;
  cout << "Result of ";
  print(c1);
  cout << " + ";
  print(c2);
  cout << " = ";
  print(cresult);
  cout << endl;

  cresult = c1 + 5.5;
  cout << "Result of ";
  print(c1);
  cout << " + "
       << "(" << 5.5 << ")"
       << " = ";
  print(cresult);
  cout << endl;

  cresult = 3.3 + c1;
  cout << "Result of "
       << "(" << 3.3 << ")"
       << " + ";
  print(c1);
  cout << " = ";
  print(cresult);
  cout << endl;
  cout << "\n\n";

  cout << "=======Operator Subtraction==========" << endl;

  //subtraction printout for COMPLEX SUB(COMPLEX a, COMPLEX b)
  cresult = c1 - c2;
  cout << "Result of ";
  print(c1);
  cout << " - ";
  print(c2);
  cout << " = ";
  print(cresult);
  cout << endl;

  //subtraction printout for COMPLEX SUB(COMPLEX a, double b)
  cresult = c1 - 5.5;
  cout << "Result of ";
  print(c1);
  cout << " - "
       << "(" << 5.5 << ")"
       << " = ";
  print(cresult);
  cout << endl;

  //subtraction printout for COMPLEX SUB(double a, COMPLEX b)
  cresult = 3.3 - c1;
  cout << "Result of "
       << "(" << 3.3 << ")"
       << " - ";
  print(c1);
  cout << " = ";
  print(cresult);
  cout << endl;
  cout << "\n\n";

  return 0;
}

void print(COMPLEX c)
{
  cout << "(" << c.Re << " + " << c.Im << "i)";
}

COMPLEX COMPLEX::operator+(const COMPLEX &b) const
{
  COMPLEX result;
  result.Re = Re + b.Re;
  result.Im = Im + b.Im;
  return result;
}
COMPLEX operator+(const COMPLEX &a, const double &b)
{
  COMPLEX result;
  result.Re = a.Re + b;
  result.Im = a.Im;
  return result;
}

COMPLEX operator+(const double &x, const COMPLEX &b)
{
  COMPLEX result;
  result.Re = b.Re + x;
  result.Im = b.Im;
  return result;
}

COMPLEX operator-(const COMPLEX &a, const COMPLEX &b)
{
  COMPLEX result;
  result.Re = a.Re - b.Re;
  result.Im = a.Im - b.Im;
  return result;
}

COMPLEX operator-(const COMPLEX &a, const double &b)
{
  COMPLEX result;
  result.Re = a.Re - b;
  result.Im = a.Im;
  return result;
}
COMPLEX operator-(const double &x, const COMPLEX &b)
{
  COMPLEX result;
  result.Re = x - b.Re;
  result.Im = b.Im;
  return result;
}
