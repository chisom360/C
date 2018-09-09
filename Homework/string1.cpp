#include <iostream>
#include <cstring>

int main()
{
    char name[20] = "Alex"; // only use 5 characters (4 letters + null terminator)
    std::cout << "My name is: " << name << '\n';
    std::cout << name << " has " << strlen(name) << " letters.\n";
    std::cout << name << " has " << sizeof(name) / sizeof(name[0]) << " characters in the array.\n";

    return 0;
}
