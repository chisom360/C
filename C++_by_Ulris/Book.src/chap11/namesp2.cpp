// namesp2.cpp
// Demonstrates the use of using-declarations and
// using-directives.
// ----------------------------------------------------
#include <iostream>      // Namespace std  

void message()           // Global function ::message()
{
   std::cout << "Within function ::message()\n";
}

namespace A
{
   using namespace std;  // Names of std visible here.
   void message()        // Function A::message()
   {
     cout << "Within function A::message()\n";
   }
}

namespace B
{
   using std::cout;      // Declaring cout of std.
   void message(void);   // Function B::message()
}

void B::message(void)    // Defining B::message()
{
   cout << "Within function B::message()\n";
}

int main()
{
   using namespace std;  // Names of namespace std 
   using B::message;     // Function name without braces!

   cout << "Testing namespaces!\n"; 

   cout << "\nCall of A::message()" << endl; 
   A::message();          

   cout << "\nCall of B::message()" << endl; 
   
   message();           // ::message() is hidden because
                        // of using-declaration.

   cout << "\nCall of von ::message()" << endl; 
   ::message();              // Global function

   return 0;
}

