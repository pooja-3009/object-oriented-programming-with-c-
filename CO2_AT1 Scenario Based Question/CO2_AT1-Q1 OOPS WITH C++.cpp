#include <iostream>
#include <string>
using namespace std;

class movieMagic
{
    int year;
    string title;
    float rating;

public:
    void accept()
    {
        cout << "Enter year of release: ";
        cin >> year;

        cin.ignore();
        cout << "Enter movie title: ";
        getline(cin, title);

        cout << "Enter rating: ";
        cin >> rating;
    }

    void display()
    {
        cout << "\nMovie Title: " << title << endl;

        if (rating >= 0.0 && rating <= 2.0)
            cout << "Message: Flop" << endl;
        else if (rating >= 2.1 && rating <= 3.4)
            cout << "Message: Semi-hit" << endl;
        else if (rating >= 3.5 && rating <= 4.5)
            cout << "Message: Hit" << endl;
        else if (rating >= 4.6 && rating <= 5.0)
            cout << "Message: Super Hit" << endl;
        else
            cout << "Invalid Rating" << endl;
    }
};

int main()
{
    movieMagic m;

    m.accept();
    m.display();

    return 0;
}