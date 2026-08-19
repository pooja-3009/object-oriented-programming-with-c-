#include <iostream>
using namespace std;

class Marks
{
protected:
    float m1, m2, m3;

public:
    void accept()
    {
        cout << "Enter marks of Subject 1: ";
        cin >> m1;

        cout << "Enter marks of Subject 2: ";
        cin >> m2;

        cout << "Enter marks of Subject 3: ";
        cin >> m3;
    }
};

class Total : public Marks
{
protected:
    float total;

public:
    void findTotal()
    {
        total = m1 + m2 + m3;
        cout << "Total Marks = " << total << endl;
    }
};

class Percentage : public Total
{
    float percentage;

public:
    void calculate()
    {
        percentage = total / 3;
        cout << "Percentage = " << percentage << "%" << endl;
    }
};

int main()
{
    Percentage p;

    p.accept();
    p.findTotal();
    p.calculate();

    return 0;
}