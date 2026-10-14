#pragma once

#include "Person.h"

// Пункт 2(4): public inheritance.
// Публічні члени Person залишаються public.
class PublicInheritanceDemo : public Person
{
public:
    PublicInheritanceDemo(
        int id,
        const std::string& name,
        const std::string& phone,
        const std::string& email,
        int age,
        const std::string& city,
        const std::string& address,
        bool isActive);

    void ShowAccess();
};

// Пункт 2(4): protected inheritance.
// Public-члени Person стають protected.
class ProtectedInheritanceDemo : protected Person
{
public:
    ProtectedInheritanceDemo(
        int id,
        const std::string& name,
        const std::string& phone,
        const std::string& email,
        int age,
        const std::string& city,
        const std::string& address,
        bool isActive);

    void ShowAccess();
};

// Пункт 2(4): private inheritance.
// Public-члени Person стають private.
class PrivateInheritanceDemo : private Person
{
public:
    PrivateInheritanceDemo(
        int id,
        const std::string& name,
        const std::string& phone,
        const std::string& email,
        int age,
        const std::string& city,
        const std::string& address,
        bool isActive);

    void ShowAccess();
};