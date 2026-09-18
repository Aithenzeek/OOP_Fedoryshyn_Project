#include <iostream>
#include "Ticket.h"

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

    delete[] visitors;

    return 0;
}