#include <iostream>
#include <string>
using namespace std;

class String
{
    string str;

public:

    void input()
    {
        cin >> str;
    }

    bool operator==(String s)
    {
        return str == s.str;
    }

    bool operator>(String s)
    {
        return str > s.str;
    }

    bool operator<(String s)
    {
        return str < s.str;
    }
};

int main()
{
    String s1, s2;

    cout << "Enter first string: ";
    s1.input();

    cout << "Enter second string: ";
    s2.input();

    if (s1 == s2)
    {
        cout << "Both strings are equal." << endl;
    }
    else if (s1 > s2)
    {
        cout << "First string is greater than second string." << endl;
    }
    else if (s1 < s2)
    {
        cout << "First string is smaller than second string." << endl;
    }

    return 0;
}