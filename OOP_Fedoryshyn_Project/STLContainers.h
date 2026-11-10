#pragma once

#include "Ticket.h"

struct TicketPriceLess
{
    bool operator()(const Ticket& first, const Ticket& second) const
    {
        if (first.price == second.price)
        {
            return first.id < second.id;
        }

        return first.price < second.price;
    }
};

struct TicketPriceOnly
{
    bool operator()(const Ticket& first, const Ticket& second) const
    {
        return first.price < second.price;
    }
};

void RunSTLContainersDemo();

// Пункт 2(7) — демонстрація категорій ітераторів
void RunSTLIteratorsDemo();

// Пункт 3(7) — демонстрація алгоритмів STL
void RunSTLAlgorithmsDemo();

// Пункт 4(7) — демонстрація функціональних об'єктів STL
void RunSTLFunctorsDemo();
