// ------------------------------------------------------
// strDemo.cpp: Insert, search and replace in strings. 
// ------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

string header = "Demonstrating the use of strings\n",
       s1 = "As time by ...",
       s2 = "goes ";

int main()
{
   int pos = 0;

   cout << header << endl;
   cout << "s1 : " << s1 << endl;

   // To insert:
   cout << "\nInserting string \"" << s2 << "\"" << endl;
   
   pos = s1.find("by");
   if( pos != string::npos )
      s1.insert(pos,s2);
   cout << "s1 : " << s1 << endl;              // Result

   // To erase:
   cout << "\nTo erase remaining characters behind \"by\":"
        << endl;
 
   pos = s1.find("by");
   if( pos != string::npos )
      s1.erase(pos + 3);
   cout << "s1 : " << s1 << endl;              // Result

   // To replace:
   cout << "\nTo replace \"time\" by \"Bill\":"
        << endl;
   
   pos = s1.find("time");
   if( pos != string::npos )
      s1.replace(pos, 4, "Bill");
   cout << "s1 : " << s1 << endl;              // Result

   return 0;
}
