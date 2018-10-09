// matrix_t.cpp: Testing dynamic matrices
// ---------------------------------------------

#include "matrix.h"

int main()
{
    Matrix m(4,5);

    try
    {
      int i,j;
      for( i=0; i < m.getLines(); i++)
        for( j=0; j < m.getCols(); j++)
          m[i][j] = (double)i + j/ 100.0;
       
      cout << "Matrix generated" << endl;  cin.get();      
      for( i=0; i < m.getLines(); i++)
      {
        for( j=0; j < m.getCols(); j++)
            cout << m[i][j] << "  ";
        
        cout << endl;
      }
    }
    catch(out_of_range& err)
    {
        cerr << err.what() << endl;
        exit(1);
    }
    
    return 0;
}
