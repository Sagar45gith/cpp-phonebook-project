#include <iostream>
#include "Phonebook.h" // Include our new header file

using std::cout;
using std::cin;
using std::endl;

void showMenu() {
    cout << "\n--- Phonebook Menu ---" << endl;
    cout << "1. Add Contact" << endl;
    cout << "2. Search Contact" << endl;
    cout << "3. Delete Contact" << endl;
    cout << "4. Display All Contacts" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Phonebook phonebook; // Create an instance of our Phonebook
    phonebook.loadFromFile("phonebook.txt"); // Load existing contacts from file
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        // Clear the input buffer
        cin.ignore(1000, '\n'); 

        switch (choice) {
            case 1:
                phonebook.addContact(); 
                break;
            case 2:
                phonebook.searchContact();
                break;
            case 3:
                phonebook.deleteContact();
                break;
            case 4:
                phonebook.displayAll();
                break;
            case 5:
                cout << "Saving contacts..." << endl;
                phonebook.saveToFile("phonebook.txt"); 
                cout << "Exiting..." << endl;
                return 0; // Exit the loop and the program
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}