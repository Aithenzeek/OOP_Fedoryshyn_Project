
#pragma once

#include <string>

class Person
{
public:
    int id;
    std::string name;
    std::string phone;
    std::string email;
    int age;
    std::string city;
    std::string address;
    bool isActive;

    Person();

    Person(
        int id,
        const std::string& name,
        const std::string& phone,
        const std::string& email,
        int age,
        const std::string& city,
        const std::string& address,
        bool isActive);

    Person(const Person& other);

    virtual ~Person();

    void ShowPersonInfo();
    void SetName(const std::string& newName);
    void SetPhone(const std::string& newPhone);
};