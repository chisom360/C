/*     FILE: FileBin5.cpp     */

// Reading and writing a COMPLEX as binary data

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
  static istream& read(istream&, COMPLEX &);
  static ostream& write(ostream&,const COMPLEX &);
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

ostream & COMPLEX::write(ostream & os, const COMPLEX & c)
{
   os.write((char *)&c.Re, sizeof(c.Re));
   os.write((char *)&c.Im, sizeof(c.Im));
   
   return os;
}

istream & COMPLEX::read(istream & is, COMPLEX & c)
{

   is.read((char *)&c.Re, sizeof(c.Re));
   is.read((char *)&c.Im, sizeof(c.Im));

   return is;
}

int main( )
{
  COMPLEX c1(3.4,5.2), c2(-1.7,-3.2);
  COMPLEX c3, c4;

  ofstream outs("FileBin5.tmp", ios::binary);

  COMPLEX::write(outs,c1);
  COMPLEX::write(outs,c2);
  
  outs.close( );
  
  ifstream ins("FileBin5.tmp", ios::binary);

  COMPLEX::read(ins,c3);
  COMPLEX::read(ins,c4);
  
  ins.close( );
  
  cout << "Read in complex: " << c3 << endl;
  cout << "Read in complex: " << c4 << endl;
  
}


/*    OUTPUT: FileBin5.cpp

	Read in complex: 3.4+5.2i
	Read in complex: -1.7-3.2i

*/
