// ------------------------------------------------------
// List.h : Defines the class InhomList
// ------------------------------------------------------

#ifndef _LIST_H_
#define _LIST_H_

#include "cell.h"

class InhomList
{
  private:
    Cell* first;

  protected: 
    Cell* getPrev(const string& s);
    Cell* getPos( const string& s);

    void  insertAfter(const string& s, Cell* prev);
    void  insertAfter(const string& s,const string& r, Cell* prev);
    void  erasePos(Cell* pos);

  public:
     InhomList(){ first = NULL; }
     InhomList(const InhomList& src);
     ~InhomList();

     InhomList& operator=( const InhomList& src);

     void  insert(const string& n);
     void  insert(const string& n, const string& r);

     void  erase(const string& s);

     void displayAll() const;
};
#endif
