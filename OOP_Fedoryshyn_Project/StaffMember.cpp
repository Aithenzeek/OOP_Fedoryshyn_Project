#include "StaffMember.h"
#include <iostream>

StaffMember::StaffMember(
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
    const std::string& singer)
    : Person(
        id,
        name,
        phone,
        email,
        age,
        city,
        address,
        true),
    Visitor(
        id,
        name,
        phone,
        email,
        age,
        city,
        address,
        true,
        0.0,
        0,
        false),
    Manager(
        id,
        name,
        concertName,
        date,
        time,
        place,
        singer,
        100.0)
{
    std::cout << "StaffMember constructor" << std::endl;
}

StaffMember::~StaffMember()
{
    std::cout << "StaffMember destructor" << std::endl;
}

void StaffMember::ShowStaffInfo() const
{
    std::cout << "\n--- Staff member ---" << std::endl;
    std::cout << "ID: " << Person::id << std::endl;
    std::cout << "Name: " << Person::name << std::endl;
    std::cout << "Phone: " << Person::phone << std::endl;
    std::cout << "Email: " << Person::email << std::endl;
}

std::string StaffMember::GetRoleDescription() const
{
    return "Concert staff member";
}