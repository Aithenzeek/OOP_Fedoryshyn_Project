#pragma once

class TicketUtils
{
public:
    static double CalculateDiscount(double price, double discountPercent);
    static bool IsValidPrice(double price);
    static void ShowPriceWithDiscount(double price, double discountPercent);

private:
    TicketUtils() = delete;
    ~TicketUtils() = delete;
};