#include <iostream>
#include <string>
#include <list>
#include <iomanip>
#include <algorithm>
#include <limits>
using namespace std;

void printHeader(const string &heading)
{
    cout << string(65, '*') << endl;
    cout << "\t\t\t" << heading << endl;
    cout << string(65, '*') << endl;
}

void getStr(string &text)
{
    do
    {
        getline(cin, text);
    } while (text.empty());
}

template <typename T>
T getNum(bool exitOnFail = false, T lower = 0, T upper = numeric_limits<T>::max())
{
    T numVal = 0;
    cin >> numVal;

    string failMsg = "Invalid input.";
    if (exitOnFail)
        failMsg = "Invalid input! Program Terminated.";

    if (cin.fail() || !(numVal > lower && numVal <= upper))
    {
        cout << failMsg << endl
             << endl;
        cin.clear();
        if (exitOnFail)
            exit(0);
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return numVal;
}

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

    void setStock(const int &stock)
    {
        m_stock = stock;
    }
    void setPrice(const double &price)
    {
        m_price = price;
    }
    void display()
    {
        cout << left << setw(21) << setfill(' ') << m_name << "| ";
        cout << left << setw(21) << setfill(' ') << m_stock << "| ";
        cout << m_price << endl;
    }
};

class Inventory
{
private:
    list<Product> prodList;

    bool strCompare(const string &a, const string &b)
    {
        auto charCompare = [](char x, char y)
        {
            return tolower(x) == tolower(y);
        };
        return a.size() == b.size() &&
               std::equal(a.begin(), a.end(), b.begin(), charCompare);
    }

    list<Product>::iterator search(const string &name)
    {
        auto prodMatch = [&](const Product &p)
        { return strCompare(p.geName(), name); };
        list<Product>::iterator findAt = find_if(prodList.begin(), prodList.end(), prodMatch);

        return findAt;
    }
    bool isEmpty()
    {
        if (prodList.empty())
        {
            cout << "Inventory is empty!" << endl
                 << endl;
            return true;
        }
        return false;
    }

public:
    void addProd()
    {
        printHeader("Adding Product");

        string name;
        int stock;
        double price;

        cout << "Enter product name: ";
        getStr(name);

        if (search(name) != prodList.end())
        {
            cout << "Product already exists" << endl
                 << endl;
            return;
        }

        cout << "Enter product quantity (for " << name << "): ";
        stock = getNum<int>();

        if (stock <= 0)
            return;

        cout << "Enter product price (for " << name << "): ";
        price = getNum<double>();

        if (price <= 0)
            return;

        prodList.emplace_back(Product(name, stock, price));

        cout << "\n";
        cout << "Product Added!" << endl
             << endl;
    }
    void delProd()
    {
        if (isEmpty())
            return;

        printHeader("Deleting Product");

        string name;
        cout << "Enter product name: ";
        getStr(name);

        cout << "\n";

        list<Product>::iterator prodAt = search(name);
        if (prodAt == prodList.end())
        {
            cout << "Product not found!" << endl
                 << endl;
            return;
        }

        prodList.erase(prodAt);

        cout << "Product Deleted!" << endl
             << endl;
    }
    void updProd()
    {
        if (isEmpty())
            return;

        printHeader("Updating Product");

        string name;
        int stock;
        double price;

        cout << "Enter product name: ";
        getStr(name);

        list<Product>::iterator prodAt = search(name);

        if (prodAt != prodList.end())
        {
            string matchName = prodAt->geName();
            cout << "Enter new quantity (for " << matchName << "): ";
            stock = getNum<int>();

            if (stock <= 0)
                return;

            prodAt->setStock(stock);

            cout << "Enter new price (for " << matchName << "): ";
            price = getNum<double>();

            if (price <= 0)
                return;

            prodAt->setPrice(price);

            cout << "\n";
            cout << "Product Updated!" << endl
                 << endl;
        }
        else
        {
            cout << "Product not found." << endl
                 << endl;
        }
    }
    void showInv()
    {
        if (isEmpty())
            return;

        printHeader("Product Details: ");

        cout << left << setw(21) << setfill(' ') << "Product Name" << "| ";
        cout << left << setw(21) << setfill(' ') << "Quantity" << "| ";
        cout << "Price" << endl;
        cout << string(65, '-') << endl;

        for (list<Product>::iterator i = prodList.begin(); i != prodList.end(); i++)
        {
            i->display();
        }
        cout << "\n";
    }
};

int main()
{
    string name;
    cout << "Enter your name: ";
    getStr(name);

    if (name.empty())
    {
        cout << "Invalid Input! Program Terminated.";
        exit(0);
    }

    cout << "Hi " << name << ", what is your courtesy title?" << endl;
    cout << "\t" << "[1] Mr." << endl;
    cout << "\t" << "[2] Ms." << endl;

    int option;
    cout << "Enter the number of your choice: ";
    option = getNum<int>(true, 0, 2);

    cout << "\n";

    string title;
    if (option == 1)
    {
        title = "Mr. ";
    }
    else
    {
        title = "Ms. ";
    }

    Inventory inv;

    cout << "Hello, " << title << name << "! Welcome to the Inventory System." << endl;
    while (true)
    {
        printHeader("Inventory System");
        cout << "What would you like to do?" << endl;
        cout << "\t" << "[1] Add Product" << endl;
        cout << "\t" << "[2] Delete Product" << endl;
        cout << "\t" << "[3] Update Product" << endl;
        cout << "\t" << "[4] Display Inventory" << endl;
        cout << "\t" << "[5] Exit" << endl;
        cout << title << name << ", please enter the number of your choice: ";
        option = getNum<int>(true, 0, 5);
        cout << "\n";

        string confirmExit;

        switch (option)
        {
        case 1:
            inv.addProd();
            break;
        case 2:
            inv.delProd();
            break;
        case 3:
            inv.updProd();
            break;
        case 4:
            inv.showInv();
            break;
        case 5:
            while (true)
            {
                cout << "Are you sure you want to exit? (Y/N): ";
                getStr(confirmExit);

                cout << "\n";

                if (confirmExit == "Y" || confirmExit == "y")
                {
                    cout << "Thank you for using the Inventory System.";
                    exit(0);
                }
                else if (confirmExit == "N" || confirmExit == "n")
                {
                    break;
                }
                else
                {
                    cout << "Invalid input." << endl
                         << endl;
                }
            }
            break;
        }
    }
    return 0;
}