#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    string address;
    string phone_no;

public:
    void acceptPerson()
    {
        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Address: ";
        cin >> address;

        cout << "Enter Phone Number: ";
        cin >> phone_no;
    }
};

class Employee : public Person
{
    int eno;
    string ename;

public:
    void accept()
    {
        cout << "\nEnter Employee Details\n";

        cout << "Enter Employee Number: ";
        cin >> eno;

        cout << "Enter Employee Name: ";
        cin >> ename;

        acceptPerson();
    }

    void display()
    {
        cout << "\nEmployee Number: " << eno << endl;
        cout << "Employee Name: " << ename << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phone_no << endl;
    }
};

class Manager : public Person
{
    string designation;
    string department_name;
    double basic_salary;

public:
    void accept()
    {
        cout << "\nEnter Manager Details\n";

        cout << "Enter Designation: ";
        cin >> designation;

        cout << "Enter Department Name: ";
        cin >> department_name;

        cout << "Enter Basic Salary: ";
        cin >> basic_salary;

        acceptPerson();
    }

    void display()
    {
        cout << "\nDesignation: " << designation << endl;
        cout << "Department: " << department_name << endl;
        cout << "Basic Salary: Rs. " << basic_salary << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phone_no << endl;
    }

    double getSalary()
    {
        return basic_salary;
    }
};

int main()
{
    int n;
    int choice;

    cout << "Enter number of Employees and Managers: ";
    cin >> n;

    Employee emp[10];
    Manager mgr[10];

    do
    {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Accept Details" << endl;
        cout << "2. Display Details" << endl;
        cout << "3. Display Manager with Highest Salary" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n--- Employee Details ---" << endl;

            for (int i = 0; i < n; i++)
            {
                cout << "\nEmployee " << i + 1 << endl;
                emp[i].accept();
            }

            cout << "\n--- Manager Details ---" << endl;

            for (int i = 0; i < n; i++)
            {
                cout << "\nManager " << i + 1 << endl;
                mgr[i].accept();
            }
            break;

        case 2:
            cout << "\n===== ALL EMPLOYEES =====" << endl;

            for (int i = 0; i < n; i++)
            {
                emp[i].display();
            }

            cout << "\n===== ALL MANAGERS =====" << endl;

            for (int i = 0; i < n; i++)
            {
                mgr[i].display();
            }
            break;

        case 3:
        {
            int position = 0;

            for (int i = 1; i < n; i++)
            {
                if (mgr[i].getSalary() > mgr[position].getSalary())
                {
                    position = i;
                }
            }

            cout << "\n===== MANAGER WITH HIGHEST SALARY =====" << endl;
            mgr[position].display();

            break;
        }

        case 4:
            cout << "\nProgram exited." << endl;
            break;

        default:
            cout << "\nInvalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}