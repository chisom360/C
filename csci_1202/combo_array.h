/*     FILE: combo_array.h     */

#ifndef _combo_array_h
#define _combo_array_h
#include "index_array.h"
#include "arith_array.h"

class combo_array: public index_array, public arithmetic_array{
public:
   combo_array(int length);
   combo_array(int lower, int upper);
   ~combo_array( ){}
   int &operator[ ](int index);
   combo_array & operator=(const arithmetic_array & operand2);
};
#endif

