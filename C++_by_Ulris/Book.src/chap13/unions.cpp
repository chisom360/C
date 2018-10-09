// unions.cpp 
// Defines and uses a union.
// ---------------------------------------------------
#include <iostream>
using namespace std;

union WordByte
{
  private:
    unsigned short w;         // 16 bits
    unsigned char b[2];       // Two bytes: b[0], b[1]

  public:                     // Word- and byte-access:
    unsigned short& word()    { return w; }
    unsigned char&  lowByte() { return b[0]; }
    unsigned char&  highByte(){ return b[1]; }
};

int main()
{
    WordByte wb;

    wb.word() = 256;

    cout << "\nWord:      " << (int)wb.word();
    cout << "\nLow-byte:  " << (int)wb.lowByte()
         << "\nHigh-byte: " << (int)wb.highByte()
         << endl;

    return 0;
}


/*
Output:

  Word:      256
  Low byte:  0
  High-byte: 1
*/
