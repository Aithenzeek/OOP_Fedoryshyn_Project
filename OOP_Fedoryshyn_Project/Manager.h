#pragma once
#include <string>
#include "Person.h"

// Пункт 1(4) - Визначення ієрархії класів
class Manager : public Person
{
public:
    std::string concert_name;

    // Пункт 1(3) - Визначення конструктора без параметрів
    // Пункт 2(3) - Визначення конструкторів за допомогою списку ініціалізації
    Manager();

    // Пункт 1(3) - Визначення конструктора з параметрами
    Manager(int id, const std::string& name,
        const std::string& concert_name,
        const std::string& date,
        const std::string& time,
        const std::string& place,
        const std::string& singer,
        double refund_percent);

    // Пункт 1(3) - Визначення конструктора копіювання
    Manager(const Manager& other);

    // Пункт 3(3) - Визначення деструктора
    ~Manager() override;

    void ShowInfo();
    void SetConcertTime(const std::string& time);
    void SetConcertPlace(const std::string& place);
    void SetRefundPercent(double percent);
    void InformSinger();
    void ShowConstAndReference();
    double GetRefundPercent();
    Manager CreateCopy();

private:
    std::string date_;
    std::string time_;
    std::string place_;
    std::string singer_;
    double refund_percent_;
    const int managerCode_;
    const std::string& managerNameReference_;
};