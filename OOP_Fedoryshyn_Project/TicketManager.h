#pragma once

#include "Ticket.h"

class TicketManager
{
public:
    TicketManager();
    ~TicketManager();

    TicketManager(const TicketManager&) = delete;
    TicketManager& operator=(const TicketManager&) = delete;

    void AddTicket(const Ticket& ticket);
    void ShowTickets() const;
    void RemoveTicket(int ticketId);
    void ClearTickets();

private:
    Ticket** tickets_;
    int count_;
    int capacity_;

    void Resize();
};