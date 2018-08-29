/*     FILE: struct6.cpp     */

/* Dynamically allocated array of structures.  */

#include <iostream>
using namespace std;

struct part{
  char name[128];
  long no;
  double price;
};

int main( )
{
  int size;
  part *inventory;    /* Array to hold SIZE "part"s */

  cout << "Enter number of parts: " << flush;
  cin >> size;
  
  inventory = new part[size]; 

  for(int i=0; i < size; i++){        /* Load the array of structures. */
    cout << "Part " << i << " at: " << inventory + i << endl;
  }

  delete[ ] inventory;
}


/*    OUTPUT: struct6.cpp

	Enter number of parts: 3
	Part 0 at: 0x3f2678
	Part 1 at: 0x3f2708
	Part 2 at: 0x3f2798

*/
