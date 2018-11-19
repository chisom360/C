/**
 * Create a class Rectangle in the style of Point and Triangle classes
 * Exercise 15
 * Chisom Esele
 */

#include <iostream>
using namespace std;

class point
{
    int x, y;

  public:
    point()
    {
        x = y = 0;
    }
    point(int xvalue, int yvalue);

    void setpoint(int new_x, int new_y);
    void setX(int new_x);
    void setY(int new_y);
    int getX() const;
    int getY() const;

    friend ostream &operator<<(ostream &os, const point &p);
};

point::point(int xvalue, int yvalue)
{
    setpoint(xvalue, yvalue);
}

void point::setX(int new_x)
{
    x = new_x;
}

void point::setY(int new_y)
{
    y = new_y;
}

int point::getX() const
{
    return x;
}

int point::getY() const
{
    return y;
}

void point::setpoint(int new_x, int new_y)
{
    x = new_x;
    y = new_y;
}

ostream &operator<<(ostream &os, const point &p)
{
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

class Rectangle
{
    point v1;
    point v2;
    point v3;
    point v4;

  public:
    Rectangle()
    {
    }
    Rectangle(point p1, point p2, point p3, point p4);
    Rectangle(int px1, int py1, int px2, int py2, int px3, int py3, int px4, int py4);

    void setRectangle(int px1, int py1, int px2, int py2, int px3, int py3, int px4, int py4);
    point getVertex1() const;
    point getVertex2() const;
    point getVertex3() const;
    point getVertex4() const;
    void setVertex1(point p1);
    void setVertex2(point p2);
    void setVertex3(point p3);
    void setVertex4(point p4);

    friend ostream &operator<<(ostream &os, const Rectangle &t);
};

Rectangle::Rectangle(point p1, point p2, point p3, point p4)
{
    setRectangle(p1.getX(), p1.getY(), p2.getX(), p2.getY(), p3.getX(), p3.getY(), p4.getX(), p4.getY());
}

Rectangle::Rectangle(int px1, int py1, int px2, int py2, int px3, int py3, int px4, int py4)
{
    setRectangle(px1, py1, px2, py2, px3, py3, px4, py4);
}

void Rectangle::setRectangle(int px1, int py1, int px2, int py2, int px3, int py3, int px4, int py4)
{
    v1 = point(px1, py1);
    v2 = point(px2, py2);
    v3 = point(px3, py3);
    v4 = point(px4, py4);
}

point Rectangle::getVertex1() const
{
    return v1;
}

point Rectangle::getVertex2() const
{
    return v2;
}

point Rectangle::getVertex3() const
{
    return v3;
}

point Rectangle::getVertex4() const
{
    return v4;
}

void Rectangle::setVertex1(point p1)
{
    v1 = p1;
}

void Rectangle::setVertex2(point p2)
{
    v2 = p2;
}

void Rectangle::setVertex3(point p3)
{
    v3 = p3;
}

void Rectangle::setVertex4(point p4)
{
    v4 = p4;
}
ostream &operator<<(ostream &os, const Rectangle &t)
{
    os << t.v1 << " " << t.v2 << " " << t.v3 << " " << t.v4;
    return os;
}

int main()
{
    point p1(2, 1); // Build some points
    point p2(2, 4);
    point p3(6, 4);
    point p4(6, 1);
    Rectangle t(p1, p2, p3, p4); // Build a Rectangle w/ points

    cout << t << '\n'
         << endl; // Display some values
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << p4 << endl;

    return 0;
}

/*       output

(2,1) (2,4) (6,4) (6,1)

(2,1)
(2,4)
(6,4)
(6,1)

*/