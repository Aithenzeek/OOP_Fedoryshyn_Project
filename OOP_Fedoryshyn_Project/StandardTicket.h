#pragma once

#include "TicketType.h"

// Пункт 1(5) - Похідний клас звичайного квитка
class StandardTicket : public TicketType
{
public:
    StandardTicket(
        int id,
        const std::string& concertName,
        double basePrice);

    double CalculatePrice() const override;
    void ShowDetails() const override;
};