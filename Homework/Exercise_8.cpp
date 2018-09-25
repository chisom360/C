#include <iostream>
using namespace std;

class objectArea
{
  public:
    int c_length;
    int c_width;
    void print();
    int rect(int length, int width);
    int Peri(int length, int width);
    int rect(int length);
};
// constructor1
int objectArea::rect(int length, int width)
{
    return length * width;
}
int objectArea::Peri(int length, int width)
{
    c_length = length;
    c_width = width;
    return 2 * (length + width);
}

void objectArea::print()
{
    cout << "Length: " << c_length << " and  Width: " << c_width << endl;
}

// constructor 2
int objectArea::rect(int length)
{
    cout << "This is the default constructor under test" << endl;
    cout << "Area printed by default constructor is: ";
    c_length = length;
    c_width = 3;
    return length * c_width;
}
int main()
{
    //class object
    objectArea Rectangle;

    //class object for default constructor
    objectArea defaultConstructorTest;

    cout << "Area of the Rectangle is " << Rectangle.rect(10, 3) << endl;
    cout << "The Perimeter of the Rectangle is " << Rectangle.Peri(10, 3) << endl;
    cout << '\n';
    cout << "Test print to see if my constructor is working" << endl;
    Rectangle.print();
    cout << '\n';
    cout << defaultConstructorTest.rect(10);

    return 0;
}
