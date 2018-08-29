/*     FILE: combo_ar.h     */

#ifndef _combo_ar_h
#define _combo_ar_h
#include "index_ar.h"
#include "arith_ar.h"

class combo_array: public index_array, public arithmetic_array{
public:
   combo_array(int length);
   combo_array(int lower, int upper);
   ~combo_array( ){}
   int &operator[ ](int index);
   combo_array & operator=(const arithmetic_array & operand2);
};
#endif

