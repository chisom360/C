#include <iostream>
using namespace std;

class objectArea
{
public:
  int c_length;
  int c_width;

  int rect(int length, int width)
  {

    c_length = length;
    c_width = width;
    return length * width;
  }
  int Peri(int length, int width)
  {
    c_length = length;
    c_width = width;

    return 2 * (length + width);
  }
};

int main()
{
  objectArea Rectangle;
  cout << "Area of the Rectangle is " << Rectangle.rect(10, 3) << endl;
  cout << "The Perimeter of the Rectangle is " << Rectangle.Peri(10, 3) << endl;
  cout << "Length: " << Rectangle.c_length << endl;
  cout << "Width: " << Rectangle.c_width << endl;

  return 0;
}

/* output: Exercise_7.cpp

Area of the Rectangle is 30
The Perimeter of the Rectangle is 26
Length: 10
Width: 3
*/