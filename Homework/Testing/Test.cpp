
/*#include <vector>
#include <iostream>
#include <algorithm>
int main()
{
    std::vector<std::pair<int, int>> v = {{1, 2}, {3, 4}, {5, 6}};
    auto p = std::make_pair(3, 4);

    if (std::find(v.begin(), v.end(), p) != v.end())
        std::cout << "yes\n";
}
*/

// vector::at
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> myvector(10); // 10 zero-initialized ints

    // assign some values:
    for (unsigned i = 0; i < myvector.size(); i++)
        myvector.at(i) = i;

    std::cout << "myvector contains:";
    for (unsigned i = 0; i < myvector.size(); i++)
        std::cout << ' ' << myvector.at(i);
    std::cout << '\n';

    return 0;
}