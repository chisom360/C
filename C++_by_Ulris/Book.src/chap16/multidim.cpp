// multidim.cpp
// Demonstrates multidimensional arrays.
// ----------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

char representative[2][20] = {"Armstrong, Wendy",
                              "Beauty, Eve"};

// Alternative:
// string vertreter[2] = {"Armstrong, Wendy",
//                        "Beauty, Eve"};


        // Each representative has five different 
        // articles available, having sold:
int articleCount[2][5] = { { 20,  51, 30,  17, 44},
                           {150, 120, 90, 110, 88} 
                         };

int main()
{ 
   for( int i=0; i < 2; i++ )
   {
      cout << "\n Representative:  " << representative[i];
      cout << "\n Number of items sold: ";

      for( int j = 0; j < 5; j++ )
         cout << setw(6) << articleCount[i][j];
      cout << endl;
   }
   return 0;
 }
