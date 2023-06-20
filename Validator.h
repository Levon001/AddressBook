#include <string>

class Validator {
    public:
        virtual bool check(const std::string&) = 0;
};

class NameValidator : public Validator {
    public:
        bool check (const std::string&);
    private:
        std::string trimString(const std::string&);
};

class PhoneNumberValidator : public Validator {
    public:
        bool check (const std::string&);
    private:
        std::string deleteSpace(const std::string&);
        bool regionCode(const std::string&);
        bool isNumber(const std::string&);
};

class EmailValidator : public Validator {
    public:
        bool check(const std::string&);
    private:
        bool domaimName(const std::string&);
        bool thereIsDog(const std::string&);
        bool lengthLocalPart(const std::string&);
        bool doubleSymbols(const std::string&);
};

