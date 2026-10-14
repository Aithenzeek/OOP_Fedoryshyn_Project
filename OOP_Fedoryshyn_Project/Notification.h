#pragma once

#include <string>

class Notification
{
public:
    std::string recipient;
    std::string message;
    std::string notificationType;

    Notification();

    Notification(
        const std::string& recipient,
        const std::string& message,
        const std::string& notificationType);

    ~Notification();

    void SendNotification();
};