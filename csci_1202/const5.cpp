/*     FILE: const5.cpp     */

/*
   Access to the invoking object allows manipulation of the object,
   by default.
*/

#include <iostream>
using namespace std;

class COMPLEX{
  double Re;
  double Im;
public:
  COMPLEX Mult(const COMPLEX & b);
  void print( );
  
  COMPLEX(double r, double im);
  COMPLEX( ){}
};

COMPLEX COMPLEX::Mult(const COMPLEX & b)
{
  COMPLEX result(0,0);

  result.Re = Re*b.Re - Im*b.Im;
  result.Im = Re*b.Im + Im*b.Re;

  return result;
}

void COMPLEX::print( )
{
  cout << "(" << Re << " + " << Im << "i)" ;
  Re = 3.3;
  Im = 4.5;
}

COMPLEX::COMPLEX(double r, double im)
{
  Re = r;
  Im = im;
}

int main( )
{
  COMPLEX c1(2,3), c2(2,3), cresult;

  cresult = c1.Mult(c2);

  cout << "Result of ";
  c1.print( );
  cout << " * ";
  c2.print( );
  cout << " = ";
  cresult.print( );
  cout << endl;

  cout << "Result of ";
  c1.print( );
  cout << " * ";
  c2.print( );
  cout << " = ";
  cresult.print( );
  cout << endl;

  return 0;
}


/*    OUTPUT: const5.cpp

	Result of (2 + 3i) * (2 + 3i) = (-5 + 12i)
	Result of (3.3 + 4.5i) * (3.3 + 4.5i) = (3.3 + 4.5i)

*/
