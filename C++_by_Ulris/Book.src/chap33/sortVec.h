// sortVec.h: The Class Template SortVec representing  
//            a sorted vector.
//---------------------------------------------------

#include <vector>      // For class template vector<T>
#include <functional>  // For comparator class less<T>
using namespace std;

template <class T, class Compare = less<T> >
class SortVec : public vector<T>  
{
  public:
   SortVec()  { }
   SortVec(int n, const T& x = T()) : vector<T>(n,x) {}
 
   void insert(const T& obj);       // in sorted order
   int  search(const T& obj);     
   void merge(const SortVec<T>& v); 
};


//---------------------------------------------------
// Method insert() adds a new object at the end  
// of the vector and reorganizes in ascending order. 
//
template <class T, class Compare >
void SortVec<T, Compare>::insert(const T& obj) 
{
   SortVec::iterator  pos, temp;
   push_back(obj);               // Add at the end.
   
   pos = end();  pos--;          // Last position  

   while (pos-- > begin())       // Sort:
   {  
     if( obj < *pos)             // Swap:
     { temp = pos; *(++temp) = *pos;  *pos = obj; }
     else   break;
   }
}

//---------------------------------------------------
// Method search() seeks an object obj in the vector
// using the binary search algorithms:
// The object obj is first compared to the element in 
// the middle of the vector. If obj is smaller than the
// "middle" element, it must belong to the left half or
// else to the right half of the vector. We repeat this
// process comparing obj with the "middle" element in
// the section where it is known to be, repeatedly
// halving the size of the interval until the interval
// consists of a single point, which is where obj 
// belongs.
// This algorithm has logarithmic time and thus  
// is very fast.
//
template <class T, class Compare >
int SortVec<T, Compare>::search(const T& obj)   
{
  int first = 0, last = end() - begin() - 1, mid; 

  while( first < last )
  {
     mid = (first + last + 1)/ 2;
                            // Search the left half,
     if( obj < (*this)[mid] ) 
         last = mid - 1; 
     else
         first = mid;        // the right half.
  }
  
  if( obj == (*this)[first] )   // Found?
      return first;             // Yes.
  else 
      return size();            // Not found.
}


// ---------------------------------------------------
// Method merge() merges the argument vector
// into the vector *this.
//
template <class T, class Compare >
void SortVec<T,Compare>::merge(const SortVec<T, Compare>& v) 
{
   SortVec temp;                    // Temporary vector
   SortVec::iterator pos = begin(); // Iterator
   int n1 = 0, n2 = 0; 

          // Copy the smaller object into vector temp:
   while(n1 < size() &&  n2 < v.size())
     if( pos[n1] <= v[n2] ) 
        temp.push_back(pos[n1++]);  
     else
        temp.push_back(v[n2++]);
                                    // Append the rest:
   while( n1 < size())
     temp.push_back(pos[n1++]); 

   while( n2 < v.size())
     temp.push_back(v[n2++]); 

   *this = temp; 
}
