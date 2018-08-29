/*     FILE: arith2.cpp     */

/*
    A new class of arrays, based on safe_array, that can
    perform arithmetic between arrays.
    
    Addition requires arrays of the same size.
*/
#include <iostream>

#include "safe_ar.h"
using namespace std;

class arithmetic_array: public safe_array{

public:
   arithmetic_array(int length):safe_array(length)
   {}
   arithmetic_array(const arithmetic_array & param):safe_array(param)
   {}
   ~arithmetic_array( ){}
   arithmetic_array operator+(const arithmetic_array & operand2)const;
   arithmetic_array operator-(const arithmetic_array & operand2)const;
   arithmetic_array operator-( )const;
   arithmetic_array operator*(double d)const;
};

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


int main( )
{
  arithmetic_array ar(5);
  arithmetic_array ar2(5);
  arithmetic_array ar3(7);

  for(int i=0; i<ar.getSize( ); i++)
    ar[i] = i;

  for(int i=0; i<ar2.getSize( ); i++)
    ar2[i] = i*10;

  for(int i=0; i<ar3.getSize( ); i++)
    ar3[i] = i*2;

  ar2 = ar + ar2;

  for(int i=0; i<ar2.getSize( ); i++)   // display array ar2
    cout << "ar2[" << i << "] = " << ar2[i] << endl;

  ar2 = ar + ar3;    // Illegal addition, size mismatch

  return 0;
}



/*    OUTPUT: arith2.cpp

	ar2[0] = 0
	ar2[1] = 11
	ar2[2] = 22
	ar2[3] = 33
	ar2[4] = 44
	
	abnormal program termination

*/
