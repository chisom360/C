/*     FILE: List2.cpp     */

/*
   The entire list can be passed as a parameter.
*/
#include <iostream>
#include <list>

using std::list;
using std::cout;

#include "Student8.h"

void display_all(list<Student> cl)
{                // Entire list is passed in
  list<Student>::iterator iter;
  
  for(iter=cl.begin( ); iter != cl.end( ); iter++)
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
    
    display_all(class_list);      // Show the list    
    
    cout << "\n" 
         << "Display the list again: \n\n";
         
    display_all(class_list);    

    
    return 0;
}


/*    OUTPUT: List2.cpp

	Student name = Joe Cool
	Student gpa = 3.95
	Student id = 000000001
	Student name = Cool Joe
	Student gpa = 3.5
	Student id = 000000002
	Student name = Joe Llama
	Student gpa = 3.2
	Student id = 000000003
	
	Display the list again: 
	
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
