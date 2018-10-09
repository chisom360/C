// --------------------------------------------
// clors_t.cpp: Tests output of exercise 1
// --------------------------------------------

#include <iostream>
using namespace std;

char* color[] = {"WHITE", "PINK", "BLUE", "GREEN" };
int main()
{
   cout << *color[1]       << "  "
        << *color          << "  "
        << *(color[3] + 3) << "  " 
        <<  color[2] + 1   << "  "
        << *( *(color + 1) + 3)
        << endl;

   return 0;
}
