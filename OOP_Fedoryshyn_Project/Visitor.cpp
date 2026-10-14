#include "Visitor.h"
#include <iostream>
#include <fstream>
#include "Person.h"

// Пункт 1(3) - Визначення конструктора без параметрів
Visitor::Visitor()
    : Person(),
    email_(""),
    age_(0),
    city_(""),
    balance_(0),
    purchasedTickets_(0),
    hasDiscount_(false),
    ticket_(),
    registrationDate_("")
{
    std::cout << "Visitor default constructor" << std::endl;
}

// Пункт 1(3) - Визначення конструктора з параметрами
Visitor::Visitor(
    int id,
    const std::string& name,
    const std::string& phone)
    : Person(
        id,
        name,
        phone,
        "",
        0,
        "",
        "",
        true),
    email_(""),
    age_(0),
    city_(""),
    balance_(0.0),
    purchasedTickets_(0),
    hasDiscount_(false),
    ticket_(),
    registrationDate_("")
{
    std::cout << "Visitor parameterized constructor" << std::endl;
}
 
// Пункт 5(4): конструктор похідного класу передає параметри
// базовому конструктору Person і ініціалізує власні поля.
Visitor::Visitor(
    int id,
    const std::string& name,
    const std::string& phone,
    const std::string& email,
    int age,
    const std::string& city,
    const std::string& address,
    bool isActive,
    double balance,
    int purchasedTickets,
    bool hasDiscount)
    : Person(
        id,
        name,
        phone,
        email,
        age,
        city,
        address,
        isActive),
    email_(email),
    age_(age),
    city_(city),
    balance_(balance),
    purchasedTickets_(purchasedTickets),
    hasDiscount_(hasDiscount),
    ticket_()
{
    std::cout << "Visitor parameterized constructor"
        << std::endl;
}

// Пункт 1(3) - Визначення конструктора копіювання
Visitor::Visitor(const Visitor& other)
    : Person(other),
    email_(other.email_),
    age_(other.age_),
    city_(other.city_),
    balance_(other.balance_),
    purchasedTickets_(other.purchasedTickets_),
    hasDiscount_(other.hasDiscount_),
    ticket_(other.ticket_),
    registrationDate_(other.registrationDate_)
{
    std::cout << "Visitor copy constructor" << std::endl;
}

// Пункт 3(3) - Визначення деструктора
Visitor::~Visitor()
{
    std::cout << "Visitor destructor" << std::endl;
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

bool Visitor::BuyTicketOnline(Ticket& new_ticket) {
    if (new_ticket.price > balance_) {
        return false;
    }

    if (!new_ticket.Sell()) {
        return false;
    }

    balance_ -= new_ticket.price;
    purchasedTickets_++;
    ticket_ = new_ticket;

    return true;
}

bool Visitor::CancelTicket(Ticket& ticket, Manager& manager) {
    if (!ticket.CancelSale()) {
        return false;
    }

    double refund = ticket.price * manager.GetRefundPercent() / 100.0;

    balance_ += refund;

    if (purchasedTickets_ > 0) {
        purchasedTickets_--;
    }

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

void Visitor::SetTicket(
    int id,
    double price,
    const std::string& concert_name,
    const std::string& date,
    const std::string& time,
    const std::string& sector,
    int row,
    int seat,
    const std::string& ticket_type,
    bool is_sold) {

    ticket_ = Ticket(
        id,
        price,
        concert_name,
        date,
        time,
        sector,
        row,
        seat,
        ticket_type,
        is_sold
    );
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

// Пункт 6(4): доступ до членів і методів базового класу.
void Visitor::ShowBaseClassAccess()
{
    std::cout << "\n--- Base class access ---" << std::endl;

    // Оператор :: для доступу до членів базового класу.
    std::cout << "Name through Person::name: "
        << Person::name << std::endl;

    std::cout << "Phone through Person::phone: "
        << Person::phone << std::endl;

    // Явний виклик методу базового класу через оператор ::.
    Person::ShowPersonInfo();

    // Методи, доступ до яких оголошено через using.
    SetName("Updated Visitor");
    SetPhone("+380001112233");

    std::cout << "\nUpdated data through using:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Phone: " << phone << std::endl;
}