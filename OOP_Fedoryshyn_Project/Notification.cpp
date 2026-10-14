#include "Notification.h"

#include <iostream>

// Конструктор без параметрів.
Notification::Notification()
    : recipient(""),
    message(""),
    notificationType("")
{
    std::cout << "Notification default constructor" << std::endl;
}

// Конструктор із параметрами.
Notification::Notification(
    const std::string& recipient,
    const std::string& message,
    const std::string& notificationType)
    : recipient(recipient),
    message(message),
    notificationType(notificationType)
{
    std::cout << "Notification parameterized constructor"
        << std::endl;
}

// Деструктор.
Notification::~Notification()
{
    std::cout << "Notification destructor. Recipient: "
        << recipient << std::endl;
}

void Notification::SendNotification()
{
    std::cout << "Notification type: "
        << notificationType << std::endl;

    std::cout << "Recipient: " << recipient << std::endl;
    std::cout << "Message: " << message << std::endl;
}
