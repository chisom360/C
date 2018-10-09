// ------------------------------------------------------
// vecQueue.h
// Defines the Class Template VecQueue<T>
// to represent an vector of queues.
// ------------------------------------------------------

#ifndef _VECQUEUE_H
#define _VECQUEUE_H

#include <vector>
#include <queue>
#include <cstdlib>            // For srand(), rand()
#include <ctime>              // For time()
using namespace std;

template <class T>
class VecQueue
{
  private: 
    vector< queue<T> > v;
    size_t sz;                // Number of queues

  public:
    VecQueue(size_t n);
    
    size_t size() const;      // Current number of all elements
    size_t size(int i) const  // Number of elements in i-th queue
    { return v[i].size(); }

    bool empty() const      { return size() == 0; }
    bool empty(int i) const { return size(i) == 0; }

    void push(const T& a);    // Hot potato algorithm

    const T& pop();           // Removes the element at the
                              // beginning of a randomly 
                              // choosen queue.
    const T& pop(int i);      // Removes the element at the
};                            // beginning of the i-th queue

template <class T>            // Constructor
VecQueue<T>::VecQueue( size_t n)
{ 
    if(n > 0)
      v.resize(n); 
    
    sz = n;    
    srand(time(NULL));
}


template <class T>            // Current number of all elements 
size_t VecQueue<T>::size() const
{
    size_t count = 0;
    for( int i=0; i < sz; ++i)
      count += v[i].size();

    return count;
}

template <class T>      // To insert the argument into the
void VecQueue<T>::push(const T& a)       // shortest queue
{
    int small = 0;      // To determine the shortest queue. 
    for(int i = 0; i < sz; i++)
      if( v[i].size() < v[small].size() )
          small = i;

    v[small].push(a);   // and insert there.
}

// To retrieve and delete an element in a randomly choosen queue:
template <class T> 
const T& VecQueue<T>::pop() 
{
   static T temp;
   int i, i0;
   
   i = i0 = rand() % sz;
   do
   {
     if(!v[i].empty())         // If i-th queue is not empty:
     {                         // To retrieve and delete the
       temp = v[i].front();    // element at the beginning.
       v[i].pop(); 
       break;
     }
     i = (i+1) % sz;           // Or else: Move to the next queue.
   }
   while( i != i0);

   return temp;
}

template <class T>               // To retrieve and delete the element 
const T& VecQueue<T>::pop(int i) // at the beginning of the i-th queue
{
   static T temp;

   if( i >= 0 && i < sz)         // If the index is okay:
   {                             // To retrieve the element at the 
       temp = v[i].front();      // beginning of the i-th queue
       v[i].pop();               // and to delete.
   }

   return temp;
}

#endif   // _VECQUEUE_H