// ------------------------------------------------------
// matrix.cpp : Defines methods of class Matrix
// ------------------------------------------------------

#include "matrix.h"

Matrix:: Matrix( int ro, int co, double val)
{
    lines = ro; cols = co;
    mat = new Row*[lines];          // Array of pointers to
                                    // arrays of rows
    int i, j;
    for(i=0; i < lines; i++)        // Arrays of rows:
    {
       mat[i] = new Row(cols);      // Allocate memory
       for(j = 0; j < cols; ++j)
          (*this)[i][j] = val;      // and copy values.
    }
}

Matrix:: Matrix( const Matrix& m)
{
    lines = m.lines; cols = m.cols;  // Rows and columns

    mat = new Row*[lines];           // Array of pointers
                                     // to arrays of rows
    int i, j;
    for(i=0; i < lines; i++)         // Arrays of rows:
    {
        mat[i] = new Row(cols);      // To allocate 
                                     // storage
        for( j = 0; j < cols; ++j)
            (*this)[i][j] = m[i][j]; // and copy values.   
    }
}

Matrix& Matrix::operator=(const Matrix& m)
{
    int i, j;                        // Free "old" storage:
    for(i=0; i < lines; i++)
        delete mat[i];
    delete[] mat;

    lines = m.lines; cols = m.cols;  // Rows, columns

    mat = new Row*[lines];           // Array of pointers
                                     // to arrays of rows
    for(i=0; i < lines; ++i)         // Array of rows:
    {
       mat[i] = new Row(cols);       // Allocate space 
                                 
       for( j = 0; j < cols; ++j)
          (*this)[i][j] = m[i][j];   // and copy values.
    }

    return *this;
}
 
Matrix& Matrix::operator+=( const Matrix& m)
{
    int i, j;
    if( cols == m.cols && lines == m.lines)
        for( i=0; i < lines; ++i)
            for( j=0; j < cols; ++j)
                (*this)[i][j] += m[i][j];

    return *this;
}
