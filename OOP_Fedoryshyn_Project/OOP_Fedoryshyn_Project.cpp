#include <iostream>
#include "Ticket.h"
#include "Visitor.h"
#include "TicketSale.h"
#include "ConcertManager.h"
#include "TicketUtils.h"
#include "Person.h"
#include "InheritanceDemo.h"
#include "PrivateManager.h"
#include "TicketPurchase.h"
#include "StandardTicket.h"
#include "VipTicket.h"
#include "StudentTicket.h"
#include "StaffMember.h"
#include "DestructorDemo.h"
#include <new>
#include <stdexcept>
#include <fstream>
#include "Service.h"
#include "TicketManager.h"
#include <iostream>
#include <limits>
#include "TemplateContainer.h"
#include "STLContainers.h"

// Пункт 5(3) Створення функції за межами класу
void CalculateTicketPrice(const Ticket& ticket) {   
    double priceWithTax = ticket.price * 1.05;

    std::cout << "Original ticket price: "
        << ticket.price << std::endl;

    std::cout << "Ticket price with 5% service fee: "
        << priceWithTax << std::endl;
}

// Пункт 6(3) - Перевантажена функція,яка отримує адресу об'єкта Ticket.
void CalculateTicketPrice(const Ticket* ticket) {
    if (ticket == nullptr) {
        std::cout << "Ticket pointer is null." << std::endl;
        return;
    }

    double priceWithTax = ticket->price * 1.1;

    std::cout << "Original ticket price: "
        << ticket->price << std::endl;

    std::cout << "Ticket price with 10% service fee: "
        << priceWithTax << std::endl;
}

// Пункт 7(4): демонстрація порядку виклику
// конструкторів і деструкторів.
void DemonstrateConstructorDestructorOrder()
{
    std::cout << "\n===== SIMPLE INHERITANCE =====" << std::endl;

    {
        std::cout << "\nCreating Visitor object:" << std::endl;

        Visitor visitor(
            80,
            "Test Visitor",
            "+380991234567");

        std::cout << "\nVisitor object is being used." << std::endl;
    }

    // Після виходу з блоку спочатку викликається деструктор
    // Visitor, а потім Person.


    std::cout << "\n===== PRIVATE INHERITANCE =====" << std::endl;

    {
        std::cout << "\nCreating PrivateManager object:" << std::endl;

        PrivateManager manager(
            81,
            "Test Manager",
            "+380671234567",
            "manager@example.com",
            30,
            "Khmelnytskyi",
            "Main Street 1",
            true);

        manager.ShowManagerInfo();
    }

    // Після виходу з блоку викликається деструктор
    // PrivateManager, а потім Person.


    std::cout << "\n===== MULTIPLE INHERITANCE =====" << std::endl;

    {
        std::cout << "\nCreating TicketPurchase object:" << std::endl;

        TicketPurchase purchase(
            101,
            1500.0,
            "Bank card",
            "visitor@example.com",
            "Ticket purchased successfully.",
            "Email",
            1,
            501,
            "Rock Concert");

        purchase.CompletePurchase();
    }

    // Після виходу з блоку викликається деструктор
    // TicketPurchase, а потім деструктори його базових класів.
}

// Пункт 5(5) - Функція для статичних об'єктів
void CreateStaticTickets()
{
    Ticket tickets[5] = {
        Ticket(1, 500, "Rock Concert", "2026-12-01", "18:00",
            "A", 1, 1, "Standard", false),

        Ticket(2, 700, "Rock Concert", "2026-12-01", "18:00",
            "A", 1, 2, "Standard", false),

        Ticket(3, 1000, "Rock Concert", "2026-12-01", "18:00",
            "B", 2, 1, "VIP", false),

        Ticket(4, 300, "Rock Concert", "2026-12-01", "18:00",
            "C", 3, 1, "Student", false),

        Ticket(5, 300, "Rock Concert", "2026-12-01", "18:00",
            "C", 3, 2, "Student", false)
    };

    std::cout << "\nStatic tickets:\n";

    for (int i = 0; i < 5; i++)
    {
        tickets[i].ShowInfo();
    }
}

// Пункт 5(5) - Функція для динамічних об'єктів
void CreateDynamicTickets()
{
    Ticket* tickets = nullptr;

    try
    {
        tickets = new Ticket[5]{
            Ticket(6, 500, "Rock Concert", "2026-12-01", "18:00",
                "A", 1, 3, "Standard", false),

            Ticket(7, 700, "Rock Concert", "2026-12-01", "18:00",
                "A", 1, 4, "Standard", false),

            Ticket(8, 1000, "Rock Concert", "2026-12-01", "18:00",
                "B", 2, 2, "VIP", false),

            Ticket(9, 300, "Rock Concert", "2026-12-01", "18:00",
                "C", 3, 3, "Student", false),

            Ticket(10, 300, "Rock Concert", "2026-12-01", "18:00",
                "C", 3, 4, "Student", false)
        };

        std::cout << "\nDynamic tickets:\n";

        for (int i = 0; i < 5; i++)
        {
            tickets[i].ShowInfo();
        }
    }
    catch (const std::bad_alloc& exception)
    {
        std::cerr << "Memory allocation error: "
            << exception.what() << std::endl;
    }

    delete[] tickets;
}

double ValidateTicketPrice(double price)
{
    if (price <= 0)
    {
        throw std::invalid_argument("Ticket price must be greater than zero.");
    }

    return price;
}

// Пункт 5(5) - Демонстрація try, catch і throw
void TestExceptions()
{
    try
    {
        double price = ValidateTicketPrice(0);
        std::cout << "Ticket price: " << price << std::endl;
    }
    catch (const std::invalid_argument& exception)
    {
        std::cerr << "Error: " << exception.what() << std::endl;
    }
}   

