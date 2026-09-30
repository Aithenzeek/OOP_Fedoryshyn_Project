#include "TicketSale.h"

#include <iostream>

TicketSale::TicketSale(
    Visitor& visitor,
    Ticket& ticket,
    Manager& manager)
    : visitor_(visitor),
    ticket_(ticket),
    manager_(manager) {
}

void TicketSale::ProcessSale() {
    std::cout << "=== TICKET SALE ===" << std::endl;

    std::cout << "Visitor: "
        << visitor_.name << std::endl;

    std::cout << "Ticket ID: "
        << ticket_.id << std::endl;

    std::cout << "Manager: "
        << manager_.name << std::endl;

    if (visitor_.BuyTicket(ticket_)) {
        std::cout << "Ticket sale completed." << std::endl;
    }
    else {
        std::cout << "Ticket sale failed." << std::endl;
    }
}