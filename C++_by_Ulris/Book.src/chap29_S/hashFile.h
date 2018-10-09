// -------------------------------------------------------
// hashFile.h
// Defines the classes 
// HashEntry representing a record in a hash file and
// HashFile representing a hash file.
// -------------------------------------------------------
#ifndef _HASH_H_
#define _HASH_H_

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h> 
using namespace std;

#include "exceptio.h"

class HashEntry
{
  private:
    unsigned long nr;
    char name[30];

  public:
    HashEntry(unsigned long n = 0L, const string& s = "")
    {  
       nr = n;
       setName(s);
    } 

    long   getNr() const { return nr; }
    void   setNr(unsigned long n){ nr = n; }
    string getName() const { return name; }
    void   setName(const string& s)
    {  strncpy(name, s.c_str(), 29); name[29]='\0'; }
  
    int getSize() const
    { return(sizeof(long) + sizeof(name)); }
  
    fstream& write(fstream& fs);
    fstream& read(fstream& fs);

    fstream& write_at(fstream& fs, unsigned long pos);
    fstream& read_at(fstream& fs, unsigned long pos); 
 
    virtual void display()
    { 
        cout << fixed << setprecision(2)
             << "----------------------------------\n"
             << "Client number:        " << nr    << endl
             << "Client:               " << name  << endl
//           << "----------------------------------\n"
             << endl;
//      cin.get();
    }
};

class HashFile
{
  private:
    fstream f;
    string  name;          // Filename
    unsigned long b;       // Size of address space 

  protected:
    unsigned long hash_func(unsigned long key)
    { return key % b; }

  public:
    HashFile(const string s, unsigned long n ) throw(OpenError);

    void insert( HashEntry& rec)  throw( ReadError, WriteError);

    HashEntry& retrieve( unsigned long key ) throw( ReadError);

    void display();
};

#endif
