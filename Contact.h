#ifndef CONTACT
#define CONTACT
#include <string>

class Contact {
    private:
        std::string fullName;
        std::string phoneNumber;
        std::string email;  
    public:
        Contact(const std::string&, const std::string&, const std::string&);
        void setFullname(const std::string&);
        std::string getFullName() const;
        void setPhoneNumber(const std::string&);
        std::string getPhoneNumber() const;
        void setEmail(const std::string&);
        std::string getEmail() const;
        ~Contact();
};

#endif