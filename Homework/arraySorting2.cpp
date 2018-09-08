#include <algorithm> // for std::sort
#include <iostream>

int main()
{
	const int length = 5;
	int array[length] = {30, 50, 20, 10, 40};

	//sort from smallest to biggest
	std::cout << "Sorting from smallest to biggest" << std::endl;
	std::sort(array, array + length);

	for (int i = 0; i < length; ++i)
	{
		std::cout << array[i] << ' ';
	}
	std::cout << "\n\n";

	//sorting from biggest to smallest
	std::cout << "Sorting from biggest to smallest" << std::endl;
	std::sort(array, array + length, std::greater<int>());
	for (int i = 0; i < length; ++i)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "\n\n";

	return 0;
}
