#include <iostream>
#include <string>
using namespace std;

class ElectricBill
{
    string n;
    int units;
    double bill;

public:
    void accept()
    {
        cout << "Enter customer name: ";
        getline(cin, n);

        cout << "Enter units consumed: ";
        cin >> units;
    }

    void calculate()
    {
        if (units <= 100)
        {
            bill = units * 2.00;
        }
        else if (units <= 300)
        {
            bill = (100 * 2.00) + ((units - 100) * 3.00);
        }
        else
        {
            bill = (100 * 2.00) + (200 * 3.00) +
                   ((units - 300) * 5.00);

            bill = bill + (bill * 0.025);
        }
    }

    void print()
    {
        cout << "\nName of the customer: " << n << endl;
        cout << "Number of units consumed: " << units << endl;
        cout << "Bill amount: Rs. " << bill << endl;
    }
};

int main()
{
    ElectricBill e;

    e.accept();
    e.calculate();
    e.print();

    return 0;
}