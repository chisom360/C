// string3.cpp: Inputs and compares lines of text.

#include <iostream>
#include <string>
using namespace std;

string prompt = "Please enter two lines of text!\n",
       line( 50, '-');

int main()
{
   string line1, line2, key = "y";

   while( key == "y" || key == "Y") 
   {
     cout << line << '\n' << prompt << line << endl; 
   
     getline( cin, line1);        // Read the first
     getline( cin, line2);        // and second line.

     if( line1 == line2)
       cout << " Both lines are the same!" << endl;
     else
     {
       cout << "The smaller line is:\n\t";
       cout << (line1 < line2 ? line1 : line2)
            << endl;
     
       int len1 = line1.length(),
           len2 = line2.length();
       
       if( len1 == len2)
         cout << "Both lines have the same length! \n";
       else
       { 
         cout << "The shorter line is:\n\t";
         cout << (len1 < len2 ? line1 : line2)
              << endl;
       }
     } 
     
     cout << "\nRepeat? (y/n) ";
     
     do
       getline( cin, key);
     while(    key != "y" && key != "Y"
            && key != "n" && key != "N");
   }
   
   return 0;
}
