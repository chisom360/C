#include <iostream>
#include <thread>
#include <chrono>
#include "Timer.h"

using namespace std;

int max(int num1, int num2)
{
    // local variable declaration
    int result;
    if (num1 > num2)
    {
        result = num1;
        cout << "Printing answer: " << num1 << endl;
    }
    else
    {
        result = num2;
        cout << "Printing answer: " << num2 << endl;
        return result;
    }
}

int main()
{
    Timer t = Timer();
    Timer T = Timer();

    t.setInterval([&]() {
        cout << "Hey.. After each 1s..." << endl;
    },
                  100);

    //T.setInterval([&]() { max(3, 2); T.stop(); }, 200);
    T.setInterval([&]() { max(3, 2); }, 200);

    t.setTimeout([&]() {
        cout << "Hey.. After 5.2s. But I will stop the timer!" << endl;
        t.stop();
    },
                 5200);

    cout << "I am Timer" << endl;

    while (true)
        ; // Keep main thread active
}