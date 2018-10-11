#include <iostream>
#include <string>
using namespace std;
const long delay = 10000000L;
string header =
    "--- Demonstrates Unformatted Input ---";
int main()
{

    string word, rest;
    cout << header
         << "\n\nPress <return> to go on" << endl;
    cin.get();
    // Read the new line
    // without saving.
    cout << "\nPlease enter a sentence with several words!"
         << "\nEnd with <!> and <return>."
         << endl;
    cin >> word;
    getline(cin, rest, '!');
    // Read the first word
    // and the remaining text
    // up to the character !
    cout << "\nThe first word:" << word
         << "\nRemaining text: " << rest << endl;
    return 0;
}
