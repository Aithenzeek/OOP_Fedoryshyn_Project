#include "Service.h"
#include <iostream>
#include <new>

void Service_Static(Ticket tickets[], int& count, double minPrice)
{
    int newCount = 0;

    for (int i = 0; i < count; i++)
    {
        if (tickets[i].price >= minPrice)
        {
            if (newCount != i)
            {
                tickets[newCount] = tickets[i];
            }

            newCount++;
        }
    }

    count = newCount;

    std::cout << "Static array: removed tickets below "
        << minPrice << " UAH.\n";
}

void Service_Dinamic(Ticket*& tickets, int& count, double minPrice)
{
    int newCount = 0;

    for (int i = 0; i < count; i++)
    {
        if (tickets[i].price >= minPrice)
        {
            newCount++;
        }
    }

    Ticket* newTickets = nullptr;

    try
    {
        if (newCount > 0)
        {
            newTickets = new Ticket[newCount];

            int index = 0;

            for (int i = 0; i < count; i++)
            {
                if (tickets[i].price >= minPrice)
                {
                    newTickets[index] = tickets[i];
                    index++;
                }
            }
        }
    }
    catch (const std::bad_alloc& exception)
    {
        delete[] newTickets;

        std::cerr << "Memory allocation error: "
            << exception.what() << '\n';

        throw;
    }

    delete[] tickets;

    tickets = newTickets;
    count = newCount;

    std::cout << "Dynamic array: removed tickets below "
        << minPrice << " UAH.\n";
}