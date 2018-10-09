// safe.h : The classes Safe and Castle
// ---------------------------------------------------
#include <iostream>
using namespace std;

class Safe
{
   private:
      int topSecret;
   protected:
      int  secret; 
      
      void setTopSecret( int n) { topSecret = n;}
      int  getTopSecret() const { return topSecret;}
      void setSecret( int n){ secret = n;}
      int  getSecret() const { return secret;}
   
   public:  
      int noSecret;
      Safe()
      { topSecret = 100; secret = 10; noSecret = 0; }
};

class Castle : public Safe
{
   public:
      Castle()
      {
         // topSecret = 10;      // Error, because private
         setTopSecret(10);       // ok, because protected
         secret = 1;             // ok, because protected
         noSecret = 0;           // ok, because public
      }

      void test()
      {
         // top.Secret = 200;    // Error, because private
         setTopSecret(200);      // ok, because protected
         secret = 20;            // ok, because protected
         noSecret = 2;           // ok, because public
      }

      void display()
      {
         cout << "\nTop secret: " << getTopSecret() 
              << "\nSecret:     " << secret
              << "\nNo secret:  " << noSecret
              << endl;
      }
};
