/*
   An array with bounds checking.
   
   Assignment creates duplicate and deletes old
   array of values. (Memory leak.)
*/
#include <iostream>
#include <cstdlib>
using namespace std;

class safe_array
{
    float *ptr;
    int size;

  public:
    safe_array(int length);
    safe_array(const safe_array &param);
    ~safe_array() { delete[] ptr; }
    float &operator[](int index);
    safe_array &operator=(const safe_array &operand2);

    int getSize() const;
};

safe_array::safe_array(int length)
{
    ptr = new float[size = length];
}

safe_array::safe_array(const safe_array &param)
{
    ptr = new float[size = param.size];
    for (int i = 0; i < size; i++)
        ptr[i] = param.ptr[i];
}

safe_array &safe_array::operator=(const safe_array &operand2)
{
    if (this != &operand2)
    {
        delete[] ptr;
        ptr = new float[size = operand2.size];
        for (int i = 0; i < size; i++)
            ptr[i] = operand2.ptr[i];
    }
    return *this;
}

float &safe_array::operator[](int index)
{
    if (index < 0 || size - 1 < index)
        abort();
    return ptr[index];
}

int safe_array::getSize() const
{
    return size;
}

int main()
{
    int i;
    safe_array ar(5);
    safe_array ar2(7);

    for (i = 0; i < ar.getSize(); i++)
        ar[i] = i * 0.3;

    for (i = 0; i < ar2.getSize(); i++)
        ar2[i] = i * 10.4;

    for (i = 0; i < ar.getSize(); i++) // display array ar
        cout << "ar[" << i << "] = " << ar[i] << endl;
    cout << endl;

    for (i = 0; i < ar2.getSize(); i++) // display array ar2
        cout << "ar2[" << i << "] = " << ar2[i] << endl;
    cout << endl;

    ar2 = ar;

    for (i = 0; i < ar2.getSize(); i++) // display array ar2
        cout << "ar2[" << i << "] = " << ar2[i] << endl;
    cout << endl;

    for (i = 0; i < ar.getSize(); i++) // alter array ar
        ar[i] = i * 11.5;

    for (i = 0; i < ar.getSize(); i++) // display array ar
        cout << "ar[" << i << "] = " << ar[i] << endl;
    cout << endl;

    for (i = 0; i < ar2.getSize(); i++) // display array ar2
        cout << "ar2[" << i << "] = " << ar2[i] << endl;

    return 0;
}
