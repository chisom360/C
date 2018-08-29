/*     FILE: struct7.cpp     */

/* Structures can haul around access to functionality. */

#include <iostream>
using namespace std;

struct part{
  char name[128];
  long no;
  double price;
  void (*print)(part *);
};

void print_part(part* p);

int main( )
{
  part board;

  board.print = print_part;

  cout << "Enter part name: " << flush;
  cin.getline(board.name,128);
  cout << "Enter part number: " << flush;
  cin >> board.no;
  cout << "Enter part price: " << flush;
  cin >> board.price;

  board.print(&board);
}

void print_part(part* p)
{
  cout << "Product: " << p->name << endl;
  cout << "Part No.: " << p->no << endl;
  cout << "Unit price: " << p->price << endl;

  return;
}


/*    OUTPUT: struct7.cpp

	Enter part name: I/O Card
	Enter part number: 2
	Enter part price: 2.22
	Product: I/O Card
	Part No.: 2
	Unit price: 2.22

*/
