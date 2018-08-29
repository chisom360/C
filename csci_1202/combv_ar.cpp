/*     FILE: combv_ar.cpp     */

#include "combv_ar.h"

combo_array::combo_array(int length):index_array(length),
                                     safe_array(length),
                                     arithmetic_array(length)
{}

combo_array::combo_array(int lower, int upper):index_array(lower,upper),
                                     safe_array(upper-lower+1),
                                     arithmetic_array(upper-lower+1)
{}

int & combo_array::operator[ ](int index)
{
   return index_array::operator[ ](index);
}

combo_array & combo_array::operator=(const arithmetic_array & operand2)
{
   if(this != &operand2){
     ((index_array&)*this) = safe_array(operand2);
   }
   return *this;
}