void ValidatePurchase(int ticketId, double balance, double ticketPrice)
{
    if (ticketId <= 0)
    {
        throw std::invalid_argument("Invalid ticket ID.");
    }

    if (balance < ticketPrice)
    {
        throw std::runtime_error("Not enough money to buy this ticket.");
    }

    std::cout << "Purchase validation successful.\n";
}

void TestPurchaseException()
{
    try
    {
        ValidatePurchase(1, 200, 500);
    }
    catch (const std::exception& exception)
    {
        std::cerr << "Purchase error: " << exception.what() << std::endl;
    }
}

void ValidateTicketFile(const std::string& fileName)
{
    std::ifstream file(fileName);

    if (!file.is_open())
    {
        throw std::runtime_error("Cannot open ticket data file.");
    }

    std::cout << "Ticket file opened successfully.\n";
}

void TestFileException()
{
    try
    {
        ValidateTicketFile("missing_tickets.txt");
    }
    catch (const std::exception& exception)
    {
        std::cerr << "File error: " << exception.what() << std::endl;
    }
}

// Пункт 6(5) Метод для перевірки статичних об'єктів
void TestStaticService()
{
    Ticket tickets[5] = {
        Ticket(1, 300, "Rock Concert", "2026-12-01", "18:00",
            "A", 1, 1, "Standard", false),

        Ticket(2, 500, "Rock Concert", "2026-12-01", "18:00",
            "A", 1, 2, "Standard", false),

        Ticket(3, 1000, "Rock Concert", "2026-12-01", "18:00",
            "B", 2, 1, "VIP", false),

        Ticket(4, 250, "Rock Concert", "2026-12-01", "18:00",
            "C", 3, 1, "Student", false),

        Ticket(5, 700, "Rock Concert", "2026-12-01", "18:00",
            "A", 2, 2, "Standard", false)
    };

    int count = 5;

    Service_Static(tickets, count, 500);

    std::cout << "\nRemaining static tickets:\n";

    for (int i = 0; i < count; i++)
    {
        tickets[i].ShowInfo();
    }
}

// Пункт 6(5) Метод для перевірки динамічних об'єктів
void TestDynamicService()
{
    int count = 5;

    Ticket* tickets = nullptr;

    try
    {
        tickets = new Ticket[5]{
            Ticket(6, 300, "Rock Concert", "2026-12-01", "18:00",
                "A", 1, 3, "Standard", false),

            Ticket(7, 500, "Rock Concert", "2026-12-01", "18:00",
                "A", 1, 4, "Standard", false),

            Ticket(8, 1000, "Rock Concert", "2026-12-01", "18:00",
                "B", 2, 2, "VIP", false),

            Ticket(9, 250, "Rock Concert", "2026-12-01", "18:00",
                "C", 3, 3, "Student", false),

            Ticket(10, 700, "Rock Concert", "2026-12-01", "18:00",
                "A", 2, 3, "Standard", false)
        };

        Service_Dinamic(tickets, count, 500);

        std::cout << "\nRemaining dynamic tickets:\n";

        for (int i = 0; i < count; i++)
        {
            tickets[i].ShowInfo();
        }
    }
    catch (const std::bad_alloc& exception)
    {
        std::cerr << "Error: " << exception.what() << '\n';
    }

    delete[] tickets;
}

// Пункт 7(5) - Функція для перевірки роботи Service
void TestFileService(const std::string& fileName)
{
    try
    {
        Ticket ticket(
            100,
            1500,
            "Rock Concert",
            "2026-12-01",
            "18:00",
            "VIP",
            1,
            10,
            "VIP",
            false
        );

        // Записуємо об'єкт у файл.
        Service(ticket, fileName, true);

        std::cout << "Ticket successfully saved.\n";

        // Створюємо інший об'єкт для читання.
        Ticket loadedTicket;

        Service(loadedTicket, fileName, false);

        std::cout << "\nLoaded ticket:\n";
        loadedTicket.ShowInfo();
    }
    catch (const std::exception& exception)
    {
        std::cerr << "File service error: "
            << exception.what() << '\n';
    }
}


// Пункт 8(5) - Функція для запуску меню
void RunTicketMenu()
{
    TicketManager manager;
    int choice = 0;

    do
    {
        std::cout << "\n========== TICKET SYSTEM ==========\n";
        std::cout << "1. Create ticket\n";
        std::cout << "2. Show all tickets\n";
        std::cout << "3. Remove ticket\n";
        std::cout << "4. Destroy all tickets\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose an option: ";

        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Invalid input.\n";
            continue;
        }

        try
        {
            switch (choice)
            {
            case 1:
            {
                int id;
                double price;
                std::string concertName;

                std::cout << "Ticket ID: ";
                std::cin >> id;

                std::cout << "Ticket price: ";
                std::cin >> price;

                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Concert name: ";
                std::getline(std::cin, concertName);

                Ticket ticket(
                    id, price, concertName,
                    "2026-12-01", "18:00",
                    "A", 1, id, "Standard", false
                );

                manager.AddTicket(ticket);

                std::cout << "Ticket created successfully.\n";
                break;
            }

            case 2:
                manager.ShowTickets();
                break;

            case 3:
            {
                int id;

                std::cout << "Enter ticket ID: ";
                std::cin >> id;

                manager.RemoveTicket(id);

                std::cout << "Ticket removed successfully.\n";
                break;
            }

            case 4:
                manager.ClearTickets();

                std::cout << "All tickets destroyed.\n";
                break;

            case 0:
                std::cout << "Exiting ticket system.\n";
                break;

            default:
                std::cout << "Unknown menu option.\n";
                break;
            }
        }
        catch (const std::exception& exception)
        {
            std::cerr << "Error: " << exception.what() << '\n';
        }

    } while (choice != 0);
}

