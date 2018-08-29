/*     FILE: Map2.cpp     */

/*
   The map container also provides iterators.
*/
#include <map>
using std::map;
using std::make_pair;

#include "Student8.h"

void display_all(map<long,Student>::iterator start, map<long,Student>::iterator end)
{
  map<long,Student>::iterator iter;
  
  for(iter=start; iter != end; iter++)
     (*iter).second.display( );
    
  return;
	
}

int main( ) 
{
    map<long,Student> class_map;
    Student s("Joe Cool", 3.95), 
            s2("Cool Joe", 3.5), 
            s3("Joe Llama", 3.2);
    
    class_map.insert(make_pair(s.getId( ),s));  // maps require insertion of "pairs"
    class_map.insert(make_pair(s2.getId( ),s2));
    class_map.insert(make_pair(s3.getId( ),s3));
    
    display_all(class_map.begin( ), class_map.end( ));    
    return 0;
}



/*    OUTPUT: Map2.cpp

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
