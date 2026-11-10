#pragma once

#include <string>

class Payment
{
public:
    int paymentId;
    double amount;
    std::string paymentMethod;

    Payment();
    Payment(
        int paymentId,
        double amount,
        const std::string& paymentMethod);

    // Пункт 3(5) Віртуальний деструктор
    virtual ~Payment();

    // Пункт 4(5) Віртуальна функція
    virtual void ProcessPayment();

    virtual std::string GetRoleDescription() const;
};