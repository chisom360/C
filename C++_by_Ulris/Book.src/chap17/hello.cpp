// hello.cpp
// Demonstrates the command line arguments.
// Call:  hello name1 name2 
// ----------------------------------------------------

#include <iostream>
using namespace std;

int main( int argc, char *argv[])
{
   if( argc != 3 )
   {
       cerr << "Use: hello name1 name2" << endl;
       return 1;
   }

   cout << "Hello " << argv[1] << '!' << endl;
   cout << "Best wishes \n"
        << "\tyours " << argv[2] << endl;
   
   return 0;
}
