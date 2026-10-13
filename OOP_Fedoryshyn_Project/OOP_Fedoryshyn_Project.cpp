#include <iostream>
#include "Ticket.h"
#include "Visitor.h"
#include "TicketSale.h"
#include "ConcertManager.h"
#include "TicketUtils.h"

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

int main()
{
    // Пункт 6. Створення 5 об'єктів у статичній пам'яті.
    // Пункт 7 - визначено перший з двох масивів об'єктів
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

    // Пункт 6. Створення 5 об'єктів у динамічній пам'яті.
    // Пункт 7 - визначено другий з двох масивів об'єктів
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

    // Пункт 8. Демонстрація роботи з об'єктами в масивах.

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

    // Пункт 9. Демонстрація всіх методів класу Ticket.

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

    // Пункт 9. Демонстрація всіх методів класу Visitor.

    std::cout << std::endl;
    std::cout << "=== VISITOR METHODS ===" << std::endl;

    visitors[0].ShowInfo();

    visitors[0].AddBalance(500);

    visitors[1].AddBalance(1000, true);

    // Пункт 10 - демонстрація сценарію взаємодії двох об'єктів: Відвідувач купляє квиток
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

    // Пункт 11. Вказівник на екземпляр класу.

    Ticket* ticket_pointer = &tickets[0];

    std::cout << std::endl;
    std::cout << "=== POINTER TO TICKET ===" << std::endl;

    ticket_pointer->ShowInfo();

    ticket_pointer->ChangePrice(1300);

    std::cout << std::endl << "Ticket after changing price through pointer:" << std::endl;
    ticket_pointer->ShowInfo();

    // Пункт 12. Робота з динамічною пам'яттю та сортуванням.

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

    // Пункт 2. Демонстрація задання полів даних як початкових значень констант і посилань
    manager.ShowConstAndReference();

    manager.name = "Petro";

    manager.ShowConstAndReference();

    // Пункт 4. Демонстрація статичного поля та статичного методу.

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

    // (3) Практичне завдання

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

    delete[] visitors;

    return 0;
}