// -------------------------------------------------------
// telList.h
// A class TelList to represent a list
// containing names and telephone numbers. 
// The methods load(), save() and saveAs() serve for
// loading and saving a telephone list.
// --------- ---------------------------------------------

#ifndef _TelList_
#define _TelList_

#include <string>
using namespace std;

#define PSEUDO -1          // Pseudo position
#define MAX 100            // Maximal number of elements
 
// Type of a list element:
struct Element { string name, telNr; };  

class TelList
{
  private:
    Element v[MAX];        // The array and the current
    int count;             // number of elements.

    string filename;       // File name 
    bool dirty;            // true, if data changed
                           // and not yet saved. 
  public:
    TelList() : count(0), filename(""), dirty(false)
    {}

    int getCount() { return count; }

    Element *retrieve( int i )
    { 
       return (i >= 0 && i < count)? &v[i] : NULL;
    }

    bool append( const Element& el )
    { 
       return append( el.name, el.telNr);
    }
    bool append( const string& name, const string& telNr);

    bool erase( const string& name);

    int  search( const string& name) const;
    
    void print() const;
    int  print( const string& name) const;

    int  getNewEntries();

    const string& getFilename() const { return filename; }
    bool setFilename( const string& fn) 
    {  
        if(fn.empty())
            return false;
        else
        {
            filename = fn;  dirty = true;
            return true;
        }
    }

    bool isDirty() { return dirty; }
    bool load();
    bool save();
    bool saveAs();
};

#endif  // _TelList_
