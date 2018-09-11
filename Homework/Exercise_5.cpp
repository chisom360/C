#include <iostream>
using namespace std;

struct COMPLEX
{
  double Re;
  double Im;
};

COMPLEX Add(COMPLEX a, COMPLEX b);
COMPLEX Add(COMPLEX a, double b);
COMPLEX Add(double a, COMPLEX b);
COMPLEX SUB(COMPLEX a, COMPLEX b);
COMPLEX SUB(COMPLEX a, double b);
COMPLEX SUB(double a, COMPLEX b);
void print(COMPLEX c);

int main()
{
  COMPLEX c1, c2, cresult;

  c1.Re = 2;
  c1.Im = 3;

  c2.Re = 2;
  c2.Im = 3;

  cresult = Add(c1, c2);
  cout << "================Addition===============" << endl;
  cout << "Result of ";
  print(c1);
  cout << " + ";
  print(c2);
  cout << " = ";
  print(cresult);
  cout << endl;

  cresult = Add(c1, 5.5);

  cout << "Result of ";
  print(c1);
  cout << " + "
       << "(" << 5.5 << ")"
       << " = ";
  print(cresult);
  cout << endl;

  cresult = Add(3.3, c2);

  cout << "Result of "
       << "(" << 3.3 << ")"
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
  cresult = SUB(c1, 5.5);
  cout << "Result of ";
  print(c1);
  cout << " - "
       << "(" << 5.5 << ")"
       << " = ";
  print(cresult);
  cout << endl;

  //subtraction printout for COMPLEX SUB(double a, COMPLEX b)
  cresult = SUB(3.3, c2);
  cout << "Result of "
       << "(" << 3.3 << ")"
       << " - ";
  print(c2);
  cout << " = ";
  print(cresult);
  cout << endl;
  cout << "\n\n";

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
  cout << "(" << c.Re << " + " << c.Im << "i)";
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
/*    OUTPUT: Exercise_5.cpp
	  ================Addition===============
Result of (2 + 3i) + (2 + 3i) = (4 + 6i)
Result of (2 + 3i) + (5.5) = (7.5 + 3i)
Result of (3.3) + (2 + 3i) = (5.3 + 3i)


=============Subtraction==============
Result of (2 + 3i) - (2 + 3i) = (0 + 0i)
Result of (2 + 3i) - (5.5) = (-3.5 + 3i)
Result of (3.3) - (2 + 3i) = (1.3 + 3i)
*/