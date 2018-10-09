// prior_t.cpp : Testing a Priority Queue
// -------------------------------------------------
#include <queue>
#include <string>
#include <iostream>
using namespace std;

class Parcel
{
  private:
    unsigned int prio;                 // Priority
    string info;

  public:
    Parcel(unsigned int p, const string& s)
    : prio(p), info(s) {}

    // Access methods, ... overloaded operators:
    friend bool operator<(const Parcel& x,const Parcel& y)
    { return (x.prio < y.prio); }

    friend ostream& operator<<(ostream& os, const Parcel& x)
    { os << x.prio << "  "<<  x.info;  return os; }
};

int main()
{
   priority_queue<Parcel>  pq;

   pq.push(Parcel(7,"Bob"));      // Insert
   pq.push(Parcel(1,"Peter"));
   pq.push(Parcel(4,"Susan"));
   
   while( !pq.empty() )
   {  
     cout << pq.top() << endl;    // Output
     pq.pop();                    // and delete
   }
   return 0;
}

// Output:   7  Bob
//           4  Susan
//           1  Peter
