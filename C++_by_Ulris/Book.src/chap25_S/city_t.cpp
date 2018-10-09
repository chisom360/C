// --------------------------------------------------
// city_t.cpp : Test the CityCar class
// --------------------------------------------------

#include "city.h"

char menu(void);
void getPassCar(string&, bool&, long&, string&);
void getTruck(int&, double&, long&, string&);

int main()
{
   CityCar carExpress;
   string tp, prod;
   bool   sr; 
   int    a;
   long   n;
   double t;

   // Two cars are already present:
   carExpress.insert(6, 9.5, 54321, "Ford");      
   carExpress.insert("A-class", true, 54320, "Mercedes");

   char choice;
   do
   {   choice = menu();
       switch( choice )
       {
         case 'Q': 
         case 'q': cout << "Bye Bye!"  << endl;
                   break;

         case 'P':
         case 'p': getPassCar(tp, sr, n, prod);
                   carExpress.insert(tp, sr, n, prod  );  
                   break;

         case 'T':
         case 't': getTruck(a, t, n, prod);
                   carExpress.insert(a, t, n, prod);  
                   break;

         case 'D':
         case 'd': carExpress.display();
                   cin.get();
                   break;

         default:  cout << "\a";     // Beep
                   break;
       }
   }while( choice != 'Q'  && choice != 'q');

   return 0;
}

char menu()                         // Input a command.
{
   cout << "\n  * * *  Car Rental Management * * *\n\n";

   char c;
   cout <<   "\n             P = Add a passenger car "
        <<   "\n             T = Add a truck "
        <<   "\n             D = Display all cars "
        <<   "\n             Q = Quit the program " 
        << "\n\nYour choice: ";
   cin >> c;

   return c;
}

void getPassCar(string& tp, bool& sr, long& n,string& prod)
{
   char c;
   cin.sync(); cin.clear();

   cout << "\nEnter data for passenger car:" << endl;
   cout << "Car type:          "; getline(cin, tp);
   cout << "Sun roof (y/n):    "; cin >> c;
   if(c == 'y' || c == 'Y')
       sr = true;
   else 
       sr = false;
   cout << "Car number:        "; cin >> n;
   cin.sync(); 
   cout << "Producer:          "; getline(cin, prod);
   cin.sync();
}

void getTruck(int& a, double& t, long& n, string& prod)
{
   cout << "\nInput data for truck:" << endl;
   cout <<   "Number of axles:     ";  cin >> a;
   cout <<   "Weight in tons:      ";  cin >> t;
   cout <<   "Car number:          ";  cin >> n;
   cin.sync(); 
   cout <<   "Producer:            "; getline(cin, prod);
   cin.sync(); 
}
