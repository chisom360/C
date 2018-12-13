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

    return 0;
}