// Пункт 9(5) - Поліморфний виклик методу через вказівник базового класу
void TestPolymorphismByPointer()
{
    std::cout << "\n=== Polymorphism using pointers ===\n";

    Person* person = new Visitor();
    Person* manager = new Manager();

    std::cout << person->GetRoleDescription() << '\n';
    std::cout << manager->GetRoleDescription() << '\n';

    delete person;
    delete manager;
}

// Пункт 9(5) - Поліморфний виклик методу через посилання базового класу
void PrintPersonRole(const Person& person)
{
    std::cout << person.GetRoleDescription() << '\n';
}

void TestPolymorphismByReference()
{
    std::cout << "\n=== Polymorphism using references ===\n";

    Visitor visitor;
    Manager manager;

    PrintPersonRole(visitor);
    PrintPersonRole(manager);
}

// Пункт 9(5) - Поліморфний виклик методу через масив вказівників
void TestPolymorphismByArray()
{
    std::cout << "\n=== Polymorphism using array ===\n";

    Person* people[3];

    people[0] = new Person();
    people[1] = new Visitor();
    people[2] = new Manager();

    for (int i = 0; i < 3; i++)
    {
        std::cout << people[i]->GetRoleDescription() << '\n';
    }

    for (int i = 0; i < 3; i++)
    {
        delete people[i];
    }
}

// Пункт 9(5) - Поліморфізм для типів квитків
void TestTicketTypePolymorphism()
{
    std::cout << "\n=== Ticket type polymorphism ===\n";

    TicketType* tickets[3];

    tickets[0] = new StandardTicket(1, "Rock Concert", 1000);
    tickets[1] = new VipTicket(2, "Rock Concert", 1000, 500);
    tickets[2] = new StudentTicket(3, "Rock Concert", 1000, 20);

    for (int i = 0; i < 3; i++)
    {
        tickets[i]->ShowDetails();

        std::cout << "Final price: "
            << tickets[i]->CalculatePrice()
            << " UAH\n\n";
    }

    for (int i = 0; i < 3; i++)
    {
        delete tickets[i];
    }
}

// Пункт 10(5) Перевірка виклику методів
void TestBinding()
{
    std::cout << "\n=== Static and Dynamic Binding ===\n";

    Visitor visitor;

    Person* personPointer = &visitor;

    // Early binding: викликається метод за типом вказівника.
    personPointer->ShowBindingType();

    // Late binding: викликається метод фактичного типу об'єкта.
    personPointer->GetRoleDescription();

    std::cout << personPointer->GetRoleDescription() << '\n';

    // Виклик через об'єкт похідного класу.
    visitor.ShowBindingType();
}

// Пункт 11(5) Функція обходу віртуальних функцій
void TestVirtualFunctionBypass()
{
    std::cout << "\n=== Virtual Function Bypass ===\n";

    Visitor visitor;

    // Звичайний поліморфний виклик.
    Person* person = &visitor;

    std::cout << "Normal virtual call: "
        << person->GetRoleDescription() << '\n';

    // Примусовий виклик реалізації базового класу.
    std::cout << "Base class call: "
        << visitor.Person::GetRoleDescription() << '\n';

    // Прямий виклик реалізації похідного класу.
    std::cout << "Derived class call: "
        << visitor.Visitor::GetRoleDescription() << '\n';
}

