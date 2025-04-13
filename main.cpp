#include <iostream>
#include <string>
#include <list>
#include <iomanip>
using namespace std;

class Product
{
private:
    string m_name = "";
    int m_stock = 0;
    double m_price = 0;

public:
    Product(const string name = "", const int &stock = 0, const double &price = 0) : m_name(name), m_stock(stock), m_price(price) {}

    string geName() const
    {
        return m_name;
    }
    int getStock() const
    {
        return m_stock;
    }
    double getPrice() const
    {
        return m_price;
    }

    void setName(const string &name)
    {
        m_name = name;
    }
    void setStock(const int &stock)
    {
        m_stock = stock;
    }
    void setPrice(const double &price)
    {
        m_price = price;
    }
};

class Inventory
{
private:
    list<Product> prodList;

public:
    void addProd()
    {
        cout << string(65, '*') << endl;
        cout << "\t\t\t" << "Adding Product" << endl;
        cout << string(65, '*') << endl;

        string name;
        int stock;
        double price;

        cout << "Enter product name: ";
        cin >> name;

        cout << "Enter product quantity (for " << name << "): ";
        cin >> stock;

        cout << "Enter product price (for " << name << "): ";
        cin >> price;

        prodList.emplace_back(Product(name, stock, price));

        cout << "\n";
        cout << "Product Added!" << endl;
        cout << "\n";
    }
    void delProd()
    {
        cout << string(65, '*') << endl;
        cout << "\t\t\t" << "Deleting Product" << endl;
        cout << string(65, '*') << endl;

        string name;
        cout << "Enter product name: ";
        cin >> name;

        prodList.remove_if([&name](Product &p)
                           { return p.geName() == name; });

        cout << "\n";
        cout << "Product Deleted!" << endl;
        cout << "\n";
    }
    void display()
    {
        cout << string(65, '*') << endl;
        cout << "\t\t\t" << "Product Details: " << endl;
        cout << string(65, '*') << endl;

        cout << left << setw(21) << setfill(' ') << "Product Name" << "| ";
        cout << left << setw(21) << setfill(' ') << "Quantity" << "| ";
        cout << "Price" << endl;
        cout << string(65, '-') << endl;

        for (list<Product>::iterator i = prodList.begin(); i != prodList.end(); i++)
        {
            cout << left << setw(21) << setfill(' ') << i->geName() << "| ";
            cout << left << setw(21) << setfill(' ') << i->getStock() << "| ";
            cout << i->getPrice() << endl;
        }
    }
};

int main()
{
    string name;
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Hi " << name << ", what is your courtesy title?" << endl;
    cout << "\t" << "[1] Mr." << endl;
    cout << "\t" << "[2] Ms." << endl;

    int option;
    cout << "Enter the number of your choice: ";
    cin >> option;

    cout << "\n";

    string title;
    option == 1 ? title = "Mr. " : title = "Ms. ";

    Inventory inv;

    cout << "Hello, " << title << name << "! Welcome to the Inventory System." << endl;
    do
    {
        cout << string(65, '*') << endl;
        cout << "\t\t\t" << "Inventory System" << endl;
        cout << string(65, '*') << endl;
        cout << "What would you like to do?" << endl;
        cout << "\t" << "[1] Add Product" << endl;
        cout << "\t" << "[2] Delete Product" << endl;
        cout << "\t" << "[3] Update Product" << endl;
        cout << "\t" << "[4] Display Inventory" << endl;
        cout << "\t" << "[5] Exit" << endl;
        cout << title << name << ", please enter the number of your choice: ";
        cin >> option;
        cout << "\n";

        switch (option)
        {
        case 1:
            inv.addProd();
            break;
        case 2:
            inv.delProd();
            break;
        case 4:
            inv.display();
            break;
        case 5:
            cout << "Exiting the program";
            exit;
            break;
        default:
            cout << "Invalid input";
            exit;
        }
    } while (option != 5);

    return 0;
}