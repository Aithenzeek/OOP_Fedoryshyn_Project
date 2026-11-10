#include "TicketManager.h"
#include <iostream>
#include <stdexcept>

TicketManager::TicketManager()
    : tickets_(nullptr), count_(0), capacity_(5)
{
    tickets_ = new Ticket * [capacity_] {};
}

TicketManager::~TicketManager()
{
    ClearTickets();
    delete[] tickets_;
}

void TicketManager::Resize()
{
    int newCapacity = capacity_ * 2;

    Ticket** newTickets = new Ticket * [newCapacity] {};

    for (int i = 0; i < count_; i++)
    {
        newTickets[i] = tickets_[i];
    }

    delete[] tickets_;

    tickets_ = newTickets;
    capacity_ = newCapacity;
}

void TicketManager::AddTicket(const Ticket& ticket)
{
    if (count_ == capacity_)
    {
        Resize();
    }

    Ticket* newTicket = new Ticket(ticket);

    tickets_[count_] = newTicket;
    count_++;
}

void TicketManager::ShowTickets() const
{
    if (count_ == 0)
    {
        std::cout << "There are no tickets.\n";
        return;
    }

    for (int i = 0; i < count_; i++)
    {
        tickets_[i]->ShowInfo();
    }
}

void TicketManager::RemoveTicket(int ticketId)
{
    int index = -1;

    for (int i = 0; i < count_; i++)
    {
        if (tickets_[i]->id == ticketId)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        throw std::runtime_error("Ticket not found.");
    }

    delete tickets_[index];

    for (int i = index; i < count_ - 1; i++)
    {
        tickets_[i] = tickets_[i + 1];
    }

    tickets_[count_ - 1] = nullptr;
    count_--;
}

void TicketManager::ClearTickets()
{
    for (int i = 0; i < count_; i++)
    {
        delete tickets_[i];
        tickets_[i] = nullptr;
    }

    count_ = 0;
}