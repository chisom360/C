// sortvec.h: The Class Template SortVec representing  
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
   SortVec(int n, const T& x = T());
 
   void insert(const T& obj);     // in sorted order
   int  search(const T& obj);     
   void merge(const SortVec<T>& v); 
};


// Die Methode insert() fügt ein neues Objekt am Ende  
// des Vektors ein und sortiert es dann ein. 
template <class T, class Compare >
void SortVec<T, Compare>::insert(const T& obj) 
{
   SortVec::iterator  pos, temp;
   push_back(obj);               // Am Ende einfügen.
   
   pos = end();  pos--;          // Letzte Position  

   while (pos-- > begin())       // Einsortieren:
   {  
     if( obj < *pos)             // Tauschen:
     { temp = pos; *(++temp) = *pos;  *pos = obj; }
     else   break;
   }
}

// Die Methode search()sucht ein vorgegebenes Objekt 
// nach dem binären Suchverfahren im Container. Hierbei
// wird das Objekt mit dem mittleren Element im Vektor 
// verglichen. Ist das Objekt kleiner, so wird in der 
// linken Hälfte, andernfalls in der rechten Hälfte 
// weitergesucht. Das binäre Suchverfahren hat eine 
// logarithmische Laufzeit und ist damit sehr schnell.

template <class T, class Compare >
int SortVec<T, Compare>::search(const T& obj)   
{
  int first = 0, last = end() - begin() - 1, mid; 

  while( first < last )
  {
      mid = (first + last + 1)/ 2;
                            // In unterer Hälfte suchen:
   if( obj < (*this)[mid] ) 
         last = mid - 1; 
   else first = mid;        // bzw. in oberer Hälfte.
  }
  
  if ( obj == (*this)[first] )  // Gefunden?
        return first;           // Ja.
  else  return -1;          // Nicht gefunden.
}

template <class T, class Compare >
void SortVec<T,Compare>::merge(const SortVec<T, Compare>& v) 
{
  SortVec temp;                   // Temporärer Vektor
  SortVec::iterator pos = begin(); // Iterator
  int n1 = 0, n2 = 0; 

        // Das jeweils kleinere Objekt in temp kopieren:
  while(n1 < size() &&  n2 < v.size())
    if( pos[n1] <= v[n2] ) 
       temp.push_back(pos[n1++]);  
    else
        temp.push_back(v[n2++]);
                                 // Rest anhängen:
  while( n1 < size())
    temp.push_back(pos[n1++]); 

  while( n2 < v.size())
    temp.push_back(v[n2++]); 

  *this = temp; 
}

