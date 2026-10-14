#include "PrivateManager.h"

#include <iostream>

// Передаємо всі параметри конструктору базового класу Person.
PrivateManager::PrivateManager(
    int id,
    const std::string& name,
    const std::string& phone,
    const std::string& email,
    int age,
    const std::string& city,
    const std::string& address,
    bool isActive)
    : Person(
        id,
        name,
        phone,
        email,
        age,
        city,
        address,
        isActive)
{
    std::cout << "PrivateManager constructor" << std::endl;
}

// Використання методу базового класу всередині похідного.
void PrivateManager::ShowManagerInfo()
{
    std::cout << "\n--- Private Manager ---" << std::endl;

    // Метод Person доступний всередині PrivateManager.
    ShowPersonInfo();
}

// Використання методу зміни даних базового класу.
void PrivateManager::ChangeManagerName(const std::string& newName)
{
    SetName(newName);
}