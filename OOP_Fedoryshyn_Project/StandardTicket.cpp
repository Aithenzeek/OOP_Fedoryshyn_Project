#include "StandardTicket.h"
#include <iostream>

StandardTicket::StandardTicket(
    int id,
    const std::string& concertName,
    double basePrice)
    : TicketType(id, concertName, basePrice)
{
}

double StandardTicket::CalculatePrice() const
{
    return basePrice_;
}

void StandardTicket::ShowDetails() const
{
    std::cout << "\nStandard ticket" << std::endl;
    std::cout << "ID: " << id_ << std::endl;
    std::cout << "Concert: " << concertName_ << std::endl;
    std::cout << "Price: " << CalculatePrice() << " UAH" << std::endl;
}