#include "SpreadsheetCell.h"
#include <iostream>
using namespace std;

int main()
{
	SpreadsheetCell myCell, anotherCell;
	myCell.setValue(3);
	anotherCell.setString("1");

	cout << "cell 1: " << myCell.getValue() << endl;
	cout << "cell 2: " << anotherCell.getValue() << endl;

	return 0;
}
