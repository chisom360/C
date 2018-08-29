/*     FILE: List.cpp     */

/*
   The list container also provides iterators.
*/
#include <list>
using std::list;

#include "Student8.h"

void display_all(list<Student>::iterator start, list<Student>::iterator end)
{                // A pair of iterators is passed in to mark the start and 
                 // ... end of the list to display
  list<Student>::iterator iter;
  
  for(iter=start; iter != end; iter++)
     (*iter).display( );
    
  return;
	
}

int main( ) 
{
    list<Student> class_list;    
    Student s("Joe Cool", 3.95), 
            s2("Cool Joe", 3.5), 
            s3("Joe Llama", 3.2);
    
    class_list.push_back(s);      // Add to the back  
    class_list.push_back(s2);
    class_list.push_back(s3);
    
    display_all(class_list.begin( ), class_list.end( ));   
                                  // Show the list
    return 0;
}


/*    OUTPUT: List.cpp

	Student name = Joe Cool
	Student gpa = 3.95
	Student id = 000000001
	Student name = Cool Joe
	Student gpa = 3.5
	Student id = 000000002
	Student name = Joe Llama
	Student gpa = 3.2
	Student id = 000000003

*/
