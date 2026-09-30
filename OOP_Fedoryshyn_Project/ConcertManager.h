#pragma once

#include "Manager.h"
#include "Ticket.h"

class ConcertManager
{
public:
    ConcertManager(Manager& manager);

    void AddTicket(Ticket& ticket);
    void ShowTicket();

private:
    Manager& manager_;
    Ticket* ticket_;
};