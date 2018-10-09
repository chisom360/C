// ------------------------------------------------------
// Array_t.cpp
// Testing class templates Array<T,n>.
// ------------------------------------------------------

#include "array.h"
#include "DayTime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
 
typedef Array<int, 100>   IntArr;
typedef Array<double>     DoubleArr;

typedef Array<DayTime, 5> DayTimeArr;

int main()
{
  try
  {
    const DoubleArr vd(10, 9.9); 
    DoubleArr kd;
    
    cout << "\nThis is the constant array of doubles: \n";
    cout << setw(8) << vd;

    kd = vd;
    cout <<  "\nAn array of doubles after the assignment: "
         << endl;
    cout << setw(8) << kd;

    kd.remove(3);          // Delete the element at
                           // position 3.
    kd.append(10.1);       // Add a new element.
    kd.append(20.2);       // And repeat!
    
    cout <<  "\nThis is the modified array: "
         << endl;
    cout << setw(8) << kd;
    cin.get();
 
    IntArr vi; 
 
    int i;
    for(i=0; i < 10; i++)
        vi.append(rand()/100); 
 
    cout << "\nThis is the array of int values: \n";
    cout << setw(10) << vi;
 
    vi += vi;
    cout << "\nAnd append: \n";
    cout << setw(10) << vi;
 
    IntArr ci(vi);
    cout << "\nThis is the copy of the array: \n";
    cout << setw(10) << ci;


    DayTimeArr vt;     // Array of DayTime objects.
    DayTime temp;

    for(i=0; i < 3; i++)
    { 
       if( !(cin >> temp))
          break;
       vt.append(temp);
    }
 
    cout << "\nThe array with objects of type DayTime:\n";
    for(i=0; i < 3; i++)
      cout << setw(20) << vt[i] << endl;
  }
  catch(BadIndex& err)
  {
      cerr << "\nIndex " << err.getBadIndex()
           << " invalid";
      exit(1);
  }
  catch(OutOfRange& )
  {
      cerr << "\nArray is full!";
      exit(2);
  }

  return 0;
}

