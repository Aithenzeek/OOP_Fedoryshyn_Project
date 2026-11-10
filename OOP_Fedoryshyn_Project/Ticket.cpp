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
    isSold_(false) 
{
    ticketCount++;
    //std::cout << "Ticket default constructor" << std::endl;
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
    isSold_(is_sold) 
{
    ticketCount++;
    //std::cout << "Ticket parameterized constructor" << std::endl;
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
    isSold_(other.isSold_) 
{
    ticketCount++;
    //std::cout << "Ticket copy constructor" << std::endl;
}

// Пункт 3(3) - Визначення деструктора
Ticket::~Ticket()
{
    ticketCount--;

    /*std::cout << "Ticket destructor. ID: "
        << id << std::endl;*/
}

void Ticket::ShowInfo() const
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

// Пункт 1(6) — префіксний оператор ++
Ticket& Ticket::operator++()
{
    ++price;
    return *this;
}

// Пункт 1(6) — постфіксний оператор ++
Ticket Ticket::operator++(int)
{
    Ticket oldTicket(*this);
    price++;
    return oldTicket;
}

// Пункт 1(6) — префіксний оператор --
Ticket& Ticket::operator--()
{
    if (price >= 1)
    {
        --price;
    }

    return *this;
}

// Пункт 1(6) — постфіксний оператор --
Ticket Ticket::operator--(int)
{
    Ticket oldTicket(*this);

    if (price >= 1)
    {
        price--;
    }

    return oldTicket;
}

// Пункт 2(6) — перевантаження оператора +
Ticket Ticket::operator+(const Ticket& other) const
{
    Ticket result(*this);
    result.price = price + other.price;

    return result;
}

// Пункт 2(6) — перевантаження оператора -
Ticket Ticket::operator-(const Ticket& other) const
{
    Ticket result(*this);
    result.price = price - other.price;

    if (result.price < 0)
    {
        result.price = 0;
    }

    return result;
}

// Пункт 3(6) — оператор множення
Ticket Ticket::operator*(double multiplier) const
{
    Ticket result(*this);
    result.price *= multiplier;

    return result;
}

// Пункт 3(6) — оператор присвоєння
Ticket& Ticket::operator=(const Ticket& other)
{
    if (this != &other)
    {
        id = other.id;
        price = other.price;
        concertName = other.concertName;
        date_ = other.date_;
        time_ = other.time_;
        sector_ = other.sector_;
        row_ = other.row_;
        seat_ = other.seat_;
        ticketType_ = other.ticketType_;
        isSold_ = other.isSold_;
    }

    return *this;
}

// Пункт 3(6) — оператор +=
Ticket& Ticket::operator+=(const Ticket& other)
{
    price += other.price;
    return *this;
}

// Пункт 3(6) — оператор -=
Ticket& Ticket::operator-=(const Ticket& other)
{
    price -= other.price;

    if (price < 0)
    {
        price = 0;
    }

    return *this;
}

// Пункт 3(6) — оператор *=
Ticket& Ticket::operator*=(double multiplier)
{
    price *= multiplier;
    return *this;
}

// Пункт 3(6) — оператор [] для зміни символу назви концерту
char& Ticket::operator[](std::size_t index)
{
    if (index >= concertName.size())
    {
        throw std::out_of_range("Concert name index is out of range.");
    }

    return concertName[index];
}

// Пункт 3(6) — константний оператор []
const char& Ticket::operator[](std::size_t index) const
{
    if (index >= concertName.size())
    {
        throw std::out_of_range("Concert name index is out of range.");
    }

    return concertName[index];
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

// Пункт 7(5) Створення методу запису
void Ticket::Write(std::ostream& out) const
{
    out << id << '\n';
    out << price << '\n';
    out << std::quoted(concertName) << '\n';
    out << std::quoted(date_) << '\n';
    out << std::quoted(time_) << '\n';
    out << std::quoted(sector_) << '\n';
    out << row_ << '\n';
    out << seat_ << '\n';
    out << std::quoted(ticketType_) << '\n';
    out << isSold_ << '\n';

    if (!out)
    {
        throw std::runtime_error("Failed to write ticket data.");
    }
}

// Пункт 7(5) Створення методу читання
void Ticket::Read(std::istream& in)
{
    in >> id;
    in >> price;
    in >> std::quoted(concertName);
    in >> std::quoted(date_);
    in >> std::quoted(time_);
    in >> std::quoted(sector_);
    in >> row_;
    in >> seat_;
    in >> std::quoted(ticketType_);
    in >> isSold_;

    if (!in)
    {
        throw std::runtime_error("Failed to read ticket data.");
    }
}