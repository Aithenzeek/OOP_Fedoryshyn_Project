#pragma once

#include "Payment.h"
#include "Notification.h"
#include <string>

class TicketPurchase : public Payment, public Notification
{
public:
    int purchaseId;
    int ticketId;
    std::string concertName;

    TicketPurchase(
        int paymentId,
        double amount,
        const std::string& paymentMethod,
        const std::string& recipient,
        const std::string& message,
        const std::string& notificationType,
        int purchaseId,
        int ticketId,
        const std::string& concertName
    );

    // Пункт 3(5) Перевизначення батьківського деструктора
    ~TicketPurchase() override;

    // Пункт 4(5) Перевизначення батьківських функцій
    virtual void CompletePurchase();
};