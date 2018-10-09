// quadMat.h:  Defining the template QuadMatrix
//             to represent quadratic matrices
// -----------------------------------------------------
#include <iostream>
#include <stdexcept>
using namespace std; 

template <class T , int cnt = 10>
class QuadMatrix
{
  private:
    T mat[cnt][cnt];

  public:
    int dim() const { return cnt; }
 
    T* operator[](int line) throw(out_of_range)
    {  
      if( line < 0 || line >= cnt)
        throw out_of_range("QuadMatrix: Index out of range");
      else
        return mat[line];
    }
 
    const T* operator[](int line) const  throw(out_of_range)
    {  
      if( line < 0 || line >= cnt)
        throw out_of_range("QuadMatrix: Index out of range");
      else
        return mat[line];
    }

    T&  operator()(int line, int col) throw(out_of_range);
    const T&  operator()(int line, int col) const throw(out_of_range); 
 
    friend QuadMatrix& operator+(const QuadMatrix&, const QuadMatrix&);

    // etc.
};



template <class T, int cnt>
T& QuadMatrix<T, cnt>::operator()(int line, int col) throw(out_of_range)     
{
    if( line < 0 || line >= cnt || col < 0 || col >= cnt)
       throw out_of_range("Matrix: Index out of range");
    else
      return mat[line][col];
}

template <class T, int cnt>
const T& QuadMatrix<T, cnt>::operator()(int line, int col) const throw(out_of_range)     
{
    if( line < 0 || line >= cnt || col < 0 || col >= cnt)
       throw out_of_range("Matrix: Index out of range");
    else
      return mat[line][col];
}


