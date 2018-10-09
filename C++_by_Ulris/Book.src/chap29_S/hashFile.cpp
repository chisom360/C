// --------------------------------------------------------
// hashFile.cpp : Methods of classes HashEntry and HashFile
// --------------------------------------------------------
#include "hashFile.h"

fstream& HashEntry::write(fstream& f)
{
    f.write((char*)&nr, sizeof(nr) );
    f.write( name, sizeof(name) );
    return f;
}

fstream& HashEntry::read(fstream& f)
{
    f.read((char*)&nr, sizeof(nr) );
    f.read( name, sizeof(name)); 
    return f;
}

fstream& HashEntry::write_at(fstream& f, unsigned long pos)
{
    f.seekp(pos);
    f.write((char*)&nr, sizeof(nr) );
    f.write( name, sizeof(name) );
    return f;
}

fstream& HashEntry::read_at(fstream& f, unsigned long pos)
{
    f.seekg(pos);
    f.read((char*)&nr, sizeof(nr) );
    f.read( name, sizeof(name)); 
    return f;
}

HashFile::HashFile(const string file, unsigned long n) 
                                          throw(OpenError)
{ 
   ios::openmode mode =  ios::in | ios::out | ios::binary;
   f.open(file.c_str(), mode);    // Open file if it
                                  // already exists.
   if(!f)                         // If file doesn't exist:
   {   
      f.clear();
      mode |= ios::trunc;
      f.open(file.c_str(), mode);
      if(!f)
         throw OpenError(name);
   }
   name = file;
   b = n;
   HashEntry rec(0L, "");
   f.seekp(0L);
   for( unsigned long i=0; i < b; i++) // Initialize 
   {                                   // the address space
      rec.write(f);
      if(!f) 
        throw WriteError(name);
   }
}

void HashFile::insert( HashEntry& rec) throw( ReadError, WriteError)
{
    HashEntry temp;       
    int  size = temp.getSize();
    // Hash value:
    unsigned long pos = hash_func(rec.getNr());

    temp.read_at(f, pos*size);         // Read a slot.
    if(!f)
       throw ReadError(name);
    else
    {
       if(temp.getNr() == 0L)          // Slot free?   
           rec.write_at(f, pos*size);  // Yes => Add
                                       // to the file. 
       else                            // No => Search for
       {                               // a free slot.
          bool found = false; 

          unsigned long p = (pos*size + size)%(b*size);

          while( !found && p!= pos*size  )
          {   
             temp.read_at(f, p); 
             if(!f)
                throw ReadError(name);
             else 
                if(temp.getNr() == 0L)  // Free slot
                    found = true;       // found.
                 else
                    // Proceed to the next slot:
                    p = (p + size)%(b*size);  
          }

          if( p == pos*size )        // Address space full.
              throw WriteError(name);
   
          if ( found == true )       // Add to file.
              rec.write_at(f,p);
       }
 
       if(!f)
           throw WriteError(name);
    }
}

HashEntry& HashFile::retrieve( unsigned long key ) throw(ReadError)
{
   static HashEntry temp; 
   int size = temp.getSize();

   unsigned long pos = hash_func(key);    // Hash value.

   temp.read_at(f, pos*size);             // Read a slot.

   if(!f) throw ReadError(name);

   if(temp.getNr() == key)                // Found?
      return temp;                        // Yes  => finish
   else                                   // No   => search
   {
     unsigned long p = (pos*size + size)%(b*size);
     while( p!= pos *size )
     {
        temp.read_at(f, p); 
        if(!f)
           throw ReadError(name);
        else 
           if(temp.getNr() == key)      // Record found.
              return temp;
           else
              p = (p + size)%(b*size);  // Proceed to the 
     }                                  // next slot.

     temp.setNr(0L); temp.setName("");  // Key doesn't 
                                        // exist.
     return temp; 
   }
}

void HashFile::display()
{
    HashEntry temp;
    f.seekg(0L);
 
    for(unsigned int i = 0; i < b; i++)
    {
        temp.read(f);
        if(!f)
            throw ReadError(name);
        temp.display();
    }
    f.clear();
}
