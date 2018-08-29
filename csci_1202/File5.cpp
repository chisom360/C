/*     FILE: File5.cpp     */

#include <iostream>
#include <fstream>

using std::ofstream;
using std::ios;
using std::ostream;
using std::cout;
using std::endl;

class COMPLEX{
  float Re;
  float Im;
public:
  COMPLEX(float r, float im);
  COMPLEX( ){Re = 0; Im = 0;}
  COMPLEX operator*(const COMPLEX &b) const;
  COMPLEX operator+(const COMPLEX &b) const;
  int operator<(const COMPLEX &b) const;
  friend ostream& operator<<(ostream&,const COMPLEX &);
};

int COMPLEX::operator<(const COMPLEX &b) const
{
  float mag1, mag2;

  mag1 = Re*Re + Im*Im;
  mag2 = b.Re*b.Re + b.Im*b.Im;

  return mag1<mag2;
}

COMPLEX COMPLEX::operator+(const COMPLEX &b) const
{
  COMPLEX result;

  result.Re = Re + b.Re;
  result.Im = Im + b.Im;

  return result;
}

COMPLEX COMPLEX::operator*(const COMPLEX &b) const
{
  COMPLEX result;

  result.Re = Re*b.Re - Im*b.Im;
  result.Im = Re*b.Im + Im*b.Re;

  return result;
}

COMPLEX::COMPLEX(float r, float im)
{
  Re = r;
  Im = im;
}

ostream & sign(ostream & os)
{
   os.setf(ios::showpos);
   return os;
}

ostream & operator<<(ostream & os, const COMPLEX & c)
{
   os << c.Re << sign << c.Im << "i";

   return os;
}

int main( )
{
  ofstream outs;
  COMPLEX c1(3.4,5.2), c2(-1.7,-3.2);

  outs.open("File5.out");

  outs << "COMPLEX c1 = " << c1 << endl;
  outs << "COMPLEX c2 = " << c2 << endl;
  outs << c1 << " + " << c2 << " = " << c1 + c2 << endl;

  outs.close( );
}


/*   OUTPUT: File5.OUT

	COMPLEX c1 = 3.4+5.2i
	COMPLEX c2 = -1.7-3.2i
	+3.4+5.2i + -1.7-3.2i = +1.7+2i

*/