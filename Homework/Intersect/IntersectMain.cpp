#include <iostream>
#include "Intersect.h"

int main()
{
    Intersection intersectClassObject(1, 8);
    Intersection intersect2(1, 4, 1);
    Intersection intersect3(1, 3, 3, South);
    Intersection intersect4(3, 6, 4, North, West);
    Intersection intersect5(7, 9, 54, North, South, West);
    Intersection intersect6(8, 60, 0, North, South, East, West);

    intersectClassObject.print();
    intersect2.print();
    intersect3.print();
    intersect4.print();
    intersect5.print();
    intersect6.print();

    return 0;
}