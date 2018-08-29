/*     FILE: File7.cpp     */

// Writing and using our own manipulators

// Toggle all-signed on/off
#include <iostream>
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::ios;
using std::ostream;
using std::istream;
using std::cout;
using std::cin;
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
  friend istream& operator>>(istream&, COMPLEX &);
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

ostream & signon(ostream & os)
{
   os.setf(ios::showpos);
   return os;
}

ostream & signoff(ostream & os)
{
   os.unsetf(ios::showpos);
   return os;
}

ostream & operator<<(ostream & os, const COMPLEX & c)
{
   os << c.Re << signon << c.Im << signoff << "i";

   return os;
}

istream & operator>>(istream & is, COMPLEX & c)
{
   char ch;

   is >> c.Re;
   is >> c.Im;
   is >> ch;

   return is;
}

int main( )
{
  ofstream outs;
  ifstream ins;
  COMPLEX c1(3.4,5.2), c2(-1.7,-3.2);
  COMPLEX c3, c4;

  outs.open("File7.out");

  outs << c1 << endl;
  outs << c2 << endl;
  
  outs.close( );
  
  ins.open("File7.out");

  ins >> c3;
  ins >> c4;
  
  ins.close( );
  
  cout << "Read in complex: " << c3 << endl;
  cout << "Read in complex: " << c4 << endl;
  
}


/*    OUTPUT: File7.cpp

	Read in complex: 3.4+5.2i
	Read in complex: -1.7-3.2i

*/


/*   OUTPUT: File7.OUT

	3.4+5.2i
	-1.7-3.2i

*/