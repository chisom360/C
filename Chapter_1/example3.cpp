#include <iostream>
#include <string>
#include <sstream>

#define discount 0.1;
using namespace std;

int main()
{
    double totalPrice, discountedAmount;
    int quantity, price;
    string myString;

    cout << "Enter the quantity of item purchased: ";
    getline(cin, myString);
    stringstream(myString) >> quantity;
    cout << "Enter the price of item purchased: ";
    getline(cin, myString);
    stringstream(myString) >> price;

    if ((quantity * price) >= 5000)
    {
        discountedAmount = (quantity * price) * discount;
        totalPrice = (quantity * price) - discountedAmount;
        cout << "Your total is " << totalPrice << endl;
    }
    else
    {
        cout << "Your total is " << (quantity * price) << endl;
    }

    return 0;
}