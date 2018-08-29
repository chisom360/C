/*     FILE: List3.cpp     */

/*
   New elements can be inserted into the list.
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
    list<Student>::iterator iter;
    
     
    Student s("Joe Cool", 3.95), 
            s2("Cool Joe", 3.5), 
            s3("Joe Llama", 3.2);
    
    class_list.push_front(s);     // Add to the front
    class_list.push_front(s2);
    class_list.push_front(s3);
    
    display_all(class_list);      // Show the list
    
    iter = class_list.begin( );   // Find a spot in
    iter++;                       // ... the list
    
    class_list.insert(iter, Student("John Doe", 3.75));
                                  // Insert an element 
    cout << "\n" 
         << "Display the list again: \n\n";
         
    display_all(class_list);      // Show the list
    
    return 0;
}


/*    OUTPUT: List3.cpp

	Student name = Joe Llama
	Student gpa = 3.2
	Student id = 000000003
	Student name = Cool Joe
	Student gpa = 3.5
	Student id = 000000002
	Student name = Joe Cool
	Student gpa = 3.95
	Student id = 000000001
	
	Display the list again: 
	
	Student name = Joe Llama
	Student gpa = 3.2
	Student id = 000000003
	Student name = John Doe
	Student gpa = 3.75
	Student id = 000000004
	Student name = Cool Joe
	Student gpa = 3.5
	Student id = 000000002
	Student name = Joe Cool
	Student gpa = 3.95
	Student id = 000000001

*/
