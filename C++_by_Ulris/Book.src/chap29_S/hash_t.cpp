// -------------------------------------------------------
// hash_t.cpp : Tests hash files
// -------------------------------------------------------

#include <iostream>
#include <string>
#include "hashFile.h"
using namespace std;

int main()
{
  try
  {
    HashFile hash("Client.fle", 7);       // Address space
                                          // of length 7 
    cout << "\nInsert: " << endl;
    HashEntry he( 3L, "Vivi");
    hash.insert( he ); 

    he.setNr(10L);  he.setName("Peter");
    hash.insert( he );

    he.setNr(17L);  he.setName("Alexa");
    hash.insert( he );

    he.setNr(21L);  he.setName("Peter");
    hash.insert( he );

    he.setNr(15L);  he.setName("Jeany");
    hash.insert( he );
    cout << "\nInsertion complete: " << endl;

    hash.display();

    unsigned long key;
    cout << "Key? ";  cin >> key;

    HashEntry temp = hash.retrieve(key);
    if(temp.getNr() != 0L)
       temp.display();
    else
       cout << "Key " << key 
            << " not found" << endl; 
  }
  catch(OpenError& err)
  {
     cerr << "Error in opening the file: " 
          << err.getName() << endl;
     exit(1);
  }
  catch(WriteError& err)
  {
     cerr << "Error writing to file: "
          << err.getName() << endl;
     exit(1);
  }
  catch(ReadError& err)
  {
     cerr << "Error reading from file: " 
          << err.getName() << endl;
     exit(1);
  }

  return 0;
}
