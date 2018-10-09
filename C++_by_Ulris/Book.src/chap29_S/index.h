// ----------------------------------------------------------
// index.h: Contains definitions of classes
//          IndexEntry      representing an index entry,
//          IndexFile       representing the index and
//          IndexFileSystem representing an index file system.
// ----------------------------------------------------------
#ifndef _INDEX_H
#define _INDEX_H

#include <fstream>
#include <iostream>
#include <string>
#include "account.h"
using namespace std;

class IndexEntry
{  
  private:
    long key;                 // Key
    long recPos;              // Offset

  public:
    IndexEntry(long k=0L, long n=0L){ key=k; recPos=n; }

    void setKey(long k) { key = k; }
    long getKey() const { return key; }
    void setPos(long p) { recPos = p; }
    long getPos() const { return recPos; }

    int recordSize() const { return sizeof(key) + sizeof(recPos); }

    fstream& write( fstream& ind) const;
    fstream& read(  fstream& ind);

    fstream& write_at(fstream& ind, long pos) const;
    fstream& read_at( fstream& ind, long pos);

    void display() const
    {
        cout << "Account Nr: " << key 
             << "  Position: " << recPos << endl;
    }
};
 
//  Adds the definition of an index
// --------------------------------------------------
class IndexFile
{
   private:
     fstream index;
     string  name;                  // Filename of index

   public:
     IndexFile( const string& s)  throw (OpenError);
     ~IndexFile() { index.close(); }
 
     void insert( long key, long pos) throw(ReadError, WriteError);
     long search( long key) throw(ReadError);
     void retrieve(IndexEntry& entry, long pos ) throw(ReadError);

     void display() throw(ReadError);
};

//  Defines the class IndexFileSystem
// ---------------------------------------------------
class IndexFileSystem : public AccFile, public IndexFile
{
   private:
     string name;               // Filename without suffix

   public:
     IndexFileSystem(const string& s)
     : AccFile(s + ".prim"), IndexFile(s + ".ind")
     { name = s;  }

    bool     insert( Account& acc);
    Account* retrieve( long key);
};

#endif
