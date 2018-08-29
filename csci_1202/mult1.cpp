/*     FILE: mult1.cpp     */

#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

#include "safe_array.h"

class index_array: public safe_array{
   int lower;
public:
   index_array(int length);
   index_array(int lower, int upper);
   index_array(const index_array & param);
   index_array(const safe_array & param);
   ~index_array( ){}
   int &operator[ ](int index);
   const int &operator[ ](int index)const;
   index_array & operator=(const index_array & operand2);

   int getMinIndex( ) const;
   int getMaxIndex( ) const;
};

index_array::index_array(int length):safe_array(length)
{
   lower = 0;
}

index_array::index_array(int lower, int upper):safe_array(upper-lower+1)
{
   index_array::lower = lower;
}

index_array::index_array(const index_array & param):safe_array(param)
{
   lower = param.lower;
}

index_array::index_array(const safe_array & param):safe_array(param)
{
   lower = 0;
}

index_array & index_array::operator=(const index_array & operand2)
{
   if(this != &operand2){
     ((safe_array&)*this) = operand2;
     lower = operand2.lower;
   }
   return *this;
}

int & index_array::operator[ ](int index)
{
   if (index < lower || getSize( )+lower-1 < index)
     abort( );
   return safe_array::operator[ ](index-lower);
}

const int & index_array::operator[ ](int index) const
{
   if (index < lower || getSize( )+lower-1 < index)
     abort( );
   return safe_array::operator[ ](index-lower);
}

int index_array::getMaxIndex( ) const
{
   return (lower + getSize( ));
}

int index_array::getMinIndex( ) const
{
   return lower;
}

int main( )
{
  index_array ar(5);
  index_array ar2(-3,7);

  for(int i=ar.getMinIndex( ); i<ar.getMaxIndex( ); i++)
     ar[i] = i;

  for(int i=ar2.getMinIndex( ); i<ar2.getMaxIndex( ); i++)
     ar2[i] = i*10;

  for(int i=ar.getMinIndex( ); i<ar.getMaxIndex( ); i++)   // display array ar
     cout << "ar[" << i << "] = " << ar[i] << endl;

  cout << endl;
  for(int i=ar2.getMinIndex( ); i<ar2.getMaxIndex( ); i++)   // display array ar2
     cout << "ar2[" << i << "] = " << ar2[i] << endl;

  ar = ar2;

  cout << endl;
  for(int i=ar.getMinIndex( ); i<ar.getMaxIndex( ); i++)   // display array ar
     cout << "ar[" << i << "] = " << ar[i] << endl;      // ...after assignment

  return 0;
}



/*    OUTPUT: mult1.cpp

	ar[0] = 0
	ar[1] = 1
	ar[2] = 2
	ar[3] = 3
	ar[4] = 4
	
	ar2[-3] = -30
	ar2[-2] = -20
	ar2[-1] = -10
	ar2[0] = 0
	ar2[1] = 10
	ar2[2] = 20
	ar2[3] = 30
	ar2[4] = 40
	ar2[5] = 50
	ar2[6] = 60
	ar2[7] = 70
	
	ar[-3] = -30
	ar[-2] = -20
	ar[-1] = -10
	ar[0] = 0
	ar[1] = 10
	ar[2] = 20
	ar[3] = 30
	ar[4] = 40
	ar[5] = 50
	ar[6] = 60
	ar[7] = 70

*/
