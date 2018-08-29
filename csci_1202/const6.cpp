/*     FILE: const6.cpp     */

/*
   Access to the invoking object by default allows manipulation
   of the object.
   
   To prevent inadvertant manipulation of the object pointed to 
   by "this" the const keyword is placed at the end of method 
   definition header line. 
*/

#include <iostream>
using namespace std;

class COMPLEX{
  double Re;
  double Im;
public:
  COMPLEX Mult(const COMPLEX & b);
  void print( ) const;
  
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

void COMPLEX::print( ) const
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

  return 0;
}


/*    OUTPUT: const6.cpp

	const6.cpp: In method `void COMPLEX::print() const':
	const6.cpp:37: assignment of member `COMPLEX::Re' in read-only structure
	const6.cpp:38: assignment of member `COMPLEX::Im' in read-only structure

*/
