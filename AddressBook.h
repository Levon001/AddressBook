#include <vector>
#include "Contact.h"

class AddressBook {
    private:
        std::vector<Contact*> contacts;

    public:
        bool addContact(const std::string&, const std::string&, const std::string& );
        void showContacts();
        void remove(const std::string&); 
        static void writeInFile(Contact*);     
        bool updateContact(Contact*, const std::string&, const std::string&, const std::string&); 
        std::vector<Contact*> findContact(const std::string&);  
        void loadContactsFromFile(const std::string&);  

        void eraseWrite();

        static std::string cleanedPhoneNumber(const std::string&);
        static void eraseFileContents(const std::string&);
};