int main(int argc, char* argv[])
{
    // Пункт 5: створення Visitor через параметризований конструктор.
    Visitor visitor(
        20,
        "Andrii",
        "+380501234567",
        "andrii@example.com",
        20,
        "Khmelnytskyi",
        "Centralna Street 10",
        true,
        2500.0,
        0,
        false);

    visitor.ShowInfo();

    // Пункт 6(2). Створення 5 об'єктів у статичній пам'яті.
    // Пункт 7(2) - визначено перший з двох масивів об'єктів
    static Ticket tickets[5] = {
        Ticket(1, 1200, "Concert 2026", "20.10.2026", "19:00",
            "VIP", 3, 15, "Electronic", false),

        Ticket(2, 900, "Concert 2026", "20.10.2026", "19:00",
            "Standard", 5, 20, "Paper", false),

        Ticket(3, 600, "Concert 2026", "20.10.2026", "19:00",
            "Economy", 8, 10, "Electronic", false),

        Ticket(4, 900, "Concert 2026", "20.10.2026", "19:00",
            "Standard", 6, 25, "Paper", false), 

        Ticket(5, 600, "Concert 2026", "20.10.2026", "19:00",
            "Economy", 10, 5, "Electronic", false)
    };

    // Пункт 6(2). Створення 5 об'єктів у динамічній пам'яті.
    // Пункт 7(2) - визначено другий з двох масивів об'єктів
    Visitor* visitors = new Visitor[5]{
        Visitor(1, "Ivan Petrenko", "+380991234567"),
        Visitor(2, "Olena Kovalenko", "+380672345678"),
        Visitor(3, "Andrii Melnyk", "+380931112233"),
        Visitor(4, "Maria Shevchenko", "+380501234567"),
        Visitor(5, "Dmytro Bondarenko", "+380971234567")
    };

    Manager manager(
        1,
        "Oleksandr Manager",
        "Concert 2026",
        "20.10.2026",
        "19:00",
        "Palace of Sports",
        "Singer",
        50
    );

    // Пункт 3(3) - Демонстрація роботи деструктора.

    std::cout << std::endl;
    std::cout << "=== DESTRUCTOR ===" << std::endl;

    {
        Manager testManager(
            10,
            "Test Manager",
            "Test Concert",
            "01.01.2027",
            "18:00",
            "Test Hall",
            "Test Singer",
            50
        );

        std::cout << "Object exists inside the block." << std::endl;
    }

    std::cout << "Block ended. Destructor was called." << std::endl;

    // Пункт 8(2). Демонстрація роботи з об'єктами в масивах.

    std::cout << std::endl;
    std::cout << "=== ALL TICKETS ===" << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << std::endl;
        std::cout << "Ticket #" << i + 1 << std::endl;
        tickets[i].ShowInfo();
    }

    std::cout << std::endl;
    std::cout << "=== ALL VISITORS ===" << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << std::endl;
        std::cout << "Visitor #" << i + 1 << std::endl;
        visitors[i].ShowInfo();
    }

    //visitors[0].AddBalance(1500);

    //std::cout << std::endl;
    //std::cout << "=== BUYING TICKET ===" << std::endl;

    //if (visitors[0].BuyTicket(tickets[0])) {
    //    std::cout << "Ticket purchased successfully!" << std::endl;
    //}
    //else {
    //    std::cout << "Ticket purchase failed!" << std::endl;
    //}

    //std::cout << "=== TICKET ===" << std::endl;
    //tickets[0].ShowInfo();

    //std::cout << std::endl;

    //std::cout << "=== VISITOR ===" << std::endl;
    //visitors[0].ShowInfo();

    // Пункт 9(2). Демонстрація всіх методів класу Ticket.

    std::cout << std::endl;
    std::cout << "=== TICKET METHODS ===" << std::endl;

    tickets[0].ShowInfo();

    tickets[1].ChangePrice(1000);
    std::cout << std::endl << "After changing price:" << std::endl;
    tickets[1].ShowInfo();

    tickets[2].ChangePrice(800, true);
    std::cout << std::endl << "After changing price with discount:" << std::endl;
    tickets[2].ShowInfo();

    if (tickets[3].Sell()) {
        std::cout << std::endl << "Ticket 4 was sold." << std::endl;
    }

    if (tickets[1].CompareTicket(tickets[4])) {
        std::cout << "Tickets 2 and 5 are equal." << std::endl;
    }
    else {
        std::cout << "Tickets 2 and 5 are different." << std::endl;
    }

    Ticket ticket_copy = tickets[0].CreateCopy();
    std::cout << std::endl << "Copy of ticket:" << std::endl;
    ticket_copy.ShowInfo();

    tickets[0].SaveToFile("ticket.txt");

    Ticket loaded_ticket;
    loaded_ticket.LoadFromFile("ticket.txt");

    std::cout << std::endl << "Loaded ticket from file:" << std::endl;
    loaded_ticket.ShowInfo();

    // Пункт 9(2). Демонстрація всіх методів класу Visitor.

    std::cout << std::endl;
    std::cout << "=== VISITOR METHODS ===" << std::endl;

    visitors[0].ShowInfo();

    visitors[0].AddBalance(500);

    visitors[1].AddBalance(1000, true);

    // Пункт 10(2) - демонстрація сценарію взаємодії двох об'єктів: Відвідувач купляє квиток
    visitors[2].AddBalance(1000);

    if (visitors[2].BuyTicket(tickets[4])) {
        std::cout << std::endl << "Visitor 3 bought ticket 5." << std::endl;
    }
    else {
        std::cout << std::endl << "Visitor 3 could not buy ticket 5." << std::endl;
    }

    if (visitors[0].CompareVisitor(visitors[1])) {
        std::cout << "Visitors 1 and 2 are equal." << std::endl;
    }
    else {
        std::cout << "Visitors 1 and 2 are different." << std::endl;
    }

    visitors[1].AddBalance(1000);

    if (visitors[1].BuyTicketOnline(tickets[1])) {
        std::cout << std::endl << "Visitor 2 bought ticket 2 online." << std::endl;
    }
    else {
        std::cout << std::endl << "Visitor 2 could not buy ticket 2 online." << std::endl;
    }

    Visitor visitor_copy = visitors[0].CreateCopy();
    std::cout << std::endl << "Copy of visitor:" << std::endl;
    visitor_copy.ShowInfo();

    visitors[0].SaveToFile("visitor.txt");

    Visitor loaded_visitor;
    loaded_visitor.LoadFromFile("visitor.txt");

    std::cout << std::endl << "Loaded visitor from file:" << std::endl;
    loaded_visitor.ShowInfo();

    // Пункт 11(2). Вказівник на екземпляр класу.

    Ticket* ticket_pointer = &tickets[0];

    std::cout << std::endl;
    std::cout << "=== POINTER TO TICKET ===" << std::endl;

    ticket_pointer->ShowInfo();

    ticket_pointer->ChangePrice(1300);

    std::cout << std::endl << "Ticket after changing price through pointer:" << std::endl;
    ticket_pointer->ShowInfo();

    // Пункт 12(2). Робота з динамічною пам'яттю та сортуванням.

    std::cout << std::endl;
    std::cout << "=== DYNAMIC MEMORY AND SORTING ===" << std::endl;

    tickets[0].GenerateAndSortPrices();

    if (visitors[1].CancelTicket(tickets[1], manager)) {
        std::cout << std::endl << "Visitor 2 cancelled the ticket." << std::endl;
        std::cout << "Refund: " << tickets[1].price *
            manager.GetRefundPercent() / 100.0 << std::endl;
    }
    else {
        std::cout << std::endl << "Ticket cancellation failed." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=== MANAGER METHODS ===" << std::endl;

    manager.SetConcertTime("19:00");

    manager.SetConcertPlace("Palace of Sports");

    manager.SetRefundPercent(50);

    manager.ShowInfo();

    manager.InformSinger();

    std::cout << "Current refund percentage: "
        << manager.GetRefundPercent() << "%" << std::endl;

    Manager manager_copy = manager.CreateCopy();

    std::cout << std::endl;
    std::cout << "=== MANAGER COPY ===" << std::endl;
    manager_copy.ShowInfo();

    // Пункт 2(2). Демонстрація задання полів даних як початкових значень констант і посилань
    manager.ShowConstAndReference();

    manager.name = "Petro";

    manager.ShowConstAndReference();

    // Пункт 4(2). Демонстрація статичного поля та статичного методу.

    std::cout << "=== STATIC TICKET MEMBER ===" << std::endl;

    std::cout << "Number of Ticket objects: "
        << Ticket::ticketCount << std::endl;

    Ticket::ShowTicketCount();

    std::cout << std::endl;
    std::cout << "=== Third Lab ===" << std::endl;
    std::cout << std::endl;

    // Пункт 5(3) - Виклик методу в main()
    CalculateTicketPrice(tickets[0]);

    // Пункт 6(3) - Виклик перевантаженого методу в main()
    CalculateTicketPrice(&tickets[0]);

    // Пункт 7(3) - Функція типу Ticket, яка повертає об'єкт класу та використовує його методи.
    Ticket copyTicket = tickets[0].CreateCopy();

    std::cout << "Copied ticket:" << std::endl;
    copyTicket.ShowInfo();

    // Пункт 8(3) - Три способи створення об'єктів.

    std::cout << std::endl;
    std::cout << "=== THREE CONSTRUCTION METHODS ===" << std::endl;

    // Простий спосіб.
    Ticket simpleTicket(
        10,
        800,
        "Concert A",
        "01.12.2026",
        "18:00",
        "A",
        5,
        10,
        "Paper",
        false
    );

    // Явний спосіб.
    Ticket explicitTicket = Ticket(
        11,
        900,
        "Concert B",
        "02.12.2026",
        "19:00",
        "B",
        6,
        11,
        "Electronic",
        false
    );

    // Скорочений спосіб.
    Ticket shortTicket = {
        12,
        1000,
        "Concert C",
        "03.12.2026",
        "20:00",
        "C",
        7,
        12,
        "Electronic",
        false
    };

    simpleTicket.ShowInfo();
    explicitTicket.ShowInfo();
    shortTicket.ShowInfo();

    // Пункт 9(3) - Покажчик на екземпляр класу, статичне та динамічне розміщення об'єктів, а також масиви об'єктів.

    std::cout << std::endl;
    std::cout << "=== POINTERS, STATIC AND DYNAMIC OBJECTS ==="
        << std::endl;

    // Об'єкт у статичній пам'яті.
    Ticket staticTicket(
        20,
        700,
        "Static Concert",
        "10.12.2026",
        "18:00",
        "A",
        1,
        1,
        "Paper",
        false
    );

    // Покажчик на екземпляр класу.
    Ticket* ticketPointer = &staticTicket;

    std::cout << "Object through pointer:" << std::endl;
    ticketPointer->ShowInfo();

    // Об'єкт у динамічній пам'яті.
    Ticket* dynamicTicket = new Ticket(
        21,
        900,
        "Dynamic Concert",
        "11.12.2026",
        "19:00",
        "B",
        2,
        2,
        "Electronic",
        false
    );

    std::cout << "Dynamic object:" << std::endl;
    dynamicTicket->ShowInfo();

    delete dynamicTicket;

    // Статичний масив об'єктів.
    Ticket staticTickets[2] = {
        Ticket(
            22,
            800,
            "Concert C",
            "12.12.2026",
            "18:00",
            "A",
            3,
            3,
            "Paper",
            false
        ),
        Ticket(
            23,
            1000,
            "Concert D",
            "13.12.2026",
            "20:00",
            "B",
            4,
            4,
            "Electronic",
            false
        )
    };

    std::cout << "Static array of Ticket objects:" << std::endl;

    for (int i = 0; i < 2; i++) {
        staticTickets[i].ShowInfo();
    }

    // Динамічний масив об'єктів.
    Ticket* dynamicTickets = new Ticket[2]{
        Ticket(
            24,
            750,
            "Concert E",
            "14.12.2026",
            "18:00",
            "A",
            5,
            5,
            "Paper",
            false
        ),
        Ticket(
            25,
            950,
            "Concert F",
            "15.12.2026",
            "19:00",
            "C",
            6,
            6,
            "Electronic",
            false
        )
    };

    std::cout << "Dynamic array of Ticket objects:" << std::endl;

    for (int i = 0; i < 2; i++) {
        dynamicTickets[i].ShowInfo();
    }

    delete[] dynamicTickets;

    // Пункт 10(3) - Демонстрація роботи всіх конструкторів.

    std::cout << std::endl;
    std::cout << "=== ALL CONSTRUCTORS ===" << std::endl;

    // ===== Ticket =====

    // Конструктор за замовчуванням.
    Ticket defaultTicket;

    // Параметризований конструктор.
    Ticket parameterizedTicket(
        30,
        1200,
        "Constructor Concert",
        "20.12.2026",
        "19:00",
        "A",
        10,
        15,
        "Electronic",
        false
    );

    // Конструктор копіювання.
    Ticket copiedTicket(parameterizedTicket);

    defaultTicket.ShowInfo();
    parameterizedTicket.ShowInfo();
    copiedTicket.ShowInfo();


    // ===== Visitor =====

    // Конструктор за замовчуванням.
    Visitor defaultVisitor;

    // Параметризований конструктор.
    Visitor parameterizedVisitor(
        30,
        "Test Visitor",
        "+380991234567"
    );

    // Конструктор копіювання.
    Visitor copiedVisitor(parameterizedVisitor);

    defaultVisitor.ShowInfo();
    parameterizedVisitor.ShowInfo();
    copiedVisitor.ShowInfo();


    // ===== Manager =====

    // Конструктор за замовчуванням.
    Manager defaultManager;

    // Параметризований конструктор.
    Manager parameterizedManager(
        30,
        "Test Manager",
        "Test Concert",
        "20.12.2026",
        "19:00",
        "Test Hall",
        "Test Singer",
        50
    );

    // Конструктор копіювання.
    Manager copiedManager(parameterizedManager);

    defaultManager.ShowInfo();
    parameterizedManager.ShowInfo();
    copiedManager.ShowInfo();

    // Пункт 11(3) Взаємодія трьох об'єктів за допомогою класу асоціації.

    std::cout << std::endl;
    std::cout << "=== ASSOCIATION CLASS ===" << std::endl;

    Visitor saleVisitor(
        40,
        "Association Visitor",
        "+380991111111"
    );

    Ticket saleTicket(
        40,
        1000,
        "Association Concert",
        "25.12.2026",
        "19:00",
        "A",
        10,
        20,
        "Electronic",
        false
    );

    Manager saleManager(
        40,
        "Association Manager",
        "Association Concert",
        "25.12.2026",
        "19:00",
        "Concert Hall",
        "Test Singer",
        50
    );

    saleVisitor.AddBalance(1000);

    TicketSale ticketSale(
        saleVisitor,
        saleTicket,
        saleManager
    );

    ticketSale.ProcessSale();

    // Пункт 12(3) - Взаємодія двох об'єктів за агрегації.

    std::cout << std::endl;
    std::cout << "=== AGGREGATION ===" << std::endl;

    Manager aggregationManager(
        50,
        "Aggregation Manager",
        "Aggregation Concert",
        "30.12.2026",
        "19:00",
        "Main Hall",
        "Test Singer",
        50
    );

    Ticket aggregationTicket(
        50,
        1100,
        "Aggregation Concert",
        "30.12.2026",
        "19:00",
        "A",
        5,
        10,
        "Electronic",
        false
    );

    ConcertManager concertManager(aggregationManager);

    concertManager.AddTicket(aggregationTicket);
    concertManager.ShowTicket();

    // Пункт 13(3) - Взаємодія двох об'єктів за композиції.

    std::cout << std::endl;
    std::cout << "=== COMPOSITION ===" << std::endl;

    Visitor compositionVisitor(
        60,
        "Composition Visitor",
        "+380992222222"
    );

    compositionVisitor.SetTicket(
        60,
        1200,
        "Composition Concert",
        "31.12.2026",
        "21:00",
        "A",
        8,
        15,
        "Electronic",
        false
    );

    compositionVisitor.ShowInfo();

    // (4) Практичне завдання

    std::cout << "=== TICKET UTILS ===" << std::endl;

    double price = 1000.0;
    double discount = 15.0;

    if (TicketUtils::IsValidPrice(price))
    {
        TicketUtils::ShowPriceWithDiscount(price, discount);
    }

    std::cout << "Calculated price: "
        << TicketUtils::CalculateDiscount(price, discount)
        << std::endl;

    // Четверта лабораторна

    // Пункт 2(4) Демонстрація керування доступу до членів базового класу

    std::cout << "\n=== Forth lab ===\n" << std::endl;

    PublicInheritanceDemo publicObject(
        1, "Ivan", "+380111111111", "ivan@example.com",
        20, "Lviv", "Main Street 1", true);

    ProtectedInheritanceDemo protectedObject(
        2, "Petro", "+380222222222", "petro@example.com",
        25, "Kyiv", "Central Street 2", true);

    PrivateInheritanceDemo privateObject(
        3, "Olena", "+380333333333", "olena@example.com",
        22, "Odesa", "Sea Street 3", true);

    publicObject.ShowAccess();
    protectedObject.ShowAccess();
    privateObject.ShowAccess();

    // Пункт 3(4): створення об'єкта через конструктор.
    PrivateManager privateManager(
        10,
        "Andrii",
        "+380501234567",
        "andrii@example.com",
        30,
        "Khmelnytskyi",
        "Centralna Street 10",
        true);

    // Використання методів похідного класу.
    privateManager.ShowManagerInfo();
    privateManager.ChangeManagerName("Andrii Kovalenko");
    privateManager.ShowManagerInfo();

    // Пункт 4(4): створення об'єкта класу з множинним наслідуванням.
    TicketPurchase purchase(
        101,
        1500.0,
        "Bank card",
        "visitor@example.com",
        "Your concert ticket has been purchased.",
        "Email",
        1,
        501,
        "Rock Concert");

    // Використання методів усіх трьох класів.
    purchase.CompletePurchase();

    // Пункт 5(4): створення Visitor через параметризований конструктор.
    Visitor fullVisitor(
        20,
        "Andrii",
        "+380501234567",
        "andrii@example.com",
        20,
        "Khmelnytskyi",
        "Centralna Street 10",
        true,
        2500.0,
        0,
        false);

    fullVisitor.ShowInfo();

    // Пункт 6(4) Демонстрація
    Visitor accessVisitor(
        70,
        "Access Test",
        "+380991234567"
    );

    accessVisitor.ShowBaseClassAccess();

    // Пункт 7(4) Демонстрація конструкторів і деструкторів
    DemonstrateConstructorDestructorOrder();

    // Пункт 8(4) Демонстрація деструкторів

    std::cout << "\n===== Demonstration of destructors =====" << std::endl;

    {
        std::cout << "\nEntering first block" << std::endl;

        Visitor visitor(80, "Test Visitor", "+380991234567");

        std::cout << "Visitor object created inside the block" << std::endl;
    }

    std::cout << "Exited first block" << std::endl;

    {
        std::cout << "\nEntering second block" << std::endl;

        TicketPurchase purchase(
            1,
            500.0,
            "Card",
            "test@example.com",
            "Your ticket has been purchased.",
            "Email",
            100,
            200,
            "Concert 2026"
        );

        std::cout << "TicketPurchase object created inside the block" << std::endl;
    }

    std::cout << "Exited second block" << std::endl;

    // Пункт 9(4): повний сценарій функціонування системи продажу квитків.

    std::cout << "\n========== CONCERT TICKET SYSTEM ==========" << std::endl;

    // 1. Інформація про концерт і менеджера.
    std::cout << "\n--- Concert manager ---" << std::endl;
    manager.ShowInfo();

    // 2. Менеджер концертів керує квитком.
    ConcertManager systemConcertManager(manager);

    systemConcertManager.AddTicket(tickets[0]);

    std::cout << "\n--- Available concert ticket ---" << std::endl;
    systemConcertManager.ShowTicket();

    // 3. Відвідувач переглядає інформацію.
    std::cout << "\n--- Visitor ---" << std::endl;
    visitors[0].ShowInfo();

    // 4. Відвідувач поповнює баланс.
    std::cout << "\n--- Adding balance ---" << std::endl;
    visitors[0].AddBalance(1500.0);

    // 5. Відвідувач купує квиток.
    std::cout << "\n--- Buying ticket ---" << std::endl;

    if (visitors[0].BuyTicket(tickets[0])) {
        std::cout << "Ticket purchased successfully." << std::endl;

        // 6. Створюється платіж і надсилається повідомлення.
        std::cout << "\n--- Payment and notification ---" << std::endl;

        TicketPurchase systemPurchase(
            201,
            tickets[0].price,
            "Bank card",
            "visitor@example.com",
            "Your concert ticket has been purchased successfully.",
            "Email",
            1001,
            tickets[0].id,
            tickets[0].concertName
        );

        systemPurchase.CompletePurchase();
    }
    else {
        std::cout << "Ticket purchase failed." << std::endl;
    }

    // 7. Перевірка стану відвідувача та квитка.
    std::cout << "\n--- Final visitor information ---" << std::endl;
    visitors[0].ShowInfo();

    std::cout << "\n--- Final ticket information ---" << std::endl;
    tickets[0].ShowInfo();

    std::cout << "\n========== SYSTEM DEMONSTRATION COMPLETED =========="
        << std::endl;

    // П'ята лабораторна

    std::cout << "\n=== Fifth lab ===\n" << std::endl;

    // Пункт 1(5) - Створення об'єктів похідних класів
    StandardTicket standardTicket(1, "Rock Concert", 1000);
    VipTicket vipTicket(2, "Rock Concert", 1000, 800);
    StudentTicket studentTicket(3, "Rock Concert", 1000, 20);

    TicketType* ticketTypes[3] =
    {
        &standardTicket,
        &vipTicket,
        &studentTicket
    };

    for (int i = 0; i < 3; i++)
    {
        ticketTypes[i]->ShowDetails();
    }

    // Пункт 2(5) - Демонстрація віртуального наслідування
    StaffMember staff(
        10,
        "Ivan Petrenko",
        "+380991112233",
        "ivan@gmail.com",
        25,
        "Khmelnytskyi",
        "Main Street",
        "Rock Concert",
        "20.12.2026",
        "19:00",
        "Concert Hall",
        "Rock Band"
    );

    staff.ShowStaffInfo();
    staff.Visitor::ShowInfo();
    staff.Manager::ShowInfo();

    // Пункт 3(5) - Порівняння віртуального та невіртуального деструкторів

    std::cout << "\n--- Non-virtual destructor ---" << std::endl;

    NonVirtualBase* nonVirtual = new NonVirtualDerived();
    delete nonVirtual;

    std::cout << "\n--- Virtual destructor ---" << std::endl;

    VirtualBase* virtualObject = new VirtualDerived();
    delete virtualObject;

    // Пункт 4(5) - Віртуальні функції в класах відкритої ієрархії наслідування

    Person* people[4];

    people[0] = new Person();
    people[1] = new Visitor();
    people[2] = new Manager();
    people[3] = new StaffMember(
        4,
        "Test Staff",
        "0987654321",
        "staff@example.com",
        25,
        "Khmelnytskyi",
        "Test address",
        "Rock Concert",
        "2026-12-01",
        "18:00",
        "Concert Hall",
        "Test Singer"
    );

    for (int i = 0; i < 4; i++)
    {
        std::cout << people[i]->GetRoleDescription() << std::endl;
    }

    for (int i = 0; i < 4; i++)
    {
        delete people[i];
    }

    // Пункт 5(5) - Створення 5 об'єктів в динамічній та статичній пам'яті
    CreateStaticTickets();
    CreateDynamicTickets();

    TestExceptions();
    TestPurchaseException();
    TestFileException();

    // Пункт 6(5) - Видалення об'єктів з масивів
    TestStaticService();
    TestDynamicService();

    // Пункт 7(5) - Перевірка роботи Service
    if (argc < 2)
    {
        std::cerr << "Usage: program.exe <file_name>\n";
        return 1;
    }

    TestFileService(argv[1]);

    // Пункт 9(5) - Демонстрація поліморфних викликів трьома способами
    TestPolymorphismByPointer();
    TestPolymorphismByReference();
    TestPolymorphismByArray();
    TestTicketTypePolymorphism();

    // Пункт 10(5) - Поліморфний виклик методів за допомогою зв'язувань
    TestBinding();

    // Пункт 11(5) - Демонстрація обходу віртуальних функцій
    TestVirtualFunctionBypass();


    // Пункт 8(5) - Запуск меню
    RunTicketMenu();


    // Шоста лабораторна

    std::cout << "\n=== Sixht lab ===\n" << std::endl;

    // ЛР №6, пункт 1 — демонстрація унарних операторів

    std::cout << "\n=== Unary operators ===" << std::endl;

    Ticket operatorTicket(
        100,
        1000,
        "Rock Concert",
        "20.12.2026",
        "19:00",
        "VIP",
        1,
        10,
        "VIP",
        false
    );

    std::cout << "Initial price: " << operatorTicket.price << std::endl;

    ++operatorTicket;
    std::cout << "After prefix ++: " << operatorTicket.price << std::endl;

    operatorTicket++;
    std::cout << "After postfix ++: " << operatorTicket.price << std::endl;

    --operatorTicket;
    std::cout << "After prefix --: " << operatorTicket.price << std::endl;

    operatorTicket--;
    std::cout << "After postfix --: " << operatorTicket.price << std::endl;

    // Пункт 2(6) — демонстрація бінарних операторів

    std::cout << "\n=== Binary operators ===" << std::endl;

    Ticket firstTicket(
        101, 1500, "Rock Concert",
        "20.12.2026", "19:00", "VIP",
        1, 10, "VIP", false
    );

    Ticket secondTicket(
        102, 500, "Rock Concert",
        "20.12.2026", "19:00", "Standard",
        2, 15, "Standard", false
    );

    Ticket sumTicket = firstTicket + secondTicket;
    Ticket differenceTicket = firstTicket - secondTicket;

    std::cout << "First ticket price: "
        << firstTicket.price << std::endl;

    std::cout << "Second ticket price: "
        << secondTicket.price << std::endl;

    std::cout << "Price after addition: "
        << sumTicket.price << std::endl;

    std::cout << "Price after subtraction: "
        << differenceTicket.price << std::endl;

    // Пункт 3(6) — демонстрація операторів *, =, +=, -=, *=, []

    std::cout << "\n=== Other overloaded operators ===" << std::endl;

    Ticket thirdTicket(
        103, 1000, "Rock Concert",
        "20.12.2026", "19:00", "VIP",
        1, 10, "VIP", false
    );

    Ticket fourthTicket(
        104, 500, "Rock Concert",
        "20.12.2026", "19:00", "Standard",
        2, 15, "Standard", false
    );

    // Оператор *
    Ticket multipliedTicket = thirdTicket * 2;
    std::cout << "After * 2: "
        << multipliedTicket.price << std::endl;

    // Оператор =
    thirdTicket = fourthTicket;
    std::cout << "After assignment: "
        << thirdTicket.price << std::endl;

    // Оператор +=
    thirdTicket += fourthTicket;
    std::cout << "After +=: "
        << thirdTicket.price << std::endl;

    // Оператор -=
    thirdTicket -= fourthTicket;
    std::cout << "After -=: "
        << thirdTicket.price << std::endl;

    // Оператор *=
    thirdTicket *= 3;
    std::cout << "After *= 3: "
        << thirdTicket.price << std::endl;

    // Оператор []
    std::cout << "First character: "
        << thirdTicket[0] << std::endl;

    thirdTicket[0] = 'M';

    std::cout << "Concert name after changing first character: "
        << thirdTicket.concertName << std::endl;

    // Пункт 4(6) — демонстрація шаблонної функції

    std::cout << "\n=== Template function ===" << std::endl;

    Ticket templateTicket(
        105, 1000, "Rock Concert",
        "20.12.2026", "19:00", "VIP",
        1, 10, "VIP", false
    );

    std::cout << "Initial price: "
        << templateTicket.price << std::endl;

    templateTicket.ApplyPriceMultiplier(2);

    std::cout << "After integer multiplier: "
        << templateTicket.price << std::endl;

    templateTicket.ApplyPriceMultiplier(1.5);

    std::cout << "After double multiplier: "
        << templateTicket.price << std::endl;

    // Пункт 5(6) — демонстрація шаблону класу

    std::cout << "\n=== Template class ===" << std::endl;

    TemplateContainer<int, std::string, double, int, std::string>
        ticketContainer(
            1,
            "Rock Concert",
            1500.0,
            2,
            "VIP tickets"
        );

    ticketContainer.ShowInfo();

    ticketContainer.SetPrice(2000.0);
    ticketContainer.SetQuantity(3);

    std::cout << "\nAfter changing data:" << std::endl;

    ticketContainer.ShowInfo();

    // Пункт 6(6) — використання користувацького класу як параметра шаблону

    std::cout << "\n=== Template with user-defined class ===" << std::endl;

    Ticket customTicket(
        201,
        1200.0,
        "Rock Concert",
        "20.12.2026",
        "19:00",
        "VIP",
        1,
        15,
        "VIP",
        false
    );

    TemplateContainer<int, std::string, double, int, Ticket>
        customContainer(
            1,
            "Ticket collection",
            1200.0,
            1,
            customTicket
        );

    std::cout << "Container information:" << std::endl;

    std::cout << "ID: " << customContainer.GetId() << std::endl;
    std::cout << "Name: " << customContainer.GetName() << std::endl;
    std::cout << "Price: " << customContainer.GetPrice() << std::endl;
    std::cout << "Quantity: " << customContainer.GetQuantity() << std::endl;

    std::cout << "\nStored Ticket:" << std::endl;

    customContainer.GetAdditional().ShowInfo();

    // Сьома лабораторна

    std::cout << "\n=== Seventh lab ===\n" << std::endl;

    // Пункт 1(7) — демонстрація контейнерів STL
    RunSTLContainersDemo();

    // Пункт 2(7) — демонстрація ітераторів STL
    RunSTLIteratorsDemo();

    // Пункт 3(7) — демонстрація алгоритмів STL
    RunSTLAlgorithmsDemo();

    // Пункт 4(7) — демонстрація функціональних об'єктів STL
    RunSTLFunctorsDemo();

    delete[] visitors;

    return 0;
}