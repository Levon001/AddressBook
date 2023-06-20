#include "Contact.h"

Contact::Contact(const std::string& fullName, const std::string& phoneNumber, const std::string& email) :
    fullName {fullName}, phoneNumber {phoneNumber}, email {email} {}

Contact::~Contact() {}

void Contact::setFullname(const std::string& fName) {
    fullName = fName; 
}

std::string Contact::getFullName() const {
    return fullName;
}

void Contact::setPhoneNumber(const std::string& phone) {
    phoneNumber = phone;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}


void Contact::setEmail(const std::string& mail) {
    email = mail;
}

std::string Contact::getEmail() const {
    return email;
}
