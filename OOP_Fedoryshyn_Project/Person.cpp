#include "Person.h"

#include <iostream>

Person::Person()
    : id(0),
    name(""),
    phone(""),
    email(""),
    age(0),
    city(""),
    address(""),
    isActive(true)
{
    std::cout << "Person default constructor" << std::endl;
}

Person::Person(
    int id,
    const std::string& name,
    const std::string& phone,
    const std::string& email,
    int age,
    const std::string& city,
    const std::string& address,
    bool isActive)
    : id(id),
    name(name),
    phone(phone),
    email(email),
    age(age),
    city(city),
    address(address),
    isActive(isActive)
{
    std::cout << "Person parameterized constructor" << std::endl;
}

Person::Person(const Person& other)
    : id(other.id),
    name(other.name),
    phone(other.phone),
    email(other.email),
    age(other.age),
    city(other.city),
    address(other.address),
    isActive(other.isActive)
{
    std::cout << "Person copy constructor" << std::endl;
}

Person::~Person()
{
    std::cout << "Person destructor: " << name << std::endl;
}

void Person::ShowPersonInfo()
{
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Phone: " << phone << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "City: " << city << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Active: " << (isActive ? "Yes" : "No")
        << std::endl;
}

void Person::SetName(const std::string& newName)
{
    name = newName;
}

void Person::SetPhone(const std::string& newPhone)
{
    phone = newPhone;
}
