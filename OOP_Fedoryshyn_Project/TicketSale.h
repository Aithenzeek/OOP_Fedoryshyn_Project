#pragma once

#include "Ticket.h"
#include "Visitor.h"
#include "Manager.h"

class TicketSale
{
public:
    TicketSale(
        Visitor& visitor,
        Ticket& ticket,
        Manager& manager);

    void ProcessSale();

private:
    Visitor& visitor_;
    Ticket& ticket_;
    Manager& manager_;
};