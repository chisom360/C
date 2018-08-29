/*     FILE: index_ar.h     */

#ifndef _index_ar_h
#define _index_ar_h
#include "safe_ar.h"

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
   index_array & operator=(const safe_array & operand2);

   int getMinIndex( ) const;
   int getMaxIndex( ) const;
};
#endif

