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

    // Пункт 3(5) Віртуальний деструктор
    virtual ~Notification();

    // Пункт 4(5) Віртуальна функція
    virtual void SendNotification();
};