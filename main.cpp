#include <iostream>
using namespace std;

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
    if (option == 1)
    {
        cout << "Hello, Mr. " << name << "! Welcome to the Inventory System." << endl;
    }
    else
    {
        cout << "Hello, Ms. " << name << "! Welcome to the Inventory System." << endl;
    }

    return 0;
}