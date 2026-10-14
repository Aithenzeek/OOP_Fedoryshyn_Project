#include "TicketPurchase.h"
#include <iostream>

TicketPurchase::TicketPurchase(
    int paymentId,
    double amount,
    const std::string& paymentMethod,
    const std::string& recipient,
    const std::string& message,
    const std::string& notificationType,
    int purchaseId,
    int ticketId,
    const std::string& concertName
)
// Пункт 5(4)
    : Payment(paymentId, amount, paymentMethod),
    Notification(recipient, message, notificationType),
    purchaseId(purchaseId),
    ticketId(ticketId),
    concertName(concertName)
{
    std::cout << "TicketPurchase constructor" << std::endl;
}

TicketPurchase::~TicketPurchase()
{
    std::cout << "TicketPurchase destructor. Purchase ID: "
        << purchaseId << std::endl;
}

void TicketPurchase::CompletePurchase()
{
    std::cout << "\n--- Ticket Purchase ---" << std::endl;
    std::cout << "Purchase ID: " << purchaseId << std::endl;
    std::cout << "Ticket ID: " << ticketId << std::endl;
    std::cout << "Concert: " << concertName << std::endl;

    ProcessPayment();
    SendNotification();
}