// coworker_t.cpp : Tests the classes
//                  Coworker, Laborer and Employee.
// -------------------------------------------------
#include "coworker.h"

// Demo Function:
void copy( Coworker& a, const Coworker& b ); 
 
int main()
{
    Employee porter("Bright, Paul", 2350.0);
    porter.display();
    cout << "\nIncome of the employee: "
         << porter.income() << endl;

    Employee substitute;
    copy(substitute, porter); 
    substitute.display();

    substitute = porter;        // Assignment not virtual
    cout << "\nAfter the assignment: ";
    substitute.display();
    cin.get();

    Laborer mason("Milo, Luis", 53.50, 40);
    mason.display();
    cout << "\nLaborer's income:   "
         << mason.income() << endl;

    Laborer apprentice;
    copy(apprentice, mason);
    cout << "\nIncome of the apprentice after copying: " 
         <<  apprentice.income()<< endl;

    apprentice.setWages(12.0);
    apprentice.setHr(20);
    mason = apprentice;         // Assignment not virtual

    cout << "\nMason's income after the assignment: "  
         << mason.income();
    mason.display();
    cin.get();

    cout << "\nAnd now with dynamic allocated storage: ";

    Coworker* felPtr[2];
    felPtr[0] = new Laborer("Young, Neil", 45., 40);
    felPtr[1] = new Employee("Smith, Eve", 3850.0);
 
    for( int i = 0; i < 2; ++i)
    {
      felPtr[i]->display();
      cout << "\nThe income of " << felPtr[i]->getName()
           << " :  " << felPtr[i]->income() << endl;
    }
    delete felPtr[0];
    delete felPtr[1];

    return 0;
}


void copy(Coworker& a,const Coworker& b)
{
    a = b;         // Calling the virtual Assignment
}
