#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>

using std::string;

class Contact{
public:
    string name;
    string phoneNumber;
    string email;
};

class Phonebook {
private:
    // A hash map where the key is the contact's name (a string)
    // and the value is the Contact object itself
    std::unordered_map<string, Contact> contacts;

public:    
    // These are the actions our phonebook can perform.
    // We'll write the code for them in Phonebook.cpp
    void addContact();
    void searchContact();
    void deleteContact();
    void displayAll();
    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
};