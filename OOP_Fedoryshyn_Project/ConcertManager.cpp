#include "ConcertManager.h"

#include <iostream>

ConcertManager::ConcertManager(Manager& manager)
    : manager_(manager),
    ticket_(nullptr) {
}

void ConcertManager::AddTicket(Ticket& ticket) {
    ticket_ = &ticket;

    std::cout << "Ticket was added to manager's concert."
        << std::endl;
}

void ConcertManager::ShowTicket() {
    if (ticket_ == nullptr) {
        std::cout << "No ticket assigned." << std::endl;
        return;
    }

    std::cout << "Manager: "
        << manager_.name << std::endl;

    ticket_->ShowInfo();
}