#pragma once

#include "Visitor.h"
#include "Manager.h"

// Пункт 2(5) - Множинне віртуальне наслідування
class StaffMember : public Visitor, public Manager
{
public:
    StaffMember(
        int id,
        const std::string& name,
        const std::string& phone,
        const std::string& email,
        int age,
        const std::string& city,
        const std::string& address,
        const std::string& concertName,
        const std::string& date,
        const std::string& time,
        const std::string& place,
        const std::string& singer);

    ~StaffMember() override;

    void ShowStaffInfo() const;

    // Пункт 4(5) Перевизначення батьківських віртуальних функцій
    std::string GetRoleDescription() const override;
};