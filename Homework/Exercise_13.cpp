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
    objectArea(objectArea &c); // copy constructor
    int Area() const;          //function prototype
    int Perimeter() const;     // function prototype
    void printObject();
    objectArea(int length); //constructor 2

    //overloaded stream insertion operator;
    friend ostream &operator<<(ostream &, const objectArea &);
    ~objectArea() // destructor
    {
        cout << "Destroying a objectArea object" << endl;
    }
};

void objectArea::printObject()
{
    cout << "Print the address of this pointer: " << &*this << endl;
}
int objectArea::Perimeter() const
{
    return 2 * (length + width);
}

int objectArea::Area() const
{
    return this->length * width;
}
objectArea::objectArea(int length)
    : length(0), width(0) //initialize length and width to zero
{
    //length = width = 0;
    cout << "print out of second constructor" << endl;
    cout << "Cube of length " << length << " is: ";
    cout << length * length * length << endl;
    cout << "\n\n";
}

objectArea::objectArea(int c_length, int c_width)
    : length(0), width(0) //initialize length and width to zero
{
    length = c_length;
    width = c_width;
}
objectArea::objectArea(objectArea &c)
{
    length = c.length;
    width = c.width;
    cout << "Constructing-COPY a objectArea object" << endl;
    cout << "Rectangle area with copy constructor: " << length * width;
    cout << "\n\n";
}

ostream &operator<<(ostream &output, const objectArea &c)
{

    output << "Length: " << c.length << " and  Width: " << c.width << endl;
    output << "Area: " << c.Area() << endl;
    output << "Perimeter: " << c.Perimeter() << endl;
    output << "cube: " << c.length * c.length * c.length << endl;
    output << "\n\n";
    return output;
}

int main()
{
    objectArea Rectangle1(20, 4), cube(20);
    objectArea copyConstructorCall = Rectangle1;
    //cout << "Rectangle1 area: " << Rectangle1.Area() << endl;
    //cout << "Rectangle1 Perimeter: " << Rectangle1.Perimeter() << endl;
    // cout << "\n\n";

    //print copy constructor object
    cout << copyConstructorCall;
    //print the address of the object
    //    cout << "Address of object Rectangle1: " << &Rectangle1 << endl;

    // print Object Rectangle1 and cube;
    //cout << Rectangle1;
    //cout << cube;

    return 0;
}
