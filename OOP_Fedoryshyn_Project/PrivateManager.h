#pragma once

#include "Person.h"
#include <string>

// Пункт 3(4): додатковий клас із закритим успадкуванням.
class PrivateManager : private Person
{
public:
    PrivateManager(
        int id,
        const std::string& name,
        const std::string& phone,
        const std::string& email,
        int age,
        const std::string& city,
        const std::string& address,
        bool isActive);

    void ShowManagerInfo();
    void ChangeManagerName(const std::string& newName);
};