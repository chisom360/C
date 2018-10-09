// -------------------------------------------------------
// matrix.cpp
// To compute the sums of rows and columns in a matrix.
// ------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

// Define and initiale a two-dimensional array:

int matrix[3][5] = { { 25, 34, 26, 12,  8 },
                     { 19, 27, 24, 11,  4 },
                     {  6, 15, 35, 36, 18 } };

int rowsum[3];               // For the sums of the rows
int colsum[5];               // For the sums of the columns

// Prototype of function matrixsum():
int matrixsum( int arr2D[][5], int vlen,
               int rsum[], int csum[]);

int main()
{
   cout << "Testing the function matrixsum().\n"
        << endl;

   // Compute sums:
   int totalsum = 
       matrixsum( matrix, 3, rowsum, colsum);

   // Output matrix and sums:
   cout << "The matrix with the sums "
        << "of rows and columns:\n"
        << endl;

   int i,j;
   for( i = 0 ; i < 3 ; ++i)    // Ouput rows of the 
   {                            // matrix with row sums.
     for( j = 0 ; j < 5 ; ++j)
       cout << setw(8) << matrix[i][j];
     cout << " | " << setw(8) << rowsum[i] << endl;
   }

   cout << "  -------------------------------------------"
        << endl;
   for( j = 0 ;  j < 5  ;  ++j )
     cout << setw(8) << colsum[j];
   cout << " | " << setw(8) << totalsum << endl;

   return 0;
}

// --------------------------------------------------------
int matrixsum( int v[][5], int len,
                 int rsum[], int csum[])
{
   int ro, co;                       // Row and column index

   for( ro = 0 ; ro < len ; ++ro)    // To compute row sums
   {
      rsum[ro] = 0;
      for( co = 0 ; co < 5 ; ++co)
        rsum[ro] += v[ro][co];
   }

   for(co = 0 ; co < 5 ; ++co)       // Compute column sums
   {
      csum[co] = 0;
      for( ro = 0 ; ro < len ; ++ro)
        csum[co] += v[ro][co];
   }

   return (rsum[0] + rsum[1] + rsum[2]);  // Total sum = 
}                                         // sum of row sums.

