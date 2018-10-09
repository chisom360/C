// ------------------------------------------------------
// interpol.cpp : Template function interpolSearch()
// ------------------------------------------------------
#include <iostream>
using namespace std;

template <class T>
long interpolSearch(const T& key, T* vp, int len) 
{
   int  expect, begin = 0, end = len - 1;
   double temp;

   if( end < 0                      // Array is empty or
       || key > vp[end]             // or key is our of 
       || key < vp[begin] )         // range
      return -1;

   while( begin <= end )
   {
      if(key > vp[end] || key < vp[begin] ) // Key is not
         return -1;                         // in range.

      temp  = (double)(key - vp[begin]) / (vp[end]-vp[begin]);
      temp  = temp * (end - begin) +0.5;
      expect = begin + (int)temp; 

      if( vp[expect] == key )            // Key found? 
         return expect; 
      if( vp[expect] > key)
          end = expect - 1;
      else begin = expect+1;
   }
   return -1; 
}

template <class T>
void insertionSort( T* vp, int len) 
{
   T temp;
   for( int i=0; i < len; i++)
   {
       temp = vp[i];        // Take element out.
       int j;               // Shift greater elements up:
       for( j = i-1; j >= 0 && vp[j] > temp; j--)
          vp[j+1] = vp[j];
       vp[j+1] = temp;            // Insert.
   }
}
 
template <class T>
void display(T* vp, int len)
{
   cout << "\n\nThe array: " << endl;
   for(int i = 0; i < len; i++)
   {
      cout << vp[i] << "  ";
      if( (i+1)%10 == 0)
          cout << endl;
   }
   cout << endl; cin.get();
}

// Two arrays for testing:
short  sv[5] = { 7, 9, 2, 4, 1};
double dv[5] = { 5.7, 3.5, 2.1, 9.4, 4.3 };

int main()
{
   cout << "\nInstantiation for type short: " << endl;
   display(sv, 5);

   insertionSort(sv, 5);
   cout << "\nAfter sorting: ";
   display(sv, 5);

   short key;
   cout << "\nArray element? ";
   cin >> key;  cin.sync();

   int pos = interpolSearch(key, sv, 5);
   if( pos != -1)
       cout << "\nfound!" << endl, cin.get();
   else 
       cout << "\nnot found!" << endl, cin.get();

   // -------------------------------------------------
   cout << "\nInstantiation for type double: " << endl;
   display(dv, 5);
 
   insertionSort(dv, 5);
   cout << "\nAfter sorting: ";
   display(dv, 5);

   double dkey;
   cout << "\nArray element? ";
   cin >> dkey; cin.sync();

   pos = interpolSearch(dkey, dv, 5);
   if( pos != -1)
       cout << "\nfound!" << endl, cin.get();
   else 
       cout << "\nnot found!" << endl, cin.get();

   return 0;
} 
