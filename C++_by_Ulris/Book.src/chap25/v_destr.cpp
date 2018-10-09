// v_destr.cpp
// Base class with a virtual destructor.
// Without a virtual destructor in the base class,
// the destructors of the derived classes 
// Derived and Data would not be performed.

// -----------------------------------------------------
#include <iostream>
#include <cstring>             // For strcpy()
using namespace std;

class Base
{
  public:
   Base()
   {  cout << "Constructor of class base\n"; }
   virtual ~Base()
   {  cout << "Destructor of class base\n"; }
};

class Data
{
  private:
    char *name;

  public:
    Data( const char *n)
    { cout << "Constructor of class Data\n";
      name = new char[strlen(n)+1];
      strcpy(name, n);
    }
    ~Data()
    { cout << "Destructor of class Data for "
           << "Object: " << name << endl;
      delete [] name;
    }
};

class Derived : public Base
{
  private:
    Data data;

  public:
    Derived( const char *n) : data(n)
    {  cout << "Constructor of class Derived\n";  }
    ~Derived()                // implizit virtuell
    {  cout << "Destructor of class Derived\n"; }
};

int main()
{
  Base *bPtr = new Derived("DEMO");

  cout << "\nCalling the virtual Destructor!\n";
  delete bPtr; 

  return 0;
}
