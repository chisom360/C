/*     FILE: struct.cpp     */

/* Structures just like C. */

#include <iostream>
using namespace std;

struct part{
  char name[128];
  long no;
  double price;
};

int main( )
{
  part item;    /* A part structure */

                                      /* Load the structure. */
  cout << "Enter part name: " << flush;
  cin >> item.name;
  cout << "Enter part number: " << flush;
  cin >> item.no;
  cout << "Enter part price: " << flush;
  cin >> item.price;
                                      /* Print the structure. */
  cout << endl;
  cout << "Product: " << item.name << endl;
  cout << "Part No.: " << item.no << endl;
  cout << "Unit price: " << item.price << endl;
  
  return 0;
}


/*    OUTPUT: struct.cpp

	Enter part name: Board
	Enter part number: 1
	Enter part price: 1.11
	
	Product: Board
	Part No.: 1
	Unit price: 1.11

*/
