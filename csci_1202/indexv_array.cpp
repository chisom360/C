/*     FILE: indexv_array.cpp     */

#include <cstdlib>
#include "indexv_array.h"

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

index_array & index_array::operator=(const safe_array & operand2)
{
   if(this != &operand2){
     ((safe_array&)*this) = operand2;
     lower = 0;
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
