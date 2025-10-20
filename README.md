# C++ Phonebook Project

This is a simple, command-line phonebook application built in C++. It's a project to practice C++ fundamentals, object-oriented programming (OOP), file handling, and data structures.

---

## Features

* **Add Contact:** Save a new contact (name, phone number, and email).
* **Search Contact:** Instantly find a contact by their unique name.
* **Delete Contact:** Remove a contact from the phonebook.
* **Display All:** Show a list of all saved contacts.
* **Persistent Storage:** All contacts are saved to `phonebook.txt` when the app closes and are reloaded when it starts.

---

## Technologies Used

* **C++:** The core programming language.
* **Data Structure:** `std::unordered_map` (a hash map) for efficient O(1) average time complexity on search, add, and delete operations.
* **File I/O:** `fstream` (input/output file streams) to save and load data.
* **String Parsing:** `sstream` (string streams) to parse the contact data from the file.

---

## How to Compile and Run

1.  Clone the repository.
2.  Navigate to the project directory.
3.  Compile the program using `g++`:

    ```bash
    g++ main.cpp Phonebook.cpp -o phonebook_app.exe
    ```

4.  Run the application:

    ```bash
    .\phonebook_app.exe
    ```