// ----------------------------------------------------
// ----------------------------------------------------
// article.h 
// Defines a simple class, Article.
// ----------------------------------------------------
#ifndef _ARTICLE_
#define _ARTICLE_

#include <string>
using namespace std;

class Article
{
  private: 
    long nr;                // Article number
    string name;            // Article name
    double sp;              // Selling price

  public:
    Article( long nr=0, const string& name="noname",
             double sp=0.0);
    ~Article();
    void print();

    const string& getName() const { return name; }
    long          getNr()   const { return nr; }
    double        getSP()   const { return sp; }
 
    bool setName( const string& s)
    {
       if( s.size() < 1)              // No empty name
         return false;
       name = s;
       return true; 
    }

    void setNr( long n) { nr = n; }
    void setSP(double v)
    {                                 // No negative price
       sp = v > 0.0 ? v : 0.0; 
    }
};

#endif   // _ARTICLE_ 
