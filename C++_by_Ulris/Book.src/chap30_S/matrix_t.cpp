// ------------------------------------------------------
// matrix_t.cpp : Tests dynamic matrices
// ------------------------------------------------------
#include "matrix.h"

void display( Matrix& m);        // Output a matrix.

int main()
{
    Matrix m(4,5);
    try
    {
      int i,j;
      for( i=0; i < m.getLines(); i++)
        for( j=0; j < m.getCols(); j++)
          m[i][j] = (double)i + j/ 100.0;

      cout << "Matrix created" << endl; 
      display(m);

      Matrix  cop(m);
      cout << "Copy generated." << endl;  
      display(cop);

      cop += m;
      cout << "Compute the sum:" << endl;      
      display(cop);

      Matrix m1(4, 5, 0.0);
      cout << "Initializing a matrix with 0:" << endl; 
      display(m1); 

      m = m1;
      cout << "Matrix assigned:" << endl;
      display(m);
    }
    catch(out_of_range& err)
    {
        cerr << err.what() << endl;
        exit(1);
    }

    return 0;
}

void display( Matrix& m)
{
    for(int i=0; i < m.getLines(); i++)
    {
      for(int j=0; j < m.getCols(); j++)
         cout << m[i][j] << "  ";
      cout << endl;
    }
    cin.get();
}
