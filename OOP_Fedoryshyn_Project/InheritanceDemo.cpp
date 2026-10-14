#include "InheritanceDemo.h"

#include <iostream>

PublicInheritanceDemo::PublicInheritanceDemo(
    int id,
    const std::string& name,
    const std::string& phone,
    const std::string& email,
    int age,
    const std::string& city,
    const std::string& address,
    bool isActive)
    : Person(id, name, phone, email, age, city, address, isActive)
{
    std::cout << "PublicInheritanceDemo constructor" << std::endl;
}

void PublicInheritanceDemo::ShowAccess()
{
    std::cout << "\n--- Public inheritance ---" << std::endl;

    // Доступ до трьох полів базового класу.
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Phone: " << phone << std::endl;

    // Доступ до трьох методів базового класу.
    ShowPersonInfo();
    SetName("Updated Public Name");
    SetPhone("+380001112233");

    std::cout << "Updated name: " << name << std::endl;
    std::cout << "Updated phone: " << phone << std::endl;
}


ProtectedInheritanceDemo::ProtectedInheritanceDemo(
    int id,
    const std::string& name,
    const std::string& phone,
    const std::string& email,
    int age,
    const std::string& city,
    const std::string& address,
    bool isActive)
    : Person(id, name, phone, email, age, city, address, isActive)
{
    std::cout << "ProtectedInheritanceDemo constructor" << std::endl;
}

void ProtectedInheritanceDemo::ShowAccess()
{
    std::cout << "\n--- Protected inheritance ---" << std::endl;

    // Public-члени Person доступні всередині похідного класу
    // як protected.
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Phone: " << phone << std::endl;

    ShowPersonInfo();
    SetName("Updated Protected Name");
    SetPhone("+380004445566");

    std::cout << "Updated name: " << name << std::endl;
    std::cout << "Updated phone: " << phone << std::endl;
}


PrivateInheritanceDemo::PrivateInheritanceDemo(
    int id,
    const std::string& name,
    const std::string& phone,
    const std::string& email,
    int age,
    const std::string& city,
    const std::string& address,
    bool isActive)
    : Person(id, name, phone, email, age, city, address, isActive)
{
    std::cout << "PrivateInheritanceDemo constructor" << std::endl;
}

void PrivateInheritanceDemo::ShowAccess()
{
    std::cout << "\n--- Private inheritance ---" << std::endl;

    // Public-члени Person доступні всередині цього класу
    // як private.
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Phone: " << phone << std::endl;

    ShowPersonInfo();
    SetName("Updated Private Name");
    SetPhone("+380007778899");

    std::cout << "Updated name: " << name << std::endl;
    std::cout << "Updated phone: " << phone << std::endl;
}