// --------------------------------------------------------
// tool_1_2.cpp
// Using two "Libraries" and testing name lookup conflicts.
// --------------------------------------------------------

#include <iostream> 

namespace TOOL1
{
  #include "tool1.h"
}
namespace TOOL2
{
  #include "tool2.h"
}

#include <iostream> 
int main()
{
   using namespace std;
   double x = 0.5, y = 10.5, res = 0.0;
   
   cout << "Calling function of Tool1!" << endl;
   res = TOOL1::calculate( x, y);
   cout << "Result:  " << res 
        << "\n---------------------------------" << endl;
   
   cout << "Calling function of Tool2!" << endl;
   res = TOOL2::calculate( x, y);
   cout << "Result:  " << res << endl; 
 
   return 0;
}

