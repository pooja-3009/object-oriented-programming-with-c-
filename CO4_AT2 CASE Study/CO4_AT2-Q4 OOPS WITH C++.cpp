#include <iostream>
#include <string>
using namespace std;

class Item
{
protected:
    int item_no;
    string name;
    double price;

public:
    void accept()
    {
        cout << "Enter Item Number: ";
        cin >> item_no;

        cout << "Enter Item Name: ";
        cin >> name;

        cout << "Enter Price: ";
        cin >> price;
    }
};

class DiscountedItem : public Item
{
    double discount_percent;
    double discount_amount;
    double final_price;

public:
    void calculate()
    {
        cout << "Enter Discount Percentage: ";
        cin >> discount_percent;

        discount_amount = price * discount_percent / 100;
        final_price = price - discount_amount;
    }

    void display()
    {
        cout << item_no << "\t"
             << name << "\t"
             << price << "\t"
             << discount_percent << "%\t"
             << final_price << endl;
    }

    double getFinalPrice()
    {
        return final_price;
    }
};

int main()
{
    int n;
    double total = 0;

    cout << "Enter number of items: ";
    cin >> n;

    DiscountedItem item[10];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of Item " << i + 1 << endl;

        item[i].accept();
        item[i].calculate();
    }

    cout << "\n========== ITEM WISE BILL ==========" << endl;
    cout << "Item No\tName\tPrice\tDiscount\tFinal Price" << endl;

    for (int i = 0; i < n; i++)
    {
        item[i].display();
        total = total + item[i].getFinalPrice();
    }

    cout << "\nTotal Amount = Rs. " << total << endl;

    return 0;
}