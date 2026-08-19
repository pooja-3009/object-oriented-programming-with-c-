#include <iostream>
#include <string>
using namespace std;

class books
{
    string author;
    string title;
    float price;
    string publisher;
    int stock;

    // Private member function
    void updatePrice(float newPrice)
    {
        price = newPrice;
    }

public:
    static int successful;
    static int unsuccessful;

    // Constructor
    books(string a, string t, float p, string pub, int s)
    {
        author = a;
        title = t;
        price = p;
        publisher = pub;
        stock = s;
    }

    bool search(string t, string a)
    {
        return (title == t && author == a);
    }

    void display()
    {
        cout << "\nBook Details" << endl;
        cout << "Title     : " << title << endl;
        cout << "Author    : " << author << endl;
        cout << "Price     : Rs. " << price << endl;
        cout << "Publisher : " << publisher << endl;
        cout << "Stock     : " << stock << endl;
    }

    void purchase(int copies)
    {
        if (copies <= stock)
        {
            float total = copies * price;

            cout << "Total Cost: Rs. " << total << endl;

            stock = stock - copies;

            successful++;

            cout << "Transaction successful." << endl;
            cout << "Remaining Stock: " << stock << endl;
        }
        else
        {
            cout << "Required copies not in stock." << endl;
            unsuccessful++;
        }
    }

    void changePrice(float newPrice)
    {
        updatePrice(newPrice);
        cout << "Price updated successfully." << endl;
    }
};

int books::successful = 0;
int books::unsuccessful = 0;

int main()
{
    books b[3] =
    {
        books("R.K.Sharma", "C++", 500, "TechBooks", 10),
        books("James", "Python", 600, "LearnPub", 8),
        books("Dennis", "Programming", 700, "CodePress", 5)
    };

    string searchTitle;
    string searchAuthor;
    int copies;
    int found = -1;

    cout << "Enter book title: ";
    cin >> searchTitle;

    cout << "Enter author name: ";
    cin >> searchAuthor;

    for (int i = 0; i < 3; i++)
    {
        if (b[i].search(searchTitle, searchAuthor))
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        cout << "\nBook is not available." << endl;
        books::unsuccessful++;
    }
    else
    {
        b[found].display();

        cout << "\nEnter number of copies required: ";
        cin >> copies;

        b[found].purchase(copies);
    }

    cout << "\n===== TRANSACTION STATISTICS =====" << endl;
    cout << "Successful Transactions   : "
         << books::successful << endl;
    cout << "Unsuccessful Transactions : "
         << books::unsuccessful << endl;

    return 0;
}