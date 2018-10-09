// List.h:  Definition der Klasse InhomList
// ---------------------------------------------
#ifndef _LIST_H
#define _LIST_H

#include "cell.h"

class InhomList
{
  private:
    Cell* first;

  protected:
    Cell* getPrev( const string& s);
    void  insertAfter( const string& s, Cell* prev);
    void  insertAfter( const string& s, const string& r, Cell* prev);

  public:
     InhomList() { first = NULL; }
     InhomList( const InhomList& src);
     ~InhomList();

     InhomList& operator=( const InhomList& src);

     void insert( const string& n);
     void insert( const string& n, const string& r);

     void displayAll() const;
};

#endif
