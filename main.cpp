#include <iostream>
#include <string>
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

    string title;
    option == 1 ? title = "Mr. " : title = "Ms. ";

    cout << "Hello, " << title << name << "! Welcome to the Inventory System." << endl;
    cout << string(70, '*') << endl;
    cout << "\t\t\t" << "Inventory System" << endl;
    cout << string(70, '*') << endl;
    cout << "What would you like to do?" << endl;
    cout << "\t" << "[1] Add Product" << endl;
    cout << "\t" << "[2] Delete Product" << endl;
    cout << "\t" << "[3] Update Product" << endl;
    cout << "\t" << "[4] Display Inventory" << endl;
    cout << "\t" << "[5] Exit" << endl;
    cout << title << name << ", please enter the number of your choice: ";
    cin >> option;
    cout << option;
    return 0;
}