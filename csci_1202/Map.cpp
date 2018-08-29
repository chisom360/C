/*     FILE: Map.cpp     */

/*
  The map container allows for rapid retrieval of a data value by a "key"
  field. It only allows one data value per key.
*/
#include <map>
using std::map;
using std::make_pair;

#include "Student8.h"

int main( ) 
{
    map<long,Student> class_map;
    Student s("Joe Cool", 3.95), 
            s2("Cool Joe", 3.5), 
            s3("Joe Llama", 3.2);
    
    class_map.insert(make_pair(s.getId( ),s)); // maps require insertion of "pairs"
    class_map.insert(make_pair(s2.getId( ),s2));
    class_map.insert(make_pair(s3.getId( ),s3));
    
    Student selected = class_map[Student::getCount( )-1];

    selected.display( );
    
    return 0;
}



/*    OUTPUT: Map.cpp

	Student name = Cool Joe
	Student gpa = 3.5
	Student id = 000000002

*/
