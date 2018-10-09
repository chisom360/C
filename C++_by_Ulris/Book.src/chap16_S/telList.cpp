// ----------------------------------------------------
// telList.cpp 
// Implements the methods of class TelList.
// -----------------------------------------------------

#include "telList.h"      // Definition of class TelList 
#include <iostream>
#include <iomanip>
using namespace std;

bool TelList::append( const string& name,    
                      const string& telNr)
{
    if( count < MAX                // Space available
        && name.length() > 1       // 2 characters at least
        && search(name) == PSEUDO) // not yet existing
    {
      v[count].name  = name;
      v[count].telNr = telNr;
      ++count;
      return true;
    }
    return false;
}

bool TelList::erase( const string& key )     
{
   int i = search(key);
   
   if( i != PSEUDO )
   {                               // Copies the last 
     v[i] = v[count-1];  --count;  // element in position i
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
