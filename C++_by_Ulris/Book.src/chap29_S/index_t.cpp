// ------------------------------------------------------
// index_t.cpp : Testing the index file
// ------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

#include "index.h"
#include "account.h"

int main()
{
  try
  {
    IndexFileSystem database("AccountTest");

    Account acc1( "Vivi", 490UL, 12340.57);
    database.insert( acc1 );

    SavAcc acc2( "Ulla", 590UL, 4321.19, 2.5);
    database.insert( acc2 );

    DepAcc acc3( "Jeany", 390UL, 12340.20, 10000.0, 12.9);
    database.insert( acc3 );

    database.IndexFile::display();
    cin.get();

    database.AccFile::display();

    unsigned long key;
    cout << "Key? ";  cin >> key;
    if(database.search(key) != -1)
        cout << "Key " << key << " found" << endl;
    else
        cout << "Key " << key << " not found" << endl; 
    
    Account* pAcc = database.retrieve(key);
    if( pAcc  != NULL )
    {
        pAcc->display();
        delete pAcc;
        pAcc = NULL;
    }
    else cout << "Retrieving failed" << endl;
  }
  catch(OpenError& err)
  {
      cerr << "Error on opening the file:" << err.getName() << endl;
      exit(1);
  }
  catch(WriteError& err)
  {
      cerr << "Error on writing into the file: " << err.getName() << endl;
      exit(1);
  }
  catch(ReadError& err)
  {
      cerr << "Error on reading from the file: " << err.getName() << endl;
      exit(1);
  }

  catch(...)
  {
      cerr << " Unhandled Exception" << endl;
      exit(1);
  }

  return 0;
}
