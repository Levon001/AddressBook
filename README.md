# Address Book

This is a simple command-line address book program written in C++. It allows users to add, update, and remove contacts, each containing a full name, phone number, and email address. The program includes a validator to ensure the correctness of user input.

## Features

- Add a new contact with a full name, phone number, and email address.
- Update an existing contact's information.
- Remove a contact from the address book.
- Input validation to ensure correct formatting of each field.
- Interactive command-line interface for user interaction.

## Requirements

- C++ compiler that supports C++11 or later.
- Command-line interface.

## Usage

1. Clone the repository:

   ```shell
   git clone https://github.com/Levon001/AddressBook.git
   ```
2. Compile the program:

   ```shell
   g++ main.cpp Contact.cpp Validator.cpp  AddressBook.cpp -o main
   ```
3. Run the program:
   
   ```
   ./main
   ```
   
