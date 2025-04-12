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

    string title;
    option == 1 ? title = "Mr. " : title = "Ms. ";

    cout << "Hello, " << title << name << "! Welcome to the Inventory System." << endl;

    return 0;
}