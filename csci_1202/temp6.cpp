/*     FILE: temp6.cpp     */

// Class stack is templatized.  Testing internal safe_array.
#include <iostream>
using std::cout;
using std::endl;

#include "stack_t.h"

int main( )
{
  stack<int> st(5);

  cout << "Pushing:\n";
  for(int i=0; i<5; i++){
     st.push(i);
     cout << i << endl;
  }

  cout << "\nPop-ing:\n";
  for(int i=0; i<5; i++)   // display stack contents
     cout << st.pop( ) << endl;

  stack<float> st2(5);

  cout << "\n\nPushing:\n";
  for(int i=0; i<5; i++){
     st2.push(i*.3);
     cout << i*0.3 << endl;
  }

  cout << "\nPop-ing:\n";
  for(int i=0; i<5; i++)   // display stack contents
     cout << st2.pop( ) << endl;

  cout << st.pop( ) << endl;   // underflow stack

  return 0;
}



/*    OUTPUT: temp6.cpp

	Pushing:
	0
	1
	2
	3
	4
	
	Pop-ing:
	4
	3
	2
	1
	0
	
	
	Pushing:
	0
	0.3
	0.6
	0.9
	1.2
	
	Pop-ing:
	1.2
	0.9
	0.6
	0.3
	0
	
	abnormal program termination

*/
