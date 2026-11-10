#pragma once

#include "TicketType.h"

// Пункт 1(5) - Похідний клас студентського квитка
class StudentTicket : public TicketType
{
public:
    StudentTicket(
        int id,
        const std::string& concertName,
        double basePrice,
        double discountPercent);

    double CalculatePrice() const override;
    void ShowDetails() const override;

private:
    double discountPercent_;
};