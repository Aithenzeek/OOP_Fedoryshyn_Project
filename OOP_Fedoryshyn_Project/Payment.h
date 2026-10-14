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

    ~Payment();

    void ProcessPayment();
};