#include <iostream>
using namespace std;

class objectArea
{
  public:
    void print() const;
    int length;
    int width;

    //constructor 1
    objectArea(int length, int width);

    // copy constructor
    objectArea(objectArea &c)
    {
        length = c.length;
        width = c.width;
        cout << "Constructing-COPY a objectArea object" << endl;
        cout << "Rectangle area with copy constructor: " << length * width;
        cout << "\n\n";
    }
    int Area()
    {
        return length * width;
    }
    int Perimeter()
    {
        return 2 * (length + width);
    }
    //constructor 2
    objectArea(int length)
    {
        //length = width = 0;
        cout << "print out of second constructor" << endl;
        cout << "Cube of length " << length << " is: ";
        cout << length * length * length << endl;
        cout << "\n\n";
    }
    ~objectArea()
    {
        cout << "Destroying a objectArea object" << endl;
    }
};
objectArea::objectArea(int c_length, int c_width)
{
    length = c_length;
    width = c_width;
}

void objectArea::print() const
{
    cout << "Length: " << length << " and  Width: " << width << endl;
}

int main()
{
    objectArea Rectangle1(20, 4), cube(20);
    objectArea copyConstructorCall = Rectangle1;
    cout << "Rectangle1 area: " << Rectangle1.Area() << endl;
    cout << "Rectangle1 Perimeter: " << Rectangle1.Perimeter() << endl;
    Rectangle1.print();
    cout << "\n\n";

    return 0;
}

/*         output: Exercise_9.cpp

print out of second constructor
Cube of length 20 is: 8000


Constructing-COPY a objectArea object
Rectangle area with copy constructor: 80

Rectangle1 area: 80
Rectangle1 Perimeter: 48
Length: 20 and  Width: 4


Destroying a objectArea object
Destroying a objectArea object
Destroying a objectArea object

*/