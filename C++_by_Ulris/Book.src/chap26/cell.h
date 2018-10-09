// cell.h: Defining the classes Cell, BaseEl and DerivedEl
// -------------------------------------------------------

#ifndef _CELL_
#define _CELL_

#include <cstdio>               // Definition of NULL
#include <string>
#include <iostream>
using namespace std;

class Cell
{
  private:
    Cell* next;

  protected:
    Cell(Cell* suc = NULL ) { next = suc; }

  public: 
    virtual ~Cell(){ }
    // Access methods:
    Cell* getNext() const { return next; }
    void  setNext(Cell* suc) { next = suc; }

    virtual void display() const = 0;
};

class BaseEl : public Cell
{
  private:
    string name;

  public:
    BaseEl( Cell* suc = NULL, const string& s = "")
    :  Cell(suc), name(s){}

    // Access methods:
    void  setName(const string& s){ name = s; }
    const string& getName() const { return name; }

    void display() const 
    { 
       cout << "\n----------------------------"
            << "\nName:    " << name << endl; 
    }
};

class DerivedEl : public BaseEl
{
  private:
    string rem;

  public:
    DerivedEl(Cell* suc = NULL,  const string& s="", const string& r="") 
    : BaseEl(suc, s), rem(r){ }
    // Access methods:
    void  setRem(const string& r){ rem = r; }
    const string& getRem() const { return rem; }

    void display() const
    {
       BaseEl::display(); 
       cout << "Remark:  " << rem << endl;
    }
};

#endif
