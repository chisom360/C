// -------------------------------------------------------
// args.cpp
// The program outputs the program name including the path,
// command line arguments and the environment. 
// -------------------------------------------------------

#include <iostream>
using namespace std;

int main( int argc, char *argv[], char *env[])
{
   cout << "Program: " << argv[0] << endl;
   
   cout << "\nCommand line arguments:" << endl;

   int i;
   for( i = 1; i < argc; ++i)             // Arguments
     cout << argv[i] << endl;

   cout << "Type <Return> to go on";
   cin.get();

   cout << "\nEnvironment strings:" << endl;
    
   for( i = 0; env[i] != NULL; ++i)       // Environment
     cout << env[i] << endl;
    
   return 0;
}
