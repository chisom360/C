// ---------------------------------------------------
// Euro.h : The class Euro represents a euro.
// ---------------------------------------------------
#ifndef _EURO_H_
#define _EURO_H_

#include <sstream>        // The class stringstream
#include <iomanip>
using namespace std;

class Euro
{
  private:
   long  data;            // Euros * 100 + Cents

  public:
    Euro( int euro = 0, int cents = 0)
    {
       if( euro < 0)            // Euro(-1,20) == -1.20 Euro
          cents = -cents; 
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

    string asString() const             // Euro as string.
    {
       stringstream strStream;          // Stream for conversion
       long temp = data;

       if( temp < 0) { strStream << '-';  temp = -temp; }

       strStream << temp/100 << ','
                 << setfill('0') << setw(2) << temp%100;
       return strStream.str();
    }

    void print( ostream os) const      // Output to stream os.
    {
       os << asString() << " Euro" << endl;
    }

    // ---- Operator functions ----

    // For conversion from Euro to double:
    operator double() const { return (double)data/100.0; }

    Euro operator-() const             // Negation (unary minus))
    {
       Euro temp;
       temp.data = -data;

       return  temp;
    } 
    
    Euro& operator+=( const Euro& e2)    // To add Euros.
    {
       data += e2.data;
       return  *this;
    } 

    Euro& operator-=( const Euro& e2)    // To subtract Euros.
    {  
       data -= e2.data;
       return  *this;
    }

    // Division Euro / double :
    Euro operator/( double x)          // Division *this / x
    {                                  // =  *this * (1/x)
       return (*this * (1.0/x));
    }

    // Global friend functions
    friend Euro operator+( const Euro& e1, const Euro& e2);
    friend Euro operator-( const Euro& e1, const Euro& e2);
    friend Euro operator*( const Euro& e, double x) 
    {
       Euro temp( ((double)e.data/100.0) * x) ;
       return temp;
    }
    friend Euro operator*( double x, const Euro& e) 
    {
       return e * x;
    }
};

// Addition: 
inline Euro operator+( const Euro& e1, const Euro& e2)
{
    Euro temp;   temp.data = e1.data + e2.data;
    return  temp;
} 

// Subtraction:
inline Euro operator-( const Euro& e1, const Euro& e2)
{
    Euro temp;   temp.data = e1.data - e2.data;
    return  temp;
}
 
// --------------------------------------------------------------
// Declaration of Shift operators:

// To output to stream os.
ostream& operator<<(ostream& os, const Euro& e);

// To input from stream is.
istream& operator>>(istream& is, Euro& e);

#endif   // _EURO_H_
