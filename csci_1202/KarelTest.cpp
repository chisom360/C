/*     FILE: KarelTest.cpp     */

/*   This is a sample program illustrating how a "pseudo-object" 
     could be built using just structures and function pointers.
     
     This will prove that "class" definitions are much easier and
     less error-prone when creating classes of objects.
     
     The program utilizes Karel++ Robots as a model for a type
     of object.
*/

#include <iostream>

using std::cout;
using std::endl;

  struct ur_Robot{
    int st, ave;
    void (*move)(ur_Robot *);
    void (*print)(ur_Robot *);
  };
  
  void theMove(ur_Robot *r)
  {
    r->st++;
  }
  
  void thePrint(ur_Robot *r)
  {
    cout << "Street: " << r->st 
         << "  Avenue: " << r->ave << endl;
  }
  
  void init(ur_Robot *r)
  {
    r->move = theMove;
//    r->turnLeft = turnLeft;
//    r->turnOff = turnOff;
    r->print = thePrint;
//    r->on = true;
  }
  
  int main( )
  {
//    ur_Robot karel = {1,1,East,0};
    ur_Robot karel = {1,1,theMove, thePrint};
//    init(&karel);
  
    karel.print(&karel);
  
    karel.move(&karel);
    karel.move(&karel);
    karel.print(&karel);
    karel.move(&karel);
    karel.move(&karel);
    karel.print(&karel);
  
//    karel.turnLeft(&karel);
    karel.move(&karel);
//    karel.turnOff(&karel);
    karel.print(&karel);

    return 0;
  }


/*    OUTPUT: KarelTest.cpp

	Street: 1  Avenue: 1
	Street: 3  Avenue: 1
	Street: 5  Avenue: 1
	Street: 6  Avenue: 1

*/
