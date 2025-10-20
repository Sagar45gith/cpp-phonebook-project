#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include "Phonebook.h" // Don't forget to include your header!

// This is safe in a .cpp file and makes our lives easier
using namespace std;

//
// This is the implementation for the Phonebook::addContact function
//
void Phonebook::addContact() {
    Contact newContact; // Create a new, blank Contact object

    cout << "\n--- Add New Contact ---" << endl;
    cout << "Enter Name: ";
    // We use getline to read the whole line, including spaces
    getline(cin, newContact.name);

    cout << "Enter Phone Number: ";
    getline(cin, newContact.phoneNumber);

    cout << "Enter Email: ";
    getline(cin, newContact.email);

    // This is the magic!
    // We add the new contact to our hash map using its name as the key.
    contacts[newContact.name] = newContact;

    cout << "\nSuccess: Contact '" << newContact.name << "' added." << endl;
}


// --- Function Stubs ---

void Phonebook::searchContact() {
    cout << "\n--- Search Contact ---" << endl;
    cout << "Enter Name to search for: ";
    string name;
    getline(cin, name);

    // This is the magic!
    // We use .find() to search for the key (the name).
    // .find() is almost instant (O(1) average time), 
    // no matter if you have 10 contacts or 10 million.
    // It returns an "iterator" (like a pointer) to the map entry.
    auto it = contacts.find(name);

    //
    // Check if the contact was found
    //
    // contacts.end() is a special value that means "past the end of the map".
    // If .find() returns contacts.end(), it means it searched and found nothing.
    if (it == contacts.end()) {
        cout << "\nError: Contact '" << name << "' not found." << endl;
    } else {
        // If it's NOT contacts.end(), it means we found it!
        // 'it' now points to the found map entry.
        //   -> 'it->first' is the key (the name, e.g., "Sagar")
        //   -> 'it->second' is the value (the Contact object itself)
        
        cout << "\n--- Contact Found ---" << endl;
        cout << "Name: " << it->second.name << endl;
        cout << "Phone: " << it->second.phoneNumber << endl;
        cout << "Email: " << it->second.email << endl;
    }
}

void Phonebook::deleteContact() {
    cout << "\n--- Delete Contact ---" << endl;
    cout << "Enter Name to delete: ";
    string name;
    getline(cin, name);

    // Step 1: Find the contact, just like in searchContact
    auto it = contacts.find(name);

    // Step 2: Check if the contact was found
    if (it == contacts.end()) {
        // Case 1: Not found
        cout << "\nError: Contact '" << name << "' not found. Nothing deleted." << endl;
    } else {
        // Case 2: Found!
        // This is the new part. The .erase() method
        // removes the key-value pair pointed to by the iterator.
        contacts.erase(it);
        cout << "\nSuccess: Contact '" << name << "' was deleted." << endl;
    }
}

void Phonebook::displayAll() {
    cout << "\n--- All Contacts ---" << endl;

    // First, check if the phonebook is empty
    if (contacts.empty()) {
        cout << "Your phonebook is empty." << endl;
        return; // Exit the function early
    }

    // This is a "range-based for loop"
    // It's the modern, easy way to loop over collections in C++.
    //
    // 'const auto& entry' :
    //   - 'auto' automatically figures out the type (which is a pair)
    //   - '&' (reference) avoids making a slow, unnecessary copy
    //   - 'const' promises we won't change the data while looping
    //
    // 'contacts' is the map we are looping over.
    for (const auto& entry : contacts) {    
        
        // 'entry' is a key-value pair.
        //   - 'entry.first' is the key (the name)
        //   - 'entry.second' is the value (the Contact object)
        
        const Contact& contact = entry.second; // Get the contact object

        cout << "------------------------" << endl;
        cout << "Name:  " << contact.name << endl;
        cout << "Phone: " << contact.phoneNumber << endl;
        cout << "Email: " << contact.email << endl;
    }
    cout << "------------------------" << endl;
    cout << "Total contacts: " << contacts.size() << endl;
}

void Phonebook::saveToFile(const string& filename) {
    // 1. Create an "output file stream" object
    //    'ofstream' means "output file stream"
    std::ofstream outFile;

    // 2. Open the file
    //    This creates the file if it doesn't exist,
    //    or overwrites it if it does.
    outFile.open(filename);

    // 3. Check if the file opened successfully
    if (!outFile.is_open()) {
        cout << "Error: Could not open file " << filename << " for writing." << endl;
        return; // Exit the function if we can't open the file
    }

    // 4. Loop through the map (just like in displayAll)
    for (const auto& entry : contacts) {
        const Contact& contact = entry.second;
        
        // 5. Write the contact data to the file, separated by commas
        outFile << contact.name << ","
                << contact.phoneNumber << ","
                << contact.email << "\n"; // '\n' for a new line
    }

    // 6. Close the file when we're done
    outFile.close();
}

void Phonebook::loadFromFile(const string& filename) {
    // 1. Create an "input file stream" object
    //    'ifstream' means "input file stream"
    std::ifstream inFile;
    inFile.open(filename);

    // 2. Check if the file opened
    //    If the file doesn't exist (like the very first time),
    //    it's not an error. We just have nothing to load.
    if (!inFile.is_open()) {
        cout << "Notice: No existing 'phonebook.txt' found. Starting fresh." << endl;
        return;
    }

    string line;
    // 3. Read the file one line at a time
    while (std::getline(inFile, line)) {
        Contact loadedContact;
        
        // 4. Use stringstream to split the line
        //    This treats our 'line' string as if it were a stream
        std::stringstream ss(line);
        string segment;

        // 5. Split the line by the comma (',') delimiter
        
        // Get the name (up to the first comma)
        if (std::getline(ss, segment, ',')) {
            loadedContact.name = segment;
        }

        // Get the phone number (up to the second comma)
        if (std::getline(ss, segment, ',')) {
            loadedContact.phoneNumber = segment;
        }

        // Get the email (the rest of the line)
        if (std::getline(ss, segment, ',')) {
            loadedContact.email = segment;
        }

        // 6. Add the loaded contact to our map
        //    (Only if the name is not empty, just in case)
        if (!loadedContact.name.empty()) {
            contacts[loadedContact.name] = loadedContact;
        }
    }

    // 7. Close the file and print a success message
    inFile.close();
    cout << "Successfully loaded " << contacts.size() << " contacts from file." << endl;
}