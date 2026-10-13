#include "TicketUtils.h"

#include <iostream>

double TicketUtils::CalculateDiscount(
    double price,
    double discountPercent)
{
    return price - price * discountPercent / 100.0;
}

bool TicketUtils::IsValidPrice(double price)
{
    return price > 0;
}

void TicketUtils::ShowPriceWithDiscount(
    double price,
    double discountPercent)
{
    double newPrice = CalculateDiscount(price, discountPercent);

    std::cout << "Original price: "
        << price << std::endl;

    std::cout << "Discount: "
        << discountPercent << "%" << std::endl;

    std::cout << "Price after discount: "
        << newPrice << std::endl;
}