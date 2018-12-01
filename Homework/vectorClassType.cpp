
/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class testObject
{
  private:
    int someInt;

  public:
    testObject(int a) { someInt = a; }
    void show() { cout << someInt << endl; }
};

int main()
{
    vector<testObject> testVector;
    cout << "Initial size: " << testVector.size() << endl;

    for (int i = 0; i < 3; i++)
        testVector.push_back(testObject(i));
    cout << "New size: " << testVector.size() << endl;

    for (int j = 0; j < 3; j++)
        testVector[j].show();

    return 0;
}

*/

/***************************************
	 
	Store class objects in vector

	By: nirvanarupali

	Compiled in Borland C++
	*********************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Friend
{
  public:
    Friend();

    ~Friend() {}

    void setName(string friendName) { name = friendName; }
    void setAge(int friendAge) { age = friendAge; }
    void setHeight(int friendHeight) { height = friendHeight; }
    void printFriendInfo();

  private:
    string name;
    int age;

    float height;
};

//implementations
Friend::Friend()
{
    age = 0;
    height = 0.0;
}
//printing

void Friend::printFriendInfo()

{
    cout << "Name       : " << name << endl;
    cout << "Age        : " << age << endl;
    cout << "Height     : " << height << endl
         << endl;
}

int main()
{
    // Create a vector of Friend objects
    vector<Friend> list;
    string Name;

    int Age;

    float Height;

    Friend *f1;

    for (int n = 0; n < 3; n++)

    {

        cout << "Enter name :" << endl;
        getline(cin, Name);
        cout << "Enter age :" << endl;
        cin >> Age;
        cout << "Enter height :" << endl;
        cin >> Height;
        f1 = new Friend;
        f1->setName(Name);
        f1->setAge(Age);
        f1->setHeight(Height);
        list.push_back(*f1);
        cin.get(); //clear buffer
    }

    // Now setup an iterator loop through the vector

    vector<Friend>::iterator it;
    for (it = list.begin(); it != list.end(); ++it)
    {
        // For each friend, print out their info
        it->printFriendInfo();
    }

    return 0;
}