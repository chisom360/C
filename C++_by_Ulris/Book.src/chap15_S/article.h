// ----------------------------------------------------
// article.h 
// Defines a simple class - Article.
// ----------------------------------------------------
#ifndef _ARTICLE_H_
#define _ARTICLE_H_
#include <string>
using namespace std;

class Article
{
   private: 
     long nr;                  // Article number
     string name;              // Article name
     double sp;                // Sales price
   
     // Static data element:
     static int countObj;    // Number of objects


   public:
     Article( long nr=0, const string& name="noname",
              double sp=0.0);
     // Copy constructor:
     Article( const Article& einArticle); 
     ~Article();
     
     void print();
     
     // Access methods:
     const string& getName() const { return name; }
     long          getNr()   const { return nr; }
     double        getSP()   const { return sp; }
     static int getCount() { return countObj; }
     bool setName( const string& s)
     {
        if( s.size() < 1)        // No empty Name
          return false;
        name = s;
        return true; 
     }
     void setNr( long n) { nr = n; }
     void setSP(double v)
     {                            // No negative price
         sp = v > 0.0 ? v : 0.0;  
     }
};
#endif   // _ARTICLE_
