/*     FILE: struct5.cpp     */

/* Dynamically allocated array of structures.  */

#include <iostream>
using namespace std;

struct part
{
  char name[128];
  long no;
  double price;
};

void print_part(part *p);

int main()
{
  int size;
  part *inventory; /* Array to hold SIZE "part"s */

  cout << "Enter number of parts: " << flush;
  cin >> size;

  // new is like malloc in C++
  inventory = new part[size];

  for (int i = 0; i < size; i++)
  { /* Load the array of structures. */
    cout << "Enter part name: " << flush;
    cin.get(); // Strip trailing newline
    cin.getline((inventory + i)->name, 128);
    cout << "Enter part number: " << flush;
    cin >> (inventory + i)->no;
    cout << "Enter part price: " << flush;
    cin >> (inventory + i)->price;
  }

  for (int i = 0; i < size; i++)
  { /* Display the array of structures. */
    print_part(inventory + i);
    cout << '\n';
  }

  // this is to de-alocate the program
  delete[] inventory;
}

void print_part(part *p)
{
  cout << "Product: " << p->name << endl;
  cout << "Part No.: " << p->no << endl;
  cout << "Unit price: " << p->price << endl;

  return;
}

/*    OUTPUT: struct5.cpp

	Enter number of parts: 3
	Enter part name: I/O Board
	Enter part number: 1
	Enter part price: 1.11
	Enter part name: I/O Card
	Enter part number: 2
	Enter part price: 2.22
	Enter part name: I/O Disk
	Enter part number: 3
	Enter part price: 3.33
	Product: I/O Board
	Part No.: 1
	Unit price: 1.11
	
	Product: I/O Card
	Part No.: 2
	Unit price: 2.22
	
	Product: I/O Disk
	Part No.: 3
	Unit price: 3.33
	

*/
