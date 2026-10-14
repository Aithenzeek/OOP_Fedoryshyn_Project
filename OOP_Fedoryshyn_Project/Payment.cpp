#include "Payment.h"

#include <iostream>

// Конструктор без параметрів.
Payment::Payment()
    : paymentId(0),
    amount(0.0),
    paymentMethod("")
{
    std::cout << "Payment default constructor" << std::endl;
}

// Конструктор із параметрами.
Payment::Payment(
    int paymentId,
    double amount,
    const std::string& paymentMethod)
    : paymentId(paymentId),
    amount(amount),
    paymentMethod(paymentMethod)
{
    std::cout << "Payment parameterized constructor" << std::endl;
}

// Деструктор.
Payment::~Payment()
{
    std::cout << "Payment destructor. ID: "
        << paymentId << std::endl;
}

void Payment::ProcessPayment()
{
    if (amount > 0)
    {
        std::cout << "Payment #" << paymentId
            << ": " << amount << " UAH"
            << ", method: " << paymentMethod
            << std::endl;
    }
    else
    {
        std::cout << "Invalid payment amount." << std::endl;
    }
}
