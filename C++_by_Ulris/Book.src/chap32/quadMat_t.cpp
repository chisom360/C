// quadMat_t.cpp:  Tests a quadratic matrix
// ------------------------------------------------------ 

#include "quadmat.h"


typedef QuadMatrix<int, 5> IntMat;

void display( const IntMat& m );

int main()
{
    IntMat m1, m2;

    try
    {
      for(int i=0; i < m1.dim(); i++)
         for( int j = 0; j < m1.dim(); j++)
         {
            m1[i][j] = i*j;
            m2[i][j] = 1;
         }

      display(m2); cin.get();
      display(m1); cin.get();

      int x,y;
      cout << "Enter two indices: ";
      cin >> x >> y;

      cout << "Matrix element at index [" << x << "," << y << "]: "
           << m1[x][y] << endl;
    }
    catch(out_of_range& err )
    {
        cerr << err.what() << endl;
    }

    return 0;
}

void display( const IntMat& m )
{ 
    cout << endl;
    for(int i=0; i < m.dim(); i++)
    {
        for( int j = 0; j < m.dim(); j++)
           cout << m[i][j] << "  ";
        cout << endl;
    }
    cout << endl; 
}
