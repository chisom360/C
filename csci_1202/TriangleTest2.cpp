/*     FILE: TriangleTest2.cpp     */

/*  Classes triangle uses class point.

    triangle "has-a" set of points that are vertices.
 
*/
#include <iostream>
using namespace std;

class point{
    int x,y;

  public:
    point( )
    { x=y=0;}
    point(int xvalue, int yvalue);
    
    void setpoint(int new_x, int new_y);
    void setX(int new_x);
    void setY(int new_y);
    int getX( ) const;
    int getY( ) const;
    
    friend ostream & operator<<(ostream & os, const point& p);
};

point::point(int xvalue, int yvalue)
{
  setpoint(xvalue,yvalue);
}

void point::setX(int new_x)
{
        x = new_x;
}

void point::setY(int new_y)
{
  y = new_y;
}

int point::getX( ) const
{
  return x;
}

int point::getY( ) const
{
  return y;
}

void point::setpoint(int new_x, int new_y)
{
  x = new_x;
  y = new_y;
}

ostream & operator<<(ostream & os, const point& p)
{
  os << "(" << p.x << "," << p.y << ")";
  return os;
}

class triangle{
    point v1;
    point v2;
    point v3;
  public:
    triangle( )
    {}
    triangle( point p1, point p2, point p3);
    triangle(int px1, int py1, int px2, int py2, int px3, int py3);
    
    void setTriangle( int px1, int py1, int px2, int py2, int px3, int py3);
    point getVertex1( ) const;
    point getVertex2( ) const;
    point getVertex3( ) const;
    void setVertex1(point p1);
    void setVertex2(point p2);
    void setVertex3(point p3);
    
    friend ostream & operator<<(ostream & os, const triangle& t);
};

triangle::triangle( point p1, point p2, point p3)
{
  setTriangle(p1.getX( ), p1.getY( ), p2.getX( ), p2.getY( ), p3.getX( ), p3.getY( ));
}

triangle::triangle(int px1, int py1, int px2, int py2, int px3, int py3)
{
  setTriangle(px1, py1, px2, py2, px3, py3);
}

void triangle::setTriangle( int px1, int py1, int px2, int py2, int px3, int py3)
{
  v1 = point(px1, py1);
  v2 = point(px2, py2);
  v3 = point(px3, py3);
}
    
point triangle::getVertex1( ) const
{
  return v1;
}

    
point triangle::getVertex2( ) const
{
  return v2;
}

    
point triangle::getVertex3( ) const
{
  return v3;
}

void triangle::setVertex1(point p1)
{
  v1 = p1;
}
   
void triangle::setVertex2(point p2)
{
  v2 = p2;
}

void triangle::setVertex3(point p3)
{
  v3 = p3;
}

ostream & operator<<(ostream & os, const triangle& t)
{
  os << t.v1 << " " << t.v2 << " " << t.v3;
  return os;
}

int main( )
{
    point p1(7,5);         // Build some points
    point p2(7,7);
    point p3(9,7);
    triangle t(p1,p2,p3);  // Build a triangle w/ points

    cout << t << endl;     // Display some values
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;


    return 0;
}


/*    OUTPUT: TriangleTest2.cpp

	(7,5) (7,7) (9,7)
	(7,5)
	(7,7)
	(9,7)

*/
