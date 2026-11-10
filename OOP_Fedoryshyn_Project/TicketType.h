#pragma once

#include <string>

// Пункт 1(5) - Абстрактний базовий клас для типів квитків
class TicketType
{
public:
    TicketType(int id, const std::string& concertName, double basePrice);

    virtual ~TicketType();

    // Пункт 4(5) - Чисто віртуальні функції
    virtual double CalculatePrice() const = 0;
    virtual void ShowDetails() const = 0;

    int GetId() const;
    double GetBasePrice() const;
    std::string GetConcertName() const;

protected:
    int id_;
    std::string concertName_;
    double basePrice_;
};