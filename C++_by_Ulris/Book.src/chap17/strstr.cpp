// strstr.cpp
// A self-defined version of the function strstr()
// ---------------------------------------------------
#include <string.h>       // For strlen() and strncmp()

namespace MyScope
{
  char *strstr( const char *s1, const char *s2) 
  {                   // To search for the string s2 within s1.
    int len = strlen( s2);

    for( ; *s1 != '\0'; ++s1)
       if( strncmp( s1, s2, len) == 0)  // s2 found?
         return (char *)s1;             // Yes -> return pointer 
                                        // to this position, or
    return NULL;                        // else the NULL pointer.
  }
}
