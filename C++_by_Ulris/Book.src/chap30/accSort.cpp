// accSort.cpp: Sorts an array of pointers to accounts
//              according the account numbers
// ---------------------------------------------------

#include "account.h"

void accSort( Account** aptr, int n);

int main()
{
    Account* arrAccPtr[3];

    string name;
    long nr;
    double value;
    
    cout << "\nPlease, enter data for 3 accounts: " << endl;
    for(int i = 0; i < 3; i++)
    {
        cout << "\nName?           ";  cin >> name;
        cout <<   "Account number? ";  cin >> nr;
        cout <<   "Balance?        ";  cin >> value;
    
        arrAccPtr[i] = new Account(name, nr, value);
    }
    
    cin.sync();

    cout << "\n\n\nThe array: " << endl;
    for(i=0; i < 3; i++)
        arrAccPtr[i]->display();
    cout << endl;  cin.get();

    accSort(arrAccPtr, 3);

    cout << "\n\nThe sorted array: " << endl;
    for(i=0; i < 3; i++)
        arrAccPtr[i]->display();
    cout << endl;  cin.get();

    return 0;
}

void ptrSwap( Account**, Account** );

void accSort( Account** aptr, int n)
{
   Account **temp, **minp, **lastp;
   lastp = aptr + n - 1;    // Pointer to the last 
                            // pointer in the array.

   for(  ; aptr < lastp; ++aptr )
   {
     minp = aptr;
   
     for( temp = aptr + 1; temp <= lastp; ++temp )
     { 
       if( (*temp)->getNr() < (*minp)->getNr() )
           minp = temp; 
     }
     ptrSwap( aptr, minp );
   }
}

void ptrSwap( Account **p1, Account **p2 )
{
   Account *help;
   help = *p1; *p1 = *p2; *p2 = help;
}
