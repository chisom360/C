// Fig. 7.11: fig07_11.cpp
// Poll analysis program.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   // define array sizes
   const int responseSize = 20; // size of array responses
   const int frequencySize = 6; // size of array frequency

   // place survey responses in array responses
   const int responses[ responseSize ] = { 1, 2, 5, 4, 3, 5, 2, 1, 3,
      1, 4, 3, 3, 3, 2, 3, 3, 2, 2, 5 };

   // initialize frequency counters to 0
   int frequency[ frequencySize ] = {};

   // for each answer, select responses element and use that value 
   // as frequency subscript to determine element to increment
   for ( int answer = 0; answer < responseSize; ++answer )
      ++frequency[ responses[ answer ] ];

   cout << "Rating" << setw( 17 ) << "Frequency" << endl;

   // output each array element's value
   for ( int rating = 1; rating < frequencySize; ++rating )
      cout << setw( 6 ) << rating << setw( 17 ) << frequency[ rating ] 
         << endl;
} // end main


/**************************************************************************
 * (C) Copyright 1992-2012 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
