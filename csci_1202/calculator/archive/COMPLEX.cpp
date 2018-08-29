#include "COMPLEX.h"

COMPLEX::COMPLEX(double r, double im)
{
  Re = r;
  Im = im;
}

COMPLEX COMPLEX::operator*(const COMPLEX & b) const
{
  COMPLEX result;

  result.Re = Re*b.Re - Im*b.Im;
  result.Im = Re*b.Im + Im*b.Re;

  return result;
}

COMPLEX COMPLEX::operator-(const COMPLEX &b) const
{
  COMPLEX result;
 
  result.Re = Re - b.Re;
  result.Im = Im - b.Im;
 
  return result;
}
 
float COMPLEX::getReal() const
{
  return Re;
}

float COMPLEX::getImag() const
{
  return Im;
}

