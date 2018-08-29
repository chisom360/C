/*     FILE: arith_ar.cpp     */

#include <cstdlib>
 
#include "arith_ar.h"
 
arithmetic_array arithmetic_array::operator+(
                        const arithmetic_array & operand2)const
{
  if(getSize( ) != operand2.getSize( ))
    abort( );
  arithmetic_array result(getSize( ));
  for(int i=0; i<result.getSize( ); i++)
    result[i] = (*this)[i] + operand2[i];
  return result;
}
 
arithmetic_array arithmetic_array::operator-(
                        const arithmetic_array & operand2)const
{
  if(getSize( ) != operand2.getSize( ))
    abort( );
  arithmetic_array result(getSize( ));
  for(int i=0; i<result.getSize( ); i++)
    result[i] = (*this)[i] - operand2[i];
  return result;
}
 
arithmetic_array arithmetic_array::operator*(double d)const
{
  arithmetic_array result(getSize( ));
  for(int i=0; i<result.getSize( ); i++)
    result[i] = int((*this)[i] * d);
  return result;
}
 
arithmetic_array operator*(double d,arithmetic_array ar)
{
  return ar*d;
}
