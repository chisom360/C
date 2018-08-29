/*     FILE: safe_ar.h     */

#ifndef _safe_ar_h
#define _safe_ar_h

class safe_array{
   int * ptr;
   int size;
public:
   safe_array(int length);
   safe_array(const safe_array & param);
   ~safe_array( ){ delete [ ] ptr;}
   int &operator[ ](int index);
   const int &operator[ ](int index)const;
   safe_array &operator=(const safe_array & operand2);
   
   int getSize( ) const{ return size;}
};
#endif
