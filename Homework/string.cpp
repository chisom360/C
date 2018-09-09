
#include <iostream>
#include <cstring> // for strcpy_s
int main()
{
    char source[] = "Copy this!";
    char dest[50];
    strcpy(dest, source);
    std::cout << dest << std::endl; // prints "Copy this!"

    return 0;
}
