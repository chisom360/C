// ----------------------------------------------------
// List.h 
// Defines the classes ListEl and List 
// representing a linked list.
// ----------------------------------------------------
#ifndef _LIST_H_
#define _LIST_H_

#include "Date.h"
#include <iostream>
#include <iomanip>
using namespace std;

class ListEl 
{
  private:
    Date  date;           // Date
    double amount;        // Amount of money
    ListEl* next;         // Pointer to successor

  public:
    ListEl( Date    d = Date(1,1,1),
            double  b = 0.0, 
            ListEl* p = NULL)
            : date(d), amount(b), next(p) {}

    // Access methods
    const Date& getDate() const { return date; }
    void setDate()        // Sets the current date
    {
       date.setDate();
    }
    bool setDate( int day, int month, int year)
    {
       return setDate( day, month, year);
    }

    double  getAmount() const   { return amount; }
    void    setAmount(double a) { amount = a;  }
    ListEl* getNext()  const    { return next; }

    friend class List; 
};

// Output an element
ostream& operator<<( ostream& os, const ListEl& le);

// ------------------------------------------------------
// Defines the List class
class List
{
  private:
    ListEl* first, *last;
  public:
    List(){ first = last = NULL; }   // Constructor
    ~List();                         // Destructor 

    List(const List&);               // Copy constructor
    List& operator=( const List&);   // Assignment

    // Access first and last elements:
    ListEl* front() const { return first; } 
    ListEl* back()  const { return last; } 

    // Appends a new element at the end of the list:
    void pushBack(const Date& d, double b);

    // Deletes an element at the beginning of the list.
    void popFront();
};

// Outputs the list
ostream& operator<<( ostream& os, const List& le);
#endif  // _LIST_H_

