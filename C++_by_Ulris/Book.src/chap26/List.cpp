// List.cpp: Methods of classe InhomList
// ---------------------------------------------------

#include "List.h"
#include <typeinfo>

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
   // To free the storage for all elements: 
   Cell *pEl = first,
        *next = NULL;
   while( pEl != NULL )
   {
      next = pEl->getNext();
      delete pEl;
      pEl = next;
   }

   first = NULL;                  // Empty List

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
          prev = pEl;
          pEl  = pEl->getNext();
      }
      else 
          return prev;
      
   }
   return prev;
}

void InhomList::insertAfter(const string& s, Cell* prev)
{
  if( prev == NULL )             // Insert at the beginning,
      first = new BaseEl( first, s); 
  else                           // middle or end. 
   {
     Cell* p = new BaseEl(prev->getNext(), s);
     prev->setNext(p);
   } 
}

void InhomList::insertAfter(const string& s, const string& b, Cell* prev)
{
  if( prev == NULL )             // Insert at the beginning,
     first = new DerivedEl( first, s, b); 
  else                           // middle or end. 
  { 
     Cell* p = new DerivedEl(prev->getNext(), s, b);
     prev->setNext(p);
  } 
}

void InhomList::insert(const string& n)
{
   Cell* pEl = getPrev(n);
   insertAfter(n, pEl);
}

void  InhomList::insert(const string& n, const string& b)
{
   Cell* pEl = getPrev(n);
   
   insertAfter(n, b, pEl);
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
