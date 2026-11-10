#include "VipTicket.h"
#include <iostream>

VipTicket::VipTicket(
    int id,
    const std::string& concertName,
    double basePrice,
    double extraCharge)
    : TicketType(id, concertName, basePrice),
    extraCharge_(extraCharge)
{
}

double VipTicket::CalculatePrice() const
{
    return basePrice_ + extraCharge_;
}

void VipTicket::ShowDetails() const
{
    std::cout << "\nVIP ticket" << std::endl;
    std::cout << "ID: " << id_ << std::endl;
    std::cout << "Concert: " << concertName_ << std::endl;
    std::cout << "Extra charge: " << extraCharge_ << " UAH" << std::endl;
    std::cout << "Price: " << CalculatePrice() << " UAH" << std::endl;
}