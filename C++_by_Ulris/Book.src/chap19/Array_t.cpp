// Array_t.cpp
// A simple class to represent an array 
// with range checking.
// -------------------------------------------------- 
#include <iostream>
#include <cstdlib>                // For exit()
using namespace std;
#define MAX 100

class FloatArr
{
  private:
    float v[MAX];                // The array

  public: 
    float& operator[](int i); 
    static int MaxIndex(){ return MAX-1; } 
};

float& FloatArr::operator[]( int i )
{
   if( i < 0 || i >= MAX )
   {
      cerr << "\nFloatArr: Outside of range!" << endl;
      exit(1);
   }
   return v[i];      // Reference to i-th element.
}

int main()
{
    cout << "\n An array with range checking!\n"
         << endl;

   FloatArr random;      // Create array.
   int i;                // An index.
                         // Fill with random values:
   for( i=0; i <= FloatArr::MaxIndex(); ++i)
      random[i] = (rand() - RAND_MAX/2) / 100.0F;

   cout << "\nEnter indices between 0 and "
        << FloatArr::MaxIndex() << "!"
        << "\n (Quit by entering invalid input)"
        << endl;

   while( cout << "\nIndex: " && cin >> i ) 
      cout << i << ". element:  " << random[i];

   return 0; 
}
