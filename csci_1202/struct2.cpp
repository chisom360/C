/*     FILE: struct2.cpp     */

/* Structures as parameters */

#include <iostream>
using namespace std;

struct part{
  char name[128];
  long no;
  double price;
};

void print_part(part p);

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
  print_part(item);
  
  return 0;
}

void print_part(part p)
{
  cout << "Product: " << p.name << endl;
  cout << "Part No.: " << p.no << endl;
  cout << "Unit price: " << p.price << endl;

  return;
}


/*    OUTPUT: struct2.cpp

	Enter part name: Board
	Enter part number: 1
	Enter part price: 1.11
	
	Product: Board
	Part No.: 1
	Unit price: 1.11

*/
