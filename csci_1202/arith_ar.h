/*     FILE: arith_ar.h     */

#ifndef _arith_ar_h
#define _arith_ar_h
 
#include "safe_ar.h"
 
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

arithmetic_array operator*(double d,arithmetic_array ar);

#endif
