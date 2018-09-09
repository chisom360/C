#include <iostream>
 
// Use reference parameters so we can modify the values of the arguments passed in
void swap(int &a, int &b)
{
	// Temporarily save value of a
	int temp = a;
	// Put value of b in a
	a = b;
	// Put previous value of a in b
	b = temp;
}
 
int main()
{
	int a = 6;
	int b = 8;
	swap(a, b);
 
	if (a == 8 && b == 6)
		std::cout << "It works!";
	else
		std::cout << "It's broken!";
 
	return 0;
}
