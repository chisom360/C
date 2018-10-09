// -------------------------------------------------------
// reverse.cpp
// Exercising arithmetic with pointers: To input
// a line and output in reverse order.
// -------------------------------------------------------
#include <iostream>
using namespace std;

#define MAXLEN 80

int main()
{
   char line[MAXLEN], *p;
    
   cout << "Enter a line of text: " << endl;
 
   // To input a line:
   for( p = line;
        p < line+MAXLEN  &&  cin.get(*p)  &&  *p != '\n';
        ++p )
     ;
 
   // Output the line in reverse order:
   while( --p >= line)
       cout << *p;

   cout << endl;

   return 0;
}
