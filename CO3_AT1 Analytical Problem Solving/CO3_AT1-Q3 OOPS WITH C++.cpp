#include <iostream>
using namespace std;

class FLOAT
{
    float value;

public:

    FLOAT()
    {
        value = 0;
    }

    FLOAT(float v)
    {
        value = v;
    }

    FLOAT operator+(FLOAT f)
    {
        return FLOAT(value + f.value);
    }

    FLOAT operator-(FLOAT f)
    {
        return FLOAT(value - f.value);
    }

    FLOAT operator*(FLOAT f)
    {
        return FLOAT(value * f.value);
    }

    FLOAT operator/(FLOAT f)
    {
        return FLOAT(value / f.value);
    }

    void display()
    {
        cout << value << endl;
    }
};

int main()
{
    float a, b;

    cout << "Enter first floating point number: ";
    cin >> a;

    cout << "Enter second floating point number: ";
    cin >> b;

    FLOAT f1(a);
    FLOAT f2(b);

    FLOAT sum = f1 + f2;
    FLOAT difference = f1 - f2;
    FLOAT product = f1 * f2;
    FLOAT division = f1 / f2;

    cout << "\nAddition: ";
    sum.display();

    cout << "Subtraction: ";
    difference.display();

    cout << "Multiplication: ";
    product.display();

    cout << "Division: ";
    division.display();

    return 0;
}