// ------------------------------------------------------
// index.cpp : Methods of the classes
//             IndexEntry, IndexFile, and IndexFileSystem
// ------------------------------------------------------

#include "index.h"

fstream& IndexEntry::write_at(fstream& ind, long pos) const
{
   ind.seekp(pos);
   ind.write((char*)&key, sizeof(key) );
   ind.write((char*)&recPos, sizeof(recPos) );

   return ind;
}

fstream& IndexEntry::read_at(fstream& ind, long pos)
{
   ind.seekg(pos);
   ind.read((char*)&key, sizeof(key) );
   ind.read((char*)&recPos, sizeof(recPos)); 

   return ind;
}

fstream& IndexEntry::write(fstream& ind) const
{
   ind.write((char*)&key, sizeof(key) );
   ind.write((char*)&recPos, sizeof(recPos) );

   return ind;
}
 
fstream& IndexEntry::read(fstream& ind)
{
   ind.read((char*)&key, sizeof(key) );
   ind.read((char*)&recPos, sizeof(recPos)); 
   
   return ind;
}

// Methods of class IndexFile
// ---------------------------------------------------
IndexFile::IndexFile(const string& file) throw (OpenError)
{ 
   ios::openmode mode =  ios::in | ios::out | ios::binary;
                         // Open file if it already exists:
   index.open(file.c_str(), mode);
   
   if(!index)           // If the file doesn't exist
   {   
       index.clear();
       mode |= ios::trunc;
       index.open(file.c_str(), mode);
       if(!index)
          throw OpenError(name);
   }
   name = file;
}

void IndexFile::display() throw(ReadError)
{
    IndexEntry entry;
    
    index.seekg(0L);
    
    if(!index)
       throw ReadError("IndexFile : Setting the get pointer");
    
    cout << endl << "The Index: " << endl;
    while( true)
    {
       if( !entry.read(index))
           break;
       entry.display();
    }
    if( !index.eof())
        throw ReadError(name);
    index.clear(); 
}

long IndexFile::search(long k) throw(ReadError)
{
   IndexEntry entry;
   long key;
   long  mid, begin = 0, end;     // Number of file records.
   int size = entry.recordSize(); // Length of an index entry.

   index.clear(); 
   index.seekg(0L, ios::end);
   end = index.tellg() / size;

   if(!index)
         throw ReadError(name);
 
   if( end == 0)
       return -1;

   end -= 1;                      // Position of the last entry

   while( begin < end )
   {
       mid = (begin + end +1)/2 ;

       entry.read_at(index, mid*size);
       
       if(!index)
         throw ReadError(name);
      
       key = entry.getKey();
       if( k < key)
           end = mid - 1;
       else 
           begin = mid;
   }  
    
   entry.read_at(index, begin * size);
   if(!index)
         throw ReadError(name);
          
   if ( k == entry.getKey() )      // Key found?     
       return begin * size;
   else return -1;               
}

void IndexFile::insert(long k, long n) 
     throw(ReadError, WriteError)
{
   IndexEntry entry;
   int size = entry.recordSize();  // Length of an index entry.

   index.clear();
   index.seekg(0, ios::end);
   long nr = index.tellg();        // Get file length
                                   // 0, if file is empty.
   if(!index) throw ReadError(name);

   nr -= size;                        // Last entry.
   bool found = false;
   while( nr >= 0 && !found )         // Searching position
   {                                  // to insert
     if(!entry.read_at(index, nr))
       throw ReadError(name);
      
     if( k < entry.getKey())          // To shift.
     {
       entry.write_at(index, nr + size);
       nr -= size;
     }
     else                             // To insert.
     {
       found = true;
     }
   }

   entry.setKey(k); entry.setPos(n);  // Insert
   entry.write_at(index, nr + size);

   if(!index)
     throw WriteError(name);
}


void IndexFile::retrieve( IndexEntry& entry, long pos)
     throw(ReadError)
{
    index.clear();    
    if(!entry.read_at(index, pos))
        throw ReadError(name);
}


//  Implementing the methods of class IndexFileSystem.
// ---------------------------------------------------
bool IndexFileSystem::insert(Account& acc)
     throw(ReadError, WriteError)
{
  if(search(acc.getNr()) == -1)          // No multiple entries.
  {
    long pos = append(acc);              // Add to primary file.

    IndexFile::insert(acc.getNr(), pos); // Insert in index file.

    return true;
  }
  else 
    return false;
}

Account* IndexFileSystem::retrieve(long key )
{
   // Get the record address from the index:
   long pos = search(key);    // Byte offset of index entry.  

   if( pos == -1 )            // Account number found?
      return NULL;
   else
   {                
      IndexEntry entry;       // Read the index eintry:
      IndexFile::retrieve( entry, pos); 
                              // Read from primary file: 
      return AccFile::retrieve( entry.getPos()); 
   }
}
