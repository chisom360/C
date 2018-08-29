/*     FILE: enum.cpp     */

/* Enumerated types give symbolic constants with type
   checking.                                          */

#include <iostream>
using namespace std;

enum GPA{F,D,C,B,A};

int main( )
{
  enum GPA grade;
  
  grade = A;
  
  cout << "Score for an A: " << grade << endl;
  
  return 0;
}


/*    OUTPUT: enum.cpp

	Score for an A: 4

*/
