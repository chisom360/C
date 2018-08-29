/*     FILE: combov_array.h     */

#ifndef _combov_array_h
#define _combov_array_h
#include "indexv_array.h"
#include "arithv_array.h"

class combo_array: public index_array, public arithmetic_array{
public:
   combo_array(int length);
   combo_array(int lower, int upper);
   ~combo_array( ){}
   int &operator[ ](int index);
   combo_array & operator=(const arithmetic_array & operand2);
};
#endif

