/*     FILE: aritv_ar.h     */

#ifndef _aritv_ar_h
#define _aritv_ar_h
#include "safe_ar.h"


class arithmetic_array: virtual public safe_array{
 
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
    friend arithmetic_array operator*(double d,
                                      const arithmetic_array & operand2);
};
#endif

