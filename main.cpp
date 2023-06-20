#include <iostream>
#include <fstream>
#include <string>
#include "Contact.h"
#include "Validator.h"
#include "AddressBook.h"


AddressBook addressBook;

void addContact() {
    std::string inputFullName;
    std::string inputPhoneNumber;
    std::string inputEmail;
    int count = 0;
    do{
        if (count != 0) {
            std::cout << "Your contacts are invalid, please input right" << std::endl;
        }

        std::cout << "Input FullName: " << std::endl;
        std::getline(std::cin >> std::ws, inputFullName);

        std::cout << "Input PhoneNumber: " << std::endl;
        std::getline(std::cin >> std::ws, inputPhoneNumber);

        std::cout << "Input email: " << std::endl;
        std::getline(std::cin >> std::ws, inputEmail);
        count++;
    } while (!addressBook.addContact(inputFullName, inputPhoneNumber, inputEmail));
               
    std::cout << "Success !" << std::endl;
}

void removeContact(const std::string& phone) {
    std::vector<Contact*> tmp = addressBook.findContact(phone);

    if (tmp.size() == 0) {
        std::cout << "The AddressBook is empty !";
        return;
    }
    else if (tmp.size() == 1) {
        addressBook.remove(tmp[0]->getPhoneNumber());
    }
    else{
        for (int i = 0; i < tmp.size(); ++i) {
            std::cout << i+1 << ": "; 
            std::cout << "Full Name: " << tmp[i]->getFullName() << ", ";
            std::cout << "Phone Number: " << tmp[i]->getPhoneNumber() << ", ";
            std::cout << "Email: " << tmp[i]->getEmail() << std::endl;
        }
        int inp;
        do{
            std::cout << "Please choose contact from this list" << std::endl;
            std::cin >> inp;
        } while (inp < 0 || inp > tmp.size());
    
        addressBook.remove(tmp[inp - 1]->getPhoneNumber());
    }
    std::cout << "Success" << std::endl;
}

void updateContact(const std::string& phone) {
    std::vector<Contact*> tmp = addressBook.findContact(phone);

    if (tmp.size() == 0) {
        std::cout << "The AddressBook is empty";
        return;
    }
    else if(tmp.size() == 1){
        int field;
        std::string newField;
        do{
            std::cout << "What field do you want to change" << std::endl;
            std::cout << "1. Full Name" << std::endl;
            std::cout << "2. Phone Number" << std::endl;
            std::cout << "3. Email address" << std::endl;
            std::cin >> field;
        } while (field < 0 || field > 3);
        std::cout << "input the new field" << std::endl;
        std::getline(std::cin >> std::ws, newField);
        if(field == 1) {
            if(!addressBook.updateContact(tmp[0], newField, "", "")){
                std::cout << "Invalid fullname!" << std::endl;
                return;
            }  
            addressBook.eraseWrite();
        }
        if(field == 2) {
            if(!addressBook.updateContact(tmp[0], newField, "", "")){
                std::cout << "Invalid phone!" << std::endl;
                return;
            }  
            addressBook.eraseWrite();
        }
        if(field == 3) {
            if(!addressBook.updateContact(tmp[0], "", "", newField)){
                std::cout << "Invalid email!" << std::endl;
                return;
            }
            addressBook.eraseWrite();
        }
    }
    else{
        for (int i = 0; i < tmp.size(); ++i) {
            std::cout << i+1 << ": "; 
            std::cout << "Full Name: " << tmp[i]->getFullName() << ", ";
            std::cout << "Phone Number: " << tmp[i]->getPhoneNumber() << ", ";
            std::cout << "Email: " << tmp[i]->getEmail() << std::endl;
        }
        int inp;
        do{
            std::cout << "Please choose contact from this list" << std::endl;
            std::cin >> inp;
        } while (inp < 0 || inp > tmp.size());

        int field;
        std::string newField;
        do{
            std::cout << "What field do you want to change" << std::endl;
            std::cout << "1. Full Name" << std::endl;
            std::cout << "2. Phone Number" << std::endl;
            std::cout << "3. Email address" << std::endl;
            std::cin >> field;
        } while (field < 0 || field > 3);
        std::cout << "input the new field" << std::endl;
        std::getline(std::cin >> std::ws, newField);
        if(field == 1) {
            if(!addressBook.updateContact(tmp[0], newField, "", "")){
                std::cout << "Invalid fullname!" << std::endl;
                return;
            }  
            addressBook.eraseWrite();
        }
        if(field == 2) {
            if(!addressBook.updateContact(tmp[0], newField, "", "")){
                std::cout << "Invalid phone!" << std::endl;
                return;
            }  
            addressBook.eraseWrite();
        }
        if(field == 3) {
            if(!addressBook.updateContact(tmp[0], "", "", newField)){
                std::cout << "Invalid email!" << std::endl;
                return;
            }
            addressBook.eraseWrite();
        }
    }
    std::cout << "Success" << std::endl;
}





int main() {
    addressBook.loadContactsFromFile("AddressBook.txt");
    int input;
    std::string data;

    do{
        std::cout << "Please, input number between 0-3: " << std::endl;
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "2. Remove Contact" << std::endl;
        std::cout << "3. Update Contact" << std::endl;
        std::cout << "4. Show all Contacts" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cin >> input;
        if (input == 1) {
            addContact();
        }
        if (input == 2) {
            std::cout << "Input the data of the contact that you want to remove" << std::endl;
            std::getline(std::cin >> std::ws, data);
            removeContact(data);
        }
        if (input == 3) {
            std::cout << "Input the data of the contact that you want to update" << std::endl;
            std::getline(std::cin >> std::ws, data);
            updateContact(data);
        }
        if (input == 4) {
            addressBook.showContacts();
        }
    }while (input);
  
    return 0;
}
