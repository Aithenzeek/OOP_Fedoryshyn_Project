#pragma once

#include "TicketType.h"

// Пункт 1(5) - Похідний клас VIP-квитка
class VipTicket : public TicketType
{
public:
    VipTicket(
        int id,
        const std::string& concertName,
        double basePrice,
        double extraCharge);

    double CalculatePrice() const override;
    void ShowDetails() const override;

private:
    double extraCharge_;
};