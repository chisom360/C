// tresor_t.cpp: Testing the classes Safe and Castle
// ------------------------------------------------------
#include "safe.h"

int main()
{
   Castle cash_box;

   cash_box.display();

//   cash_box.topSecret = 1;    // Error: private
//   cash_box.secret = 2;       // Error: protected
//   cash_box.setTopSecret(5);  // Error: protected

   cash_box.noSecret = 10;      // ok
   cash_box.display();

   cash_box.test();
   cash_box.display();

   return 0;
}
