#pragma once

#include <string>

// Пункт 1 - Визначено користувацький клас Ticket згідно з варіантом завдання з не менше чим 8 полями
// Пункт 2 - надано класу мінімум 3 загальних та 5 приватних елементів та відображено викорастання усіх полів даних в методах
/* Пункт 4 - Визначено мінімум 6 методів, які опрацьовують описані дані(два методи перевантажені), 
де один метод приймає в якості параметрі об'єкт класу, а інший метод повертає тип класу*/
class Ticket
{
public:
    int id;
    double price;
    std::string concertName;

    Ticket();
    Ticket(int id, double price, const std::string& concert_name,
        const std::string& date, const std::string& time,
        const std::string& sector, int row, int seat,
        const std::string& ticket_type, bool is_sold);

    void ShowInfo();
    void ChangePrice(double newPrice);
    void ChangePrice(double newPrice, bool discount);
    bool Sell();
    bool CompareTicket(const Ticket& other);
    Ticket CreateCopy();

    // Пункт 5 визначено в класі методи для запису у файл та читання з файлу полів даних
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

// Пункт 1 - Визначено користувацький клас Visitor згідно з варіантом завдання з не менше чим 8 полями
// Пункт 2 - надано класу мінімум 3 загальних та 5 приватних елементів та відображено викорастання усіх полів даних в методах
/* Пункт 4 - Визначено мінімум 6 методів, які опрацьовують описані дані(два методи перевантажені),
де один метод приймає в якості параметрі об'єкт класу, а інший метод повертає тип класу*/
class Visitor
{
public:
    int id;
    std::string name;
    std::string phone;

    Visitor();
    Visitor(int id, const std::string& name, const std::string& phone);

    void ShowInfo();
    void AddBalance(double amount);
    void AddBalance(double amount, bool bonus);
    bool BuyTicket(Ticket& newTicket);
    bool CompareVisitor(const Visitor& other);
    Visitor CreateCopy();

    // Пункт 5 визначено в класі методи для запису у файл та читання з файлу полів даних
    void SaveToFile(const std::string& file_name);
    void LoadFromFile(const std::string& file_name);

private:
    std::string email_;
    int age_;
    std::string city_;
    double balance_;
    int purchasedTickets_;
    bool hasDiscount_;
    // Пункт 3 - забезпечено зв'язок двох об'єктів шляхом розміщення об'єкта одного класу в іншому без використання дружніх функцій
    Ticket ticket_;
};


