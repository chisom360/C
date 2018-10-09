// -------------------------------------------------------
// TelList.cpp 
// Implements the methods of class TelList.
// -------------------------------------------------------
#include "telList.h"      // Definition of class TelList 
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

bool TelList::append( const string& name,    
                      const string& telNr)
{
    if( count < MAX                 // Any space
        && name.length() > 1        // minimum 2 characters
        && search(name) == PSEUDO)  // does not exist
    {
      v[count].name  = name;
      v[count].telNr = telNr;
      ++count;
      dirty = true;
      return true;
    }
    return false;
}

bool TelList::erase( const string& key )
{
   int i = search(key);
   if( i != PSEUDO )
   {   
     if( i != count-1)            // Copy the last element 
         v[i] = v[count-1];       // to position i.
     --count;
     dirty = true;
     return true;
   }
   return false;
}

int TelList::search( const string& key )  const
{
   for( int i = 0; i < count; i++ )        // Searching.
     if( v[i].name == key )
       return i;                           // Found

   return PSEUDO;                          // Not found
}

// Functions to support the output:
inline void tabHeader()              // Title of the table
{
   cout << "\n  Name                        Telephone #\n"
           "----------------------------------------------"
        << endl;
}
inline void printline( const Element& el)
{
   cout << left << setw(30) << el.name.c_str()
        << left << setw(20) << el.telNr.c_str()
        << endl;
}

void TelList::print() const        // Outputs all entries
{
   if( count == 0)
      cout << "\nThe telephone list is empty!" << endl;
   else
   {
      tabHeader(); 
      for( int i = 0; i < count; ++i)
          printline( v[i]);
   }
}

int TelList::print( const string& name) const   // Entries 
{                                   // beginning with name.
   int matches = 0, len = name.length();
   
   for( int i = 0; i < count; ++i)
   {
      if( v[i].name.compare(0, len, name) == 0)
      {
        if( matches == 0) tabHeader();  // Title before
                                        // first output. 
        ++matches;
        printline( v[i]);
      }
   }
   if( matches == 0)
      cout << "No corresponding entry found!" << endl;

   return matches;
}

int TelList::getNewEntries()        // Input new entries
{
    int inputCount = 0;
    cout << "\nEnter new names and telephone numbers:"
            "\n(Terminate by empty input) "  
         << endl;
    Element el;
    while( true)
    {
      cout << "\nNew last name, first name:  "; 
      cin.sync(); getline( cin, el.name);
      if( el.name.empty())
        break;
      cout << "\nTelephone number: "; 
      cin.sync(); getline( cin, el.telNr);

      if( !append( el))
      {
         cout << "Name has not been inserted!" << endl;
         if( count == MAX)
         {
            cout << "The Table is full!" << endl;
            break;
         }
         if( search( el.name) != PSEUDO)
            cout << "Name already exists!" << endl;
      }
      else
      {
         ++inputCount;
         cout << "A new element has been inserted!" 
              << endl;
      }
    }
    return inputCount;
}

// Methods for loading and saving the telephone list.

bool TelList::load()
{
   cout << "\n--- Load the telephone list "
        << "from a file. ---" << "\nFile: ";

   string file;                      // Input file name.
   cin.sync(); cin.clear();          // No previous input
   getline( cin, file);
   if( file.empty())
   {
      cerr << "No filename declared!" << endl;
      return false;
   }
 
// Open the file for reading:
   ifstream infile( file.c_str(), ios::in | ios::binary);
   if( !infile )
   {
      cerr << "File " << file 
           << " could not be opened!" << endl;
      return false;
   }

   int i = 0; 
   while( i < MAX)
   {
      getline( infile, v[i].name, '\0');
      getline( infile, v[i].telNr, '\0');
      if( !infile)
         break;
      else
         ++i;
   }

   if( i == MAX)
      cerr << "Max capacity " << MAX
           << " has been reached!" << endl;
   else if( !infile.eof())
   {
      cerr << "Error reading file " << file << endl;
      return false;
   }

   count = i;
   filename = file;
   dirty = false;

   return true;
}

bool TelList::saveAs()
{
   cout << "-- Save the telephone list in a file. --"
        << "\nFile: ";
   string file;                    // Input file name.
   cin.sync(); cin.clear();        // No previous input
   getline( cin, file);
   if( !setFilename(file))
   {
      cerr << "No file name declared!" << endl;
      return false;
   }
   else
     return save();
}

bool TelList::save()      // Save the telephone list.
{
   if( filename.empty())
      return saveAs();
   if( !dirty)
       return true;

   ofstream outfile( filename.c_str(),
                     ios::out | ios::binary);
   if( !outfile )
   {
      cerr << "File " << filename 
           << " could not be opened!" << endl;
      return false;
   }

   int i = 0;
   while( i < count)
   {
      outfile << v[i].name  << '\0';
      outfile << v[i].telNr << '\0';
      if( !outfile)
         break;
      else
         ++i;
   }
   if( i < count)
   {
      cerr << "Error writing to file " << filename << endl;
      return false;
   }

   dirty = false;
   return true;
}
