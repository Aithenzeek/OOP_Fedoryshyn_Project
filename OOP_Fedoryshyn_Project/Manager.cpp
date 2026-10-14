#include "Manager.h"
#include <iostream>

// Пункт 1(3) - Визначення конструктора без параметрів
// Пункт 2(3) - Визначення конструкторів за допомогою списку ініціалізації
Manager::Manager()
    : Person(),
    concert_name(""),
    managerCode_(0),
    managerNameReference_(name),
    date_(""),
    time_(""),
    place_(""),
    singer_(""),
    refund_percent_(0.0) 
{
    std::cout << "Manager default constructor" << std::endl;
}

// Пункт 1(3) - Визначення конструктора з параметрами
Manager::Manager(
    int id,
    const std::string& name,
    const std::string& concert_name,
    const std::string& date,
    const std::string& time,
    const std::string& place,
    const std::string& singer,
    double refund_percent)
    : Person(
        id,
        name,
        "",
        "",
        0,
        "",
        "",
        true),
    concert_name(concert_name),
    managerCode_(id),
    managerNameReference_(this->name),
    date_(date),
    time_(time),
    place_(place),
    singer_(singer),
    refund_percent_(refund_percent)
{
    std::cout << "Manager parameterized constructor" << std::endl;
}

// Пункт 1(3) - Визначення конструктора копіювання
Manager::Manager(const Manager& other)
    : Person(other),
    concert_name(other.concert_name),
    managerCode_(other.managerCode_),
    managerNameReference_(this->name),
    date_(other.date_),
    time_(other.time_),
    place_(other.place_),
    singer_(other.singer_),
    refund_percent_(other.refund_percent_)
{
    std::cout << "Manager copy constructor" << std::endl;
}

// Пункт 3(3) - Визначення деструктора
Manager::~Manager()
{
    std::cout << "Manager destructor. Manager ID: "
        << id << std::endl;
}

double Manager::GetRefundPercent() 
{
    return refund_percent_;
}

void Manager::SetRefundPercent(double percent) 
{
    if (percent < 0.0) 
    {
        refund_percent_ = 0.0;
    }
    else if (percent > 100.0) 
    {
        refund_percent_ = 100.0;
    }
    else {
        refund_percent_ = percent;
    }
}

void Manager::ShowInfo() {
    std::cout << "Manager ID: " << id << std::endl;
    std::cout << "Manager name: " << name << std::endl;
    std::cout << "Concert: " << concert_name << std::endl;
    std::cout << "Date: " << date_ << std::endl;
    std::cout << "Time: " << time_ << std::endl;
    std::cout << "Place: " << place_ << std::endl;
    std::cout << "Singer: " << singer_ << std::endl;
    std::cout << "Refund percentage: "
        << refund_percent_ << "%" << std::endl;
}

void Manager::SetConcertTime(const std::string& time) {
    time_ = time;
}

void Manager::SetConcertPlace(const std::string& place) {
    place_ = place;
}

void Manager::InformSinger() {
    std::cout << "Singer " << singer_
        << " was informed about the concert." << std::endl;
}

void Manager::ShowConstAndReference() {
    std::cout << "Manager code: "
        << managerCode_ << std::endl;

    std::cout << "Manager name: "
        << name << std::endl;

    std::cout << "Manager name through reference: "
        << managerNameReference_ << std::endl;
}

Manager Manager::CreateCopy() {
    return *this;
}
