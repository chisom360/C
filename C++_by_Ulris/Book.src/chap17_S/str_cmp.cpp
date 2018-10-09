// -------------------------------------------------------
// str_cmp.cpp
// To define and test the pointer version str_cmp() 
// of the standard function strcmp().
// -------------------------------------------------------
#include <iostream>
using namespace std;

#define MAXLEN 100       // Maximal length of the C-strings

// Prototyp:
int str_cmp( const char* str1, const char* str2);

int main()                              // Test str_cmp()
{
    char text1[MAXLEN], text2[MAXLEN]; 

    cout << "Testing the function str_cmp()" << endl;
    
    while( true)
    {
       cout << "Enter two lines of text!\n"
               "End with two empty lines.\n" << endl;
    
       cout << "1. line: ";
       cin.sync();  cin.clear();  cin.get(text1,MAXLEN);
       
       cout << "2. line: ";
       cin.sync();  cin.clear();  cin.get(text2,MAXLEN);
       
       if( text1[0] == '\0' && text2[0] == '\0')
           break;                    // Both lines empty.
       
       int cmp = str_cmp( text1, text2);
       
       if( cmp < 0)
           cout << "The 1. string is smalller!\n";
       else if( cmp == 0)
           cout << "Both strings are equal!\n";
       else
           cout << "The 1. string is greater!\n";
       cout << endl;
    }
    
    return 0;
}

// ------------------------------------------------------
// Function str_cmp()
// Pointer version of the standard function strcmp().
// ------------------------------------------------------
int str_cmp( const char* str1, const char* str2)
{
   for( ; *str1 == *str2 && *str1 != '\0'; ++str1, ++str2)
     ;
   
   return (*str1 - *str2);
}


