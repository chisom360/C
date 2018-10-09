// ------------------------------------------------------
// List.cpp : The methods of class InhomList
// ------------------------------------------------------

#include "List.h"
#include <typeinfo>

// Copy constructor:
InhomList::InhomList(const InhomList& src)
{
   // Append the elements from src to the empty list.
   first = NULL;
   Cell *pEl = src.first;

   for(  ; pEl != NULL;  pEl = pEl->getNext() )
       if(typeid(*pEl) == typeid(DerivedEl))
           insert(dynamic_cast<DerivedEl*>(pEl)->getName(),
                  dynamic_cast<DerivedEl*>(pEl)->getRem());
       else
           insert(dynamic_cast<BaseEl*>(pEl)->getName());
}

// Assignment:
InhomList& InhomList::operator=(const InhomList& src)
{
   // To free storage for all elements: 
   Cell *pEl = first,
        *next = NULL;
   while( pEl != NULL )
   {
      next = pEl->getNext();
      delete pEl;
      pEl = next;
   }

   first = NULL;                // Empty list

   // Copy the elements from src to the empty list.
   pEl = src.first;
   
   for(  ; pEl != NULL;  pEl = pEl->getNext() )
      if(typeid(*pEl) == typeid(DerivedEl))
           insert(dynamic_cast<DerivedEl*>(pEl)->getName(), 
                  dynamic_cast<DerivedEl*>(pEl)->getRem());
      else
           insert(dynamic_cast<BaseEl*>(pEl)->getName());
       
   return *this;
}

 
// Destructor:
InhomList::~InhomList()
{
   Cell *pEl = first,
        *next = NULL;
   while( pEl != NULL ) 
   {
      next = pEl->getNext();
      delete pEl;
      pEl = next;
   }
}

Cell* InhomList::getPrev(const string& n)
{
   Cell *pEl  = first,
        *prev = NULL;

   while( pEl != NULL  ) 
   {
      if( n > dynamic_cast<BaseEl*>(pEl)->getName() )
      {
          prev = pEl;   pEl  = pEl->getNext();
      }
      else 
          return prev;
   }
   return prev;
}

Cell* InhomList::getPos( const string& n)
{
   Cell *pEl  = first;

   while( pEl != NULL  && (n != dynamic_cast<BaseEl*>(pEl)->getName()))
      pEl  = pEl->getNext();

   if( pEl != NULL  &&  n == dynamic_cast<BaseEl*>(pEl)->getName())
      return pEl;
   else
      return NULL;
}

void InhomList::insertAfter(const string& s, Cell* prev)
{
   if( prev == NULL )           // Insert at the beginning:
      first = new BaseEl( first, s); 
   else                         // In the middle or at the end: 
   {
      Cell* p = new BaseEl(prev->getNext(), s);
      prev->setNext(p);
   } 
}

void InhomList::insertAfter( const string& s,
                             const string& r, Cell* prev)
{
   if( prev == NULL )      // Insert at the beginning:
      first = new DerivedEl( first, s, r); 
   else                    // In the middle or at the end: 
   { 
      Cell* p = new DerivedEl(prev->getNext(), s, r);
      prev->setNext(p);
   } 
}

void InhomList::insert(const string& n)
{
   Cell* pEl = getPrev(n);
   insertAfter(n, pEl);
}

void  InhomList::insert(const string& n, const string& r)
{
   Cell* pEl = getPrev(n);
   insertAfter(n, r, pEl);
}

void  InhomList::erasePos(Cell* pos)
{
   Cell* temp;

   if( pos != NULL)
     if( pos == first )       // Delete the first element
     {
        temp = first;
        first = first->getNext();
        delete temp;
     }
     else          // Delete from the middle or at the end
     {                        // Get the predecessor
        temp = getPrev( dynamic_cast<BaseEl*>(pos)->getName());

        if(temp != NULL)      // and bend pointer.
           temp->setNext(pos->getNext());
        delete pos;
     }
}

void  InhomList::erase(const string& n)
{
    erasePos( getPos(n));
}

void InhomList::displayAll() const
{
   Cell* pEl = first;
   while(pEl != NULL)
   {
       pEl->display();
       pEl = pEl->getNext();
   }
}

