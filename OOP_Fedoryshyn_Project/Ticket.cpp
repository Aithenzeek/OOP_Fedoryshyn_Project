#include "Ticket.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>

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
}

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

bool Ticket::CompareTicket(const Ticket& other) 
{
    return price == other.price &&
        sector_ == other.sector_ &&
        row_ == other.row_ &&
        seat_ == other.seat_;
}

Ticket Ticket::CreateCopy() 
{
    return *this;
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

Visitor::Visitor()
    : id(0),
    name(""),
    phone(""),
    email_(""),
    age_(0),
    city_(""),
    balance_(0),
    purchasedTickets_(0),
    hasDiscount_(false),
    ticket_() {
}

Visitor::Visitor(int id, const std::string& name, const std::string& phone)
    : id(id),
    name(name),
    phone(phone),
    email_(""),
    age_(0),
    city_(""),
    balance_(0),
    purchasedTickets_(0),
    hasDiscount_(false),
    ticket_() {
}

void Visitor::ShowInfo() 
{
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Phone: " << phone << std::endl;
    std::cout << "Email: " << email_ << std::endl;
    std::cout << "Age: " << age_ << std::endl;
    std::cout << "City: " << city_ << std::endl;
    std::cout << "Balance: " << balance_ << " UAH" << std::endl;
    std::cout << "Purchased tickets: " << purchasedTickets_ << std::endl;
    std::cout << "Discount: " << (hasDiscount_ ? "Yes" : "No") << std::endl;

    std::cout << "Visitor's ticket:" << std::endl;
    ticket_.ShowInfo();
}

void Visitor::AddBalance(double amount)
{
    if (amount > 0) {
        balance_ += amount;
    }
}

void Visitor::AddBalance(double amount, bool bonus) 
{
    if (amount <= 0)
    {
        return;
    }

    balance_ += amount;

    if (bonus) {
        balance_ += amount * 0.1;
    }
}

bool Visitor::BuyTicket(Ticket& newTicket) 
{
    if (newTicket.price > balance_) 
    {
        return false;
    }

    if (!newTicket.Sell()) 
    {
        return false;
    }

    balance_ -= newTicket.price;
    purchasedTickets_++;

    ticket_ = newTicket;

    return true;
}

bool Visitor::CompareVisitor(const Visitor& other) 
{
    return name == other.name &&
        phone == other.phone &&
        city_ == other.city_;
}

Visitor Visitor::CreateCopy() 
{
    return *this;
}

void Visitor::SaveToFile(const std::string& file_name) 
{
    std::ofstream file(file_name);

    if (!file.is_open()) 
    {
        std::cout << "Cannot open file." << std::endl;
        return;
    }

    file << id << std::endl;
    file << name << std::endl;
    file << phone << std::endl;
    file << email_ << std::endl;
    file << age_ << std::endl;
    file << city_ << std::endl;
    file << balance_ << std::endl;
    file << purchasedTickets_ << std::endl;
    file << hasDiscount_ << std::endl;

    file.close();
}

void Visitor::LoadFromFile(const std::string& file_name) 
{
    std::ifstream file(file_name);

    if (!file.is_open()) 
    {
        std::cout << "Cannot open file." << std::endl;
        return;
    }

    file >> id;

    file.ignore();
    getline(file, name);
    getline(file, phone);
    getline(file, email_);

    file >> age_;

    file.ignore();
    getline(file, city_);

    file >> balance_;
    file >> purchasedTickets_;
    file >> hasDiscount_;

    file.close();
}