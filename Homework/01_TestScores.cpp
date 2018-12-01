
#include <cstddef>
#include <vector>
#include <iostream>
#include <limits>
using namespace std;

int main()
{
	vector<double> doubleVector(10);				  // Create a vector of 10 doubles.
	double max = -numeric_limits<double>::infinity(); // Initialize max to smallest number

	for (size_t i = 0; i < doubleVector.size(); i++)
	{
		cout << "Enter score " << i + 1 << ": ";
		cin >> doubleVector[i];
		if (doubleVector[i] > max)
		{
			max = doubleVector[i];
		}
	}

	max /= 100.0;

	// for ( range_declaration : range_expression ) loop_statement
	for (auto &element : doubleVector)
	{
		element /= max;
		cout << element << " ";
	}
	cout << endl;
	return 0;
}

/*

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = {0, 1, 2, 3, 4, 5};

	for (const int &i : v) // access by const reference
		std::cout << i << ' ';
	std::cout << '\n';

	for (auto i : v) // access by value, the type of i is int
		std::cout << i << ' ';
	std::cout << '\n';

	for (auto &&i : v) // access by forwarding reference, the type of i is int&
		std::cout << i << ' ';
	std::cout << '\n';

	const auto &cv = v;

	for (auto &&i : cv) // access by f-d reference, the type of i is const int&
		std::cout << i << ' ';
	std::cout << '\n';

	for (int n : {0, 1, 2, 3, 4, 5}) // the initializer may be a braced-init-list
		std::cout << n << ' ';
	std::cout << '\n';

	int a[] = {0, 1, 2, 3, 4, 5};
	for (int n : a) // the initializer may be an array
		std::cout << n << ' ';
	std::cout << '\n';

	for (int n : a)
		std::cout << 1 << ' '; // the loop variable need not be used
	std::cout << '\n';
}
*/