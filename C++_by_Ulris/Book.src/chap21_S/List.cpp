// ----------------------------------------------------
// List.cpp 
// Implements the methods of class List,
// which are not previously defined inline.
// ----------------------------------------------------

#include "List.h"

// Destructor of the list:
List::~List()
{
   ListEl *pEl = first,  *next = NULL;

   for(  ; pEl != NULL;  pEl = next) 
   {
      next = pEl->next;
      delete pEl;
   }
}

// Appends a new element at the end of the list:
void List::pushBack(const Date& d, double b)
{ 
   ListEl *pEl = new ListEl( d, b);

   if( last == NULL)       // List empty?
      first = last = pEl;
   else
      last->next = pEl,  last = pEl;
}

// Deletes an element from the beginning of the list.
void List::popFront()
{
   if( first != NULL)       // Not empty?
   {
     ListEl *pEl = first;   // Save the first element.

     first = first->next;   // Move to the next element.
     delete pEl;            // Former first element

     if( first == NULL)     // Empty now?
        last = NULL;
   }
}

// --- Global functions for output ---

// Outputs an element:
ostream& operator<<( ostream& os, const ListEl& le)
{
    os << le.getDate().asString() << "  Amount: ";
    os << fixed << setprecision(2) << setw(10) 
       << le.getAmount();

    return os;
}

// Outputs the list:
ostream& operator<<( ostream& os, const List& List)
{
   ListEl *pEl = List.front();
   if( pEl == NULL)
       os << "The list is empty!" << endl;

   for(  ; pEl != NULL;  pEl = pEl->getNext() )
      os << *pEl << endl;

   return os;
}

