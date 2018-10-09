// Euro1.h : The class Euro containing arithmetic operators.
// ---------------------------------------------------------
#ifndef _EURO_H_
#define _EURO_H_

#include <sstream>             // The class stringstream
#include <iomanip>
using namespace std;

class Euro
{
  private: 
    long  data;                // Euros * 100 + Cents

  public:
    Euro( int euro = 0, int cents = 0)
    {
      data = 100L * (long)euro + cents;
    }

    Euro( double x)
    {
       x *= 100.0;                            // Rounding,
       data = (long)(x>=0.0 ? x+0.5 : x-0.5); // ex. 9.7 -> 10
    }

    long getWholePart() const { return data/100; }
    int  getCents() const { return (int)(data%100); }

    double asDouble() const { return (double)data/100.0; }

    string asString() const           // Euro as string.
    {
       stringstream strStream;        // Stream for conversion
       long temp = data;

       if( temp < 0) { strStream << '-';  temp = -temp; }

       strStream << temp/100 << ','
                 << setfill('0') << setw(2) << temp%100;
       return strStream.str();
    }

    void print( ostream os) const  // Output to stream os.
    {
       os << asString() << " Euro" << endl;
    }

    // ---- Operator functions ----
    Euro operator-() const        // Negation (unary minus))
    {
       Euro temp;
       temp.data = -data;

       return  temp;
    }

    Euro operator+( const Euro& e2) const   // Addition.
    {
       Euro temp;
       temp.data = data + e2.data;

       return  temp;
    } 

    Euro operator-( const Euro& e2) const   // Subtraction.
    { 
       Euro temp;
       temp.data = data - e2.data;

       return  temp;
    }

    Euro& operator+=( const Euro& e2)       // To add Euros.
    {
       data += e2.data;
       return  *this;
    } 

    Euro& operator-=( const Euro& e2)      // To subtract euros.
    {  
       data -= e2.data;
       return  *this;
    }
};

#endif   // _EURO_H_


