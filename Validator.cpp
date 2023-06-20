#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include "Validator.h"

bool NameValidator::check(const std::string &fullName)
{   
    std::string trimmed = trimString(fullName);
    if (trimmed == ""){
        return false;
    }
    
    std::regex pattern("^[a-zA-Z]{3,} [a-zA-Z]+$");
    return std::regex_match(trimmed, pattern);

}

std::string NameValidator::trimString(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t\n\r");

    if (start == std::string::npos)
        return "";

    size_t end = str.find_last_not_of(" \t\n\r");

    std::string trimmed = str.substr(start, end - start + 1);

    std::istringstream iss(trimmed);
    std::ostringstream oss;
    std::string word;
    bool isFirstWord = true;
    while (iss >> word)
    {
        if (isFirstWord)
            isFirstWord = false;
        else
            oss << " ";
        oss << word;
    }

    return oss.str();
}

std::string PhoneNumberValidator::deleteSpace (const std::string& phoneNumber) {
        std::string cleanedNumber = phoneNumber;
        cleanedNumber.erase(std::remove(cleanedNumber.begin(), cleanedNumber.end(), ' '), cleanedNumber.end());
        cleanedNumber.erase(std::remove(cleanedNumber.begin(), cleanedNumber.end(), '_'), cleanedNumber.end());
        cleanedNumber.erase(std::remove(cleanedNumber.begin(), cleanedNumber.end(), '-'), cleanedNumber.end());
        return cleanedNumber;
    }

bool PhoneNumberValidator::check (const std::string& phone) {
        std::string input = phone; 
        input = deleteSpace(input);
        if (input.find("374") == 0) {
            input= "+" + input;
        }
        std::string str;
        std::string lastPart;
        if (input.find("0") == 0) {
            str = input.substr(1, 2);
            if (regionCode(str)) {
                lastPart = input.substr(3);
                return isNumber(lastPart);
            } else {
                return false;
            }
        } else if (input.find("+374") == 0) {
            str = input.substr(4, 2);
            if (regionCode(str)) {
                lastPart = input.substr(6);
                return isNumber(lastPart);
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    bool PhoneNumberValidator::regionCode(const std::string& str) {
        std::vector<std::string> rangePhoneNumber = { "91", "93", "94", "95", "96", "97", "98", "99", "77", "43", "33", "47", "55" };
        for (const auto& code : rangePhoneNumber) {
            if (str == code) {
                return true;
            }
        }
        return false;
    }

    bool PhoneNumberValidator::isNumber(const std::string& phoneNumber) {
        if (phoneNumber.length() != 6) {
            return false;
        } else {
            for (char c : phoneNumber) {
                if (c < '0' || c > '9') {
                    std::cout << "false" << std::endl;
                    return false;
                }
            }
            return true;
        }
    }


    bool EmailValidator::domaimName(const std::string& email) {
        std::vector<std::string> rangeDomainName = {"gmail.com", "mail.ru"};
        size_t atPos = email.find('@');
        std::string partsOne = email.substr(atPos + 1);

        bool domainMatch = false;
        for (const std::string& domain : rangeDomainName) {
            if (partsOne == domain) {
                domainMatch = true;
                break;
            }
        }

        if (!domainMatch) {
            return false;
        } else {
            return true;
        }
    }

    bool EmailValidator::check(const std::string& inputEmail) {
        char c = inputEmail[0];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (lengthLocalPart(inputEmail)) {
                if (thereIsDog(inputEmail)) {
                    if (doubleSymbols(inputEmail)) {
                        return true;
                    }
                    return false;
                }
                return false;
            }
        } 
        return false;    
    }

    bool EmailValidator::thereIsDog(const std::string& str) {
        int count = 0;
        for (size_t i = 1; i < str.length(); ++i) {
            if (str[i] == '@') {
                ++count;
            }
        }

        if (count <= 1 && count != 0) {
            return true;
        } else {
            return false;
        }
    }
    


    bool EmailValidator::lengthLocalPart(const std::string& s) {
        size_t atPos = s.find('@');
        std::string localPart = s.substr(0, atPos);
        std::string regex = "^[^ ;'%$#!,><]*$";
        if (!regex_match(localPart, std::regex(regex))) {
            return false;
        }
        if (localPart.length() < 5) {
            return false;
        } else {
            return true;
        }
    }

    bool EmailValidator::doubleSymbols(const std::string& s) {
        size_t atPos = s.find('@');
        std::string localPart = s.substr(0, atPos);

        for (size_t i = 1; i < localPart.length() - 1; ++i) {
            if ((localPart[i] == '_' && localPart[i + 1] == '_') ||
                (localPart[i] == '-' && localPart[i + 1] == '-') ||
                (localPart[i] == '.' && localPart[i + 1] == '.')) {
                return false;
            }
        }
        return true;
    }