#include "StudentTicket.h"
#include <iostream>

StudentTicket::StudentTicket(
    int id,
    const std::string& concertName,
    double basePrice,
    double discountPercent)
    : TicketType(id, concertName, basePrice),
    discountPercent_(discountPercent)
{
}

double StudentTicket::CalculatePrice() const
{
    return basePrice_ * (1.0 - discountPercent_ / 100.0);
}

void StudentTicket::ShowDetails() const
{
    std::cout << "\nStudent ticket" << std::endl;
    std::cout << "ID: " << id_ << std::endl;
    std::cout << "Concert: " << concertName_ << std::endl;
    std::cout << "Discount: " << discountPercent_ << "%" << std::endl;
    std::cout << "Price: " << CalculatePrice() << " UAH" << std::endl;
}