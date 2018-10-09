// -- ----------------------------------------------------
// matrix.h :  Represents dynamic matrices
// -------------------------------------------------------
#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdexcept>
#include <iostream>
using namespace std;

class Row
{
    double *ro;
    int size;

  public:
    Row( int s) { size = s;  ro = new double[s]; }
    ~Row() { delete[]ro; }
 
    double& operator[](int i) 
    {
      if(i < 0 || i >= size)
        throw out_of_range("Column index: Out of Range\n");
      return ro[i]; 
    }
    const double& operator[](int i)  const
    {
      if(i < 0 || i >= size)
        throw out_of_range("Column index: Out of Range\n");
      return ro[i]; 
    }
};

class Matrix
{
  private:
    Row **mat;            // Pointer to array of rows
    int lines, cols;      // Number of rows and columns
  
  public:
    Matrix(int ro , int co)
    { 
      lines = ro; cols = co;
      mat = new Row*[lines];
      for(int i=0; i < lines; i++)
         mat[i] = new Row(cols);
    }

    Matrix:: Matrix( int z, int s, double val);
 
    Matrix( const Matrix& ); 

    ~Matrix()
    {  for(int i=0; i < lines; i++)
           delete mat[i];
       delete[] mat;
    }
    int  getLines() const { return lines; }
    int  getCols()  const { return cols; }

    Row& operator[](int i) 
    { 
      if(i < 0 || i >= lines)
         throw out_of_range("Row index: Out of Range\n");
      return *mat[i]; 
    }

    const Row& operator[](int i) const
    { 
      if(i < 0 || i > lines)
         throw out_of_range("Row index: Out of Range\n");
      return *mat[i]; 
    }
                                     // Assignments:
    Matrix& operator=( const Matrix& );
    Matrix& operator+=( const Matrix& );
};

#endif
