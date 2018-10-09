// funcptr.cpp:  Demonstrates the use of an array 
//               of pointers to functions.
// --------------------------------------------------
#include  <iostream> 
#include  <cstdlib>    // Prototype of atoi()
#include  <cctype>     // Macros  toupper(), tolower()
using namespace std;

void  error_message(char *), message(char *),
      message_up(char *), message_low(char *);

void (*functab[])(char *) = { error_message, message, 
                              message_up, message_low };

char call[]="Input: 1,2 or 3";

int main()
{
   int n = 0;
   cout << "Which of the three functions "
        << "do you want call (1,2 or 3)?\n";
   cin >> n;

   if( n<1 || n>3)
     (*functab[0])( call );
    else
     (*functab[n])("Hello, world\n");
    return 0;
}

void error_message( char *s)  {  cerr << s << endl; }

void message( char *s)       {  cout << s << endl; }

void message_up( char *s)
{   int c;
    for( ; *s != '\0';++s) c = toupper(*s),cout.put(c);
}

void message_low( char *s)
{   int c;
    for( ; *s != '\0';++s) c = tolower(*s), cout.put(c);
}
