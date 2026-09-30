#include "Ticket.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>

// Пункт 4(3) Створення статичної властивості
int Ticket::ticketCount = 0;

// Пункт 1(3) - Визначення конструктора без параметрів
Ticket::Ticket()
    : id(0),
    price(0),
    concertName(""),
    date_(""),
    time_(""),
    sector_(""),
    row_(0),
    seat_(0),
    ticketType_(""),
    isSold_(false) {
    ticketCount++;
}

// Пункт 1(3) - Визначення конструктора з параметрами
Ticket::Ticket(int id, double price, const std::string& concert_name,
    const std::string& date, const std::string& time,
    const std::string& sector, int row, int seat,
    const std::string& ticket_type, bool is_sold)
    : id(id),
    price(price),
    concertName(concert_name),
    date_(date),
    time_(time),
    sector_(sector),
    row_(row),
    seat_(seat),
    ticketType_(ticket_type),
    isSold_(is_sold) {
    ticketCount++;
}

// Пункт 1(3) - Визначення конструктора копіювання
Ticket::Ticket(const Ticket& other)
    : id(other.id),
    price(other.price),
    concertName(other.concertName),
    date_(other.date_),
    time_(other.time_),
    sector_(other.sector_),
    row_(other.row_),
    seat_(other.seat_),
    ticketType_(other.ticketType_),
    isSold_(other.isSold_) {
    ticketCount++;
}

// Пункт 3(3) - Визначення деструктора
Ticket::~Ticket() {
    ticketCount--;

    std::cout << "Entering destruction of Ticket object. "
        << "Ticket ID: " << id << std::endl;
}

void Ticket::ShowInfo() 
{
    std::cout << "ID: " << id << std::endl;
    std::cout << "Concert: " << concertName << std::endl;
    std::cout << "Price: " << price << " UAH" << std::endl;
    std::cout << "Date: " << date_ << std::endl;
    std::cout << "Time: " << time_ << std::endl;
    std::cout << "Sector: " << sector_ << std::endl;
    std::cout << "Row: " << row_ << std::endl;
    std::cout << "Seat: " << seat_ << std::endl;
    std::cout << "Ticket type: " << ticketType_ << std::endl;
    std::cout << "Sold: " << (isSold_ ? "Yes" : "No") << std::endl;
}

void Ticket::ChangePrice(double new_price) 
{
    if (new_price > 0) {
        price = new_price;
    }
}

void Ticket::ChangePrice(double new_price, bool apply_discount) 
{
    if (new_price <= 0) 
    {
        return;
    }

    price = new_price;

    if (apply_discount) 
    {
        price *= 0.9;
    }
}

bool Ticket::Sell() 
{
    if (isSold_) 
    {
        return false;
    }

    isSold_ = true;
    return true;
}

bool Ticket::CancelSale() {
    if (!isSold_) {
        return false;
    }   

    isSold_ = false;
    return true;
}

bool Ticket::CompareTicket(const Ticket& other) 
{
    return price == other.price &&
        sector_ == other.sector_ &&
        row_ == other.row_ &&
        seat_ == other.seat_;
}

// Пункт 7 - Створення методу який повертає об'єкт класу
Ticket Ticket::CreateCopy() 
{
    Ticket copy(*this);

    copy.ShowInfo();

    return copy;
}

void Ticket::SaveToFile(const std::string& file_name) 
{
    std::ofstream file(file_name);

    if (!file.is_open()) 
    {
        std::cout << "Cannot open file." << std::endl;
        return;
    }

    file << id << std::endl;
    file << price << std::endl;
    file << concertName << std::endl;
    file << date_ << std::endl;
    file << time_ << std::endl;
    file << sector_ << std::endl;
    file << row_ << std::endl;
    file << seat_ << std::endl;
    file << ticketType_ << std::endl;
    file << isSold_ << std::endl;

    file.close();
}

void Ticket::LoadFromFile(const std::string& file_name) 
{
    std::ifstream file(file_name);

    if (!file.is_open()) 
    {
        std::cout << "Cannot open file." << std::endl;
        return;
    }

    file >> id;
    file >> price;

    file.ignore();
    getline(file, concertName);
    getline(file, date_);
    getline(file, time_);
    getline(file, sector_);

    file >> row_;
    file >> seat_;

    file.ignore();
    getline(file, ticketType_);

    file >> isSold_;

    file.close();
}

void Ticket::GenerateAndSortPrices()
{
    int size = 5 + rand() % 6;

    int* prices = new int[size];

    std::cout << std::endl;
    std::cout << "Random prices before sorting:" << std::endl;

    for (int i = 0; i < size; i++)
    {
        prices[i] = 500 + rand() % 1501;
        std::cout << prices[i] << " ";
    }

    std::sort(prices, prices + size);

    std::cout << std::endl;
    std::cout << "Prices after sorting:" << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << prices[i] << " ";
    }

    std::cout << std::endl;

    delete[] prices;
}

// Пункт 4(3) Створення статичного метода
void Ticket::ShowTicketCount() {
    std::cout << "Current number of Ticket objects: "
        << ticketCount << std::endl;
}