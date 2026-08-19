#include <iostream>
#include <string>
using namespace std;

class worker
{
protected:
    int code;
    string name;
    float salary;

public:
    void getWorker()
    {
        cout << "Enter Worker Code: ";
        cin >> code;

        cout << "Enter Worker Name: ";
        cin >> name;

        cout << "Enter Salary: ";
        cin >> salary;
    }
};

class officer
{
protected:
    float DA;
    float HRA;

public:
    void getOfficer()
    {
        cout << "Enter DA percentage: ";
        cin >> DA;

        cout << "Enter HRA percentage: ";
        cin >> HRA;
    }
};

class manager : public worker, public officer
{
    float TA;
    float gross_sal;

public:
    void calculate()
    {
        TA = salary * 0.10;

        float daAmount = salary * DA / 100;
        float hraAmount = salary * HRA / 100;

        gross_sal = salary + daAmount + hraAmount + TA;
    }

    void display()
    {
        cout << "\n===== MANAGER DETAILS =====" << endl;
        cout << "Worker Code: " << code << endl;
        cout << "Worker Name: " << name << endl;
        cout << "Basic Salary: Rs. " << salary << endl;
        cout << "DA: " << DA << "%" << endl;
        cout << "HRA: " << HRA << "%" << endl;
        cout << "TA: Rs. " << TA << endl;
        cout << "Gross Salary: Rs. " << gross_sal << endl;
    }
};

int main()
{
    manager m;

    m.getWorker();
    m.getOfficer();
    m.calculate();
    m.display();

    return 0;
}