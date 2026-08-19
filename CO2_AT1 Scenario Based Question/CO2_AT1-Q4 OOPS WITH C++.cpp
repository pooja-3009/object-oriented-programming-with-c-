#include <iostream>
#include <string>
using namespace std;

class RailwayTicket
{
    string name;
    string coach;
    long mobno;
    int amt;
    int totalamt;

public:
    void accept()
    {
        cout << "Enter customer name: ";
        getline(cin, name);

        cout << "Enter coach type: ";
        cin >> coach;

        cout << "Enter mobile number: ";
        cin >> mobno;

        cout << "Enter basic amount: ";
        cin >> amt;
    }

    void update()
    {
        if (coach == "First_AC")
            totalamt = amt + 700;
        else if (coach == "Second_AC")
            totalamt = amt + 500;
        else if (coach == "Third_AC")
            totalamt = amt + 250;
        else if (coach == "sleeper")
            totalamt = amt;
        else
            totalamt = amt;
    }

    void display()
    {
        cout << "\nCustomer Name: " << name << endl;
        cout << "Coach: " << coach << endl;
        cout << "Mobile Number: " << mobno << endl;
        cout << "Total Amount: Rs. " << totalamt << endl;
    }
};

int main()
{
    RailwayTicket r;

    r.accept();
    r.update();
    r.display();

    return 0;
}