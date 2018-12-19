#include <iostream>
#include "KarelWorld.h"
#include "Intersect.h"
#include <vector>
#include "KarelWorldBuilder.h"

int main()
{

    karelWorld w(KarelWorldBuilder());

    w.print();
    w.incrementBeeperCount(2, 6);
    w.incrementBeeperCount(2, 6);
    w.incrementBeeperCount(2, 6);
    w.incrementBeeperCount(2, 6);
    w.print();
    w.decrementBeeperCount(2, 6);
    w.print();

    //w.print(2,6); use to print a specific intersection

    return 0;
}