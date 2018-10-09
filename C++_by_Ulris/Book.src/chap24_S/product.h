// ----------------------------------------------------
// product.h : Defines the classes 
//             Product, PrepackedFood and FreshFood
// ----------------------------------------------------

#ifndef _PRODUCT_H
#define _PRODUCT_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Product
{
  private:
    long   bar;
    string name;

  public:
    Product(long b = 0L, const string& s = "")
    : bar(b), name(s)
    {  }
    void setCode(long b) { bar = b; }
    long getCode() const { return bar; }

    void  setName(const string& s){ name = s; }
    const string& getName() const { return name; }

    void scanner()
    {
       cout << "\nBarcode:     "; cin >> bar;
       cout <<   "Name:        "; cin >> name;
       cin.sync(); cin.clear();
    }

    void printer() const
    { 
       cout << "\n-------------------------------"
            << "\nBarcode:    " << bar
            << "\nName:       " << name
            << endl;
    }
};

class PrepackedFood : public Product
{
  private:
    double pce_price;
 
  public:
    PrepackedFood(double p = 0.0,long b = 0L, 
                  const string& s = "")
    : Product(b, s), pce_price(p)
    {}
    void   setPrice(double p){ pce_price = p;}
    double getPrice()const   { return pce_price; }
    void scanner()
    {   Product::scanner();
        cout << "Price per piece:    ";  cin >> pce_price;
    }
    void printer() const
    {  
        Product::printer();
        cout << fixed << setprecision(2)
             << "Price per piece:    " << pce_price << endl;
    }
};

class FreshFood : public Product
{
  private:
    double wght;
    double lbs_price;

  public:
    FreshFood(double g = 0.0, double p = 0.0,
                 long b = 0L, const string& s = "")
    : Product(b, s), wght(g), lbs_price(p) {}
    void   setWght(double g) { wght = g;} 
    double getWght()const    { return wght; }
    void   setPrice(double p) { lbs_price = p;} 
    double getPrice()const    { return lbs_price; }
    void scanner()
    {   Product::scanner();
        cout << "Weight(lbs):  "; cin >> wght;
        cout << "Price/lbs:    "; cin >> lbs_price;
        cin.sync(); cin.clear();
    }
    void printer() const
    { 
       Product::printer();
       cout << fixed << setprecision(2)
            <<   "Price per Lbs: " << lbs_price
            << "\nWeight:        " << wght
            << "\nTotal:         " << lbs_price * wght
            << endl;
    }
};

#endif
