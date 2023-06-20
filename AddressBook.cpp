#include <iostream>
#include <fstream>
#include <sstream>
#include "Contact.h"
#include "AddressBook.h"
#include "Validator.h"

bool AddressBook::addContact(const std::string& fullName, const std::string& phoneNumber, const std::string& email) {
    if(!NameValidator().check(fullName) || !PhoneNumberValidator().check(phoneNumber) || !EmailValidator().check(email)) {
        return false;
    }
    Contact* contact = new Contact(fullName, phoneNumber, email);
    contacts.push_back(contact);
    writeInFile(contact);
    return true;
}

void AddressBook::writeInFile(Contact* contact) {
    std::ofstream outputFile("AddressBook.txt", std::ios::app);
        if (outputFile.is_open()) {
            outputFile << contact->getFullName() << ",";
            outputFile << AddressBook::cleanedPhoneNumber(contact->getPhoneNumber()) << ",";
            outputFile << contact->getEmail() << std::endl;
            outputFile.close();
        } else {
            std::cout << "Unable to open the file for writing." << std::endl;
        }
}


void AddressBook::showContacts() {
    for (auto contact: contacts){
        std::cout << "Full Name: " << contact->getFullName() << ", ";
        std::cout << "Phone Number: " << contact->getPhoneNumber() << ", ";
        std::cout << "Email: " << contact->getEmail() << std::endl;
    } 
}

void AddressBook::remove(const std::string& phoneNumber) {
    for (auto contact = contacts.begin(); contact != contacts.end(); ++contact) {
        if((*contact)->getPhoneNumber() == phoneNumber) {
            contacts.erase(contact);
            break;
        }
    }

    eraseWrite();
}        

void AddressBook::eraseWrite() {
    eraseFileContents("AddressBook.txt");

    for (auto contact : contacts ) {
        AddressBook::writeInFile(contact);
    }
}

void AddressBook::eraseFileContents(const std::string& filename) {
    std::ofstream file(filename, std::ios::trunc);
    if (file.is_open()) {
        file.close();
        std::cout << "File contents erased successfully." << std::endl;
    } else {
        std::cout << "Unable to open the file for erasing contents." << std::endl;
    }
}


std::vector<Contact*> AddressBook::findContact(const std::string& info) {
    std::vector<Contact*> tmpVector;
    for (auto contact : contacts) {
        if(contact->getEmail() == info || contact->getFullName() == info || contact->getPhoneNumber() == info) {
            tmpVector.push_back(contact);
        }
    }
    return tmpVector;
}     


bool AddressBook::updateContact(Contact* contact, const std::string& fullName, const std::string& phoneNumber, const std::string& email) {
    Validator* validator = nullptr; 
    if (fullName.size() > 0) {
        
        validator = new NameValidator();
        std::cout << validator->check(fullName) << std::endl;
        if(validator->check(fullName)) { 
            contact->setFullname(fullName);
            return true;
        }
        return false;
    }

    if (phoneNumber.size() > 0) {
        validator = new PhoneNumberValidator();
        if(validator->check(phoneNumber)) {
            contact->setPhoneNumber(phoneNumber);
            return true;
        }
        return false;
    }

    if (email.size() > 0) {
        validator = new EmailValidator();
        if(validator->check(email)) {
            contact->setEmail(email);
            return true;
        }
        return false;
    }

    return false;
}      

void AddressBook::loadContactsFromFile(const std::string& filename) {
     std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            std::string fullName, phoneNumber, email;
            std::getline(iss, fullName, ',');
            std::getline(iss, phoneNumber, ',');
            std::getline(iss, email);
            Contact* contactFromFile = new Contact(fullName, phoneNumber, email);
            contacts.push_back(contactFromFile);
        }
        inputFile.close();
    } else {
        std::cout << "Unable to open the file for reading." << std::endl;
    }
}

std::string AddressBook::cleanedPhoneNumber(const std::string& phoneNumber) {
    std::string cleanedPhoneNumber;
    for (char c : phoneNumber) {
        if (c != '-' && c != '_') {
            cleanedPhoneNumber += c;
        }
    }

    if(cleanedPhoneNumber[0] == '+') {
        cleanedPhoneNumber = cleanedPhoneNumber.substr(1);
    }

    if(cleanedPhoneNumber.substr(0,3) == "374") {
        cleanedPhoneNumber = "0" + cleanedPhoneNumber.substr(3);
    }

    return cleanedPhoneNumber;
}
