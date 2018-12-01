//#include <cstddef>
#include <vector>
#include <iostream>
#include <limits>
using namespace std;

int main()
{
	vector<double> doubleVector; // Create a vector with zero elements.
	// Initialize max to smallest number
	double max = -numeric_limits<double>::infinity();

	for (size_t i = 1; true; i++)
	{
		double temp;
		cout << "Enter score " << i << " (-1 to stop): ";
		cin >> temp;
		if (temp == -1)
		{
			break;
		}
		doubleVector.push_back(temp);
		if (temp > max)
		{
			max = temp;
		}
	}

	max /= 100.0;

	for (vector<double>::iterator iter = begin(doubleVector);
		 iter != end(doubleVector); ++iter)
	{
		*iter /= max;
		cout << *iter << " ";
	}
	/*
	for (auto &element : doubleVector)
	{
		element /= max;
		cout << element << " ";
	}
	cout << endl;

	*/
	return 0;
}

/*

#include <limits>
#include <iostream>
 
int main() 
{
    std::cout << "type\tlowest()\tmin()\t\tmax()\n\n";
 
    std::cout << "uchar\t"
              << +std::numeric_limits<unsigned char>::lowest() << '\t' << '\t'
              << +std::numeric_limits<unsigned char>::min() << '\t' << '\t'
              << +std::numeric_limits<unsigned char>::max() << '\n';
    std::cout << "int\t"
              << std::numeric_limits<int>::lowest() << '\t'
              << std::numeric_limits<int>::min() << '\t'
              << std::numeric_limits<int>::max() << '\n';
    std::cout << "float\t"
              << std::numeric_limits<float>::lowest() << '\t'
              << std::numeric_limits<float>::min() << '\t'
              << std::numeric_limits<float>::max() << '\n';
    std::cout << "double\t"
              << std::numeric_limits<double>::lowest() << '\t'
              << std::numeric_limits<double>::min() << '\t'
              << std::numeric_limits<double>::max() << '\n';
}

*/