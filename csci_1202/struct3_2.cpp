/*     FILE: struct3_2.cpp     */

/* Pointers to structures */

#include <iostream>
using namespace std;

struct part{
  char name[128];
  long no;
  double price;
};

void print_part(part *p);

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
  print_part(&item);
  
  return 0;
}

void print_part(part *p)       /* a structure pointer parameter */
{
  cout << "Product: " << *p.name << endl;
  cout << "Part No.: " << *p.no << endl;
  cout << "Unit price: " << *p.price << endl;

  return;
}


/*    OUTPUT: struct3_2.cpp

	struct3_2.cpp: In function `void print_part(part*)':
	struct3_2.cpp:34: request for member `name' in `p', which is of non-aggregate 
	   type `part*'
	struct3_2.cpp:35: request for member `no' in `p', which is of non-aggregate 
	   type `part*'
	struct3_2.cpp:36: request for member `price' in `p', which is of non-aggregate 
	   type `part*'

*/
