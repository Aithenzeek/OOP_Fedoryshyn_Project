#include "TicketType.h"

TicketType::TicketType(
    int id,
    const std::string& concertName,
    double basePrice)
    : id_(id),
    concertName_(concertName),
    basePrice_(basePrice)
{
}

TicketType::~TicketType() = default;

int TicketType::GetId() const
{
    return id_;
}

double TicketType::GetBasePrice() const
{
    return basePrice_;
}

std::string TicketType::GetConcertName() const
{
    return concertName_;
}