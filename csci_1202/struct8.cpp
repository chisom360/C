/*     FILE: struct8.cpp     */

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
void print_part2(part* p);
void read_part(part* p);
void display(part* p);

int main( )
{
  part board, board2;

  board.print = print_part;
  board2.print = print_part2;

  read_part(&board);
  read_part(&board2);

  cout << "\n\nPart Display info:" << endl;
  display(&board);
  display(&board2);
}

void read_part(part* p)
{
  cout << "Enter part name: " << flush;
  cin.getline(p->name,128);
  cout << "Enter part number: " << flush;
  cin >> p->no;
  cout << "Enter part price: " << flush;
  cin >> p->price;
  cin.get( );
}

void print_part(part* p)
{
  cout << "Product: " << p->name << endl;
  cout << "Part No.: " << p->no << endl;
  cout << "Unit price: " << p->price << endl;

  return;
}

void print_part2(part* p)
{
  cout << "Product: " << p->name
       << ", " << p->no
       << ", " << p->price << endl;

  return;
}

void display(part* p)
{
  p->print(p);

  return;
}


/*    OUTPUT: struct8.cpp

	Enter part name: I/O Card
	Enter part number: 2
	Enter part price: 2.22
	Enter part name: Contoller Card
	Enter part number: 3
	Enter part price: 3.45
	
	
	Part Display info:
	Product: I/O Card
	Part No.: 2
	Unit price: 2.22
	Product: Contoller Card, 3, 3.45

*/
