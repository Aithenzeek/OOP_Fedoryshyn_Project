#pragma once

#include <string>
#include "Manager.h"

// Пункт 1(2) - Визначено користувацький клас Ticket згідно з варіантом завдання з не менше чим 8 полями
// Пункт 2(2) - надано класу мінімум 3 загальних та 5 приватних елементів та відображено викорастання усіх полів даних в методах
/* Пункт 4(2) - Визначено мінімум 6 методів, які опрацьовують описані дані(два методи перевантажені), 
де один метод приймає в якості параметрі об'єкт класу, а інший метод повертає тип класу*/
class Ticket
{
public:
    int id;
    double price;
    std::string concertName;

    // Пункт4(3) - Створення статичного поля
    static int ticketCount;

    // Пункт 1(3) - Визначення конструктора без параметрів
    Ticket();

    // Пункт 1(3) - Визначення конструктора з параметрами
    Ticket(int id, double price, const std::string& concert_name,
        const std::string& date, const std::string& time,
        const std::string& sector, int row, int seat,
        const std::string& ticket_type, bool is_sold);

    // Пункт 1(3) - Визначення конструктора копіювання
    Ticket(const Ticket& other);

    // Пункт 3(3) - Визначення деструктора
    ~Ticket();

    void ShowInfo();
    void ChangePrice(double newPrice);
    void ChangePrice(double newPrice, bool discount);
    bool Sell();
    bool CancelSale();
    bool CompareTicket(const Ticket& other);
    Ticket CreateCopy();

    // Пункт4(3) - Створення статичного метода
    static void ShowTicketCount();

    // Пункт 5(2) визначено в класі методи для запису у файл та читання з файлу полів даних
    void SaveToFile(const std::string& file_name);
    void LoadFromFile(const std::string& file_name);

    void GenerateAndSortPrices();

private:
    std::string date_;
    std::string time_;
    std::string sector_;
    int row_;
    int seat_;
    std::string ticketType_;
    bool isSold_;
};