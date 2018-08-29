/*     FILE: cmdLine1.cpp     */

/* Program echoes all the command line arguments given. */

#include <iostream>
using std::cout;
using std::endl;


int main(int argc, char *argv[ ])
{
 int i;

 for(i=0; i<argc; i++)
   cout << "argv[" << i << "] = " << argv[i] << endl;

 return 0;
}


/*    OUTPUT: cmdLine1.cpp


   COMMAND LINE: cmdLine1 one two three

	argv[0] = cmdLine1
	argv[1] = one
	argv[2] = two
	argv[3] = three


   COMMAND LINE: cmdLine1 one 1 two 2 three 3

	argv[0] = cmdLine1
	argv[1] = one
	argv[2] = 1
	argv[3] = two
	argv[4] = 2
	argv[5] = three
	argv[6] = 3


   COMMAND LINE: cmdLine1 "Jim Polzin" "Teaches C++, sometimes."

	argv[0] = cmdLine1
	argv[1] = Jim Polzin
	argv[2] = Teaches C++, sometimes.

*/
