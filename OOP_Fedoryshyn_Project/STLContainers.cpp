#include "STLContainers.h"

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <forward_list>
#include <algorithm>
#include <functional>

// Пункт 1(7) — демонстрація контейнерів STL
void RunSTLContainersDemo()
{
    Ticket ticket1(
        101, 500, "Rock Concert",
        "20.12.2026", "19:00", "Standard",
        1, 10, "Standard", false
    );

    Ticket ticket2(
        102, 1000, "Rock Concert",
        "20.12.2026", "19:00", "VIP",
        1, 15, "VIP", false
    );

    Ticket ticket3(
        103, 750, "Rock Concert",
        "20.12.2026", "19:00", "Fan Zone",
        2, 20, "Fan Zone", false
    );

    std::cout << "\n=== VECTOR ===" << std::endl;

    std::vector<Ticket> ticketsVector;

    ticketsVector.push_back(ticket1);
    ticketsVector.push_back(ticket2);
    ticketsVector.push_back(ticket3);

    std::cout << "Number of tickets: "
        << ticketsVector.size() << std::endl;

    std::cout << "First ticket price: "
        << ticketsVector[0].price << std::endl;

    ticketsVector.erase(ticketsVector.begin() + 1);

    std::cout << "After erase: "
        << ticketsVector.size() << " tickets" << std::endl;


    std::cout << "\n=== LIST ===" << std::endl;

    std::list<Ticket> ticketsList;

    ticketsList.push_back(ticket1);
    ticketsList.push_back(ticket2);
    ticketsList.push_front(ticket3);

    std::cout << "Number of tickets: "
        << ticketsList.size() << std::endl;

    std::cout << "First ticket ID: "
        << ticketsList.front().id << std::endl;

    ticketsList.pop_front();

    std::cout << "After pop_front: "
        << ticketsList.size() << " tickets" << std::endl;


    std::cout << "\n=== DEQUE ===" << std::endl;

    std::deque<Ticket> ticketsDeque;

    ticketsDeque.push_back(ticket1);
    ticketsDeque.push_back(ticket2);
    ticketsDeque.push_front(ticket3);

    std::cout << "Number of tickets: "
        << ticketsDeque.size() << std::endl;

    std::cout << "First ticket ID: "
        << ticketsDeque.front().id << std::endl;

    ticketsDeque.pop_back();

    std::cout << "After pop_back: "
        << ticketsDeque.size() << " tickets" << std::endl;


    std::cout << "\n=== SET ===" << std::endl;

    std::set<Ticket, TicketPriceLess> ticketsSet;

    ticketsSet.insert(ticket1);
    ticketsSet.insert(ticket2);
    ticketsSet.insert(ticket3);

    std::cout << "Number of tickets: "
        << ticketsSet.size() << std::endl;

    auto setIterator = ticketsSet.find(ticket2);

    if (setIterator != ticketsSet.end())
    {
        std::cout << "Found ticket ID: "
            << setIterator->id << std::endl;
    }

    ticketsSet.erase(ticket1);

    std::cout << "After erase: "
        << ticketsSet.size() << " tickets" << std::endl;


    std::cout << "\n=== MULTISET ===" << std::endl;

    std::multiset<Ticket, TicketPriceOnly> ticketsMultiset;

    ticketsMultiset.insert(ticket1);
    ticketsMultiset.insert(ticket2);
    ticketsMultiset.insert(ticket3);
    ticketsMultiset.insert(ticket1);

    std::cout << "Number of tickets: "
        << ticketsMultiset.size() << std::endl;

    std::cout << "Tickets with price 500: "
        << ticketsMultiset.count(ticket1) << std::endl;

    auto multiSetIterator = ticketsMultiset.find(ticket1);

    if (multiSetIterator != ticketsMultiset.end())
    {
        ticketsMultiset.erase(multiSetIterator);
    }

    std::cout << "After erasing one ticket: "
        << ticketsMultiset.size() << " tickets" << std::endl;


    std::cout << "\n=== MAP ===" << std::endl;

    std::map<int, Ticket> ticketsMap;

    ticketsMap.insert({ ticket1.id, ticket1 });
    ticketsMap.insert({ ticket2.id, ticket2 });
    ticketsMap.insert({ ticket3.id, ticket3 });

    std::cout << "Number of tickets: "
        << ticketsMap.size() << std::endl;

    std::cout << "Ticket with ID 102 costs: "
        << ticketsMap.at(102).price << std::endl;

    ticketsMap.erase(101);

    std::cout << "After erase: "
        << ticketsMap.size() << " tickets" << std::endl;


    std::cout << "\n=== MULTIMAP ===" << std::endl;

    std::multimap<int, Ticket> ticketsMultimap;

    ticketsMultimap.insert({ 1, ticket1 });
    ticketsMultimap.insert({ 1, ticket2 });
    ticketsMultimap.insert({ 2, ticket3 });

    std::cout << "Number of entries: "
        << ticketsMultimap.size() << std::endl;

    auto range = ticketsMultimap.equal_range(1);

    std::cout << "Tickets with key 1:" << std::endl;

    for (auto iterator = range.first;
        iterator != range.second;
        ++iterator)
    {
        std::cout << "Ticket ID: "
            << iterator->second.id << std::endl;
    }

    auto multiMapIterator = ticketsMultimap.find(2);

    if (multiMapIterator != ticketsMultimap.end())
    {
        ticketsMultimap.erase(multiMapIterator);
    }

    std::cout << "After erase: "
        << ticketsMultimap.size() << " entries" << std::endl;


    std::cout << "\n=== STACK ===" << std::endl;

    std::stack<Ticket> ticketsStack;

    ticketsStack.push(ticket1);
    ticketsStack.push(ticket2);
    ticketsStack.push(ticket3);

    std::cout << "Number of tickets: "
        << ticketsStack.size() << std::endl;

    std::cout << "Top ticket ID: "
        << ticketsStack.top().id << std::endl;

    ticketsStack.pop();

    std::cout << "After pop: "
        << ticketsStack.size() << " tickets" << std::endl;


    std::cout << "\n=== QUEUE ===" << std::endl;

    std::queue<Ticket> ticketsQueue;

    ticketsQueue.push(ticket1);
    ticketsQueue.push(ticket2);
    ticketsQueue.push(ticket3);

    std::cout << "Number of tickets: "
        << ticketsQueue.size() << std::endl;

    std::cout << "First ticket ID: "
        << ticketsQueue.front().id << std::endl;

    ticketsQueue.pop();

    std::cout << "After pop: "
        << ticketsQueue.size() << " tickets" << std::endl;


    std::cout << "\n=== PRIORITY QUEUE ===" << std::endl;

    std::priority_queue<
        Ticket,
        std::vector<Ticket>,
        TicketPriceLess
    > ticketsPriorityQueue;

    ticketsPriorityQueue.push(ticket1);
    ticketsPriorityQueue.push(ticket2);
    ticketsPriorityQueue.push(ticket3);

    std::cout << "Number of tickets: "
        << ticketsPriorityQueue.size() << std::endl;

    std::cout << "Highest priority ticket ID: "
        << ticketsPriorityQueue.top().id << std::endl;

    ticketsPriorityQueue.pop();

    std::cout << "After pop: "
        << ticketsPriorityQueue.size() << " tickets" << std::endl;
}

void RunSTLIteratorsDemo()
{
    std::cout << "\n=== STL ITERATORS ===" << std::endl;

    Ticket ticket1(
        201, 500, "Rock Concert",
        "20.12.2026", "19:00", "Standard",
        1, 10, "Standard", false
    );

    Ticket ticket2(
        202, 1000, "Rock Concert",
        "20.12.2026", "19:00", "VIP",
        1, 15, "VIP", false
    );

    Ticket ticket3(
        203, 750, "Rock Concert",
        "20.12.2026", "19:00", "Fan Zone",
        2, 20, "Fan Zone", false
    );


    std::cout << "\n--- Input iterator ---" << std::endl;

    std::vector<Ticket> inputTickets =
    {
        ticket1, ticket2, ticket3
    };

    std::cout << "Enter a ticket ID: " << std::flush;

    std::istream_iterator<int> inputIterator(std::cin);
    std::istream_iterator<int> inputEnd;

    int enteredId = *inputIterator;

    std::cout << "Entered ID: " << enteredId << std::endl;


    std::cout << "\n--- Output iterator ---" << std::endl;

    std::vector<int> outputData(3);

    std::ostream_iterator<int> outputIterator(
        std::cout, " "
    );

    std::cout << "Ticket IDs: ";

    for (const Ticket& ticket : inputTickets)
    {
        *outputIterator++ = ticket.id;
    }

    std::cout << std::endl;


    std::cout << "\n--- Forward iterator ---" << std::endl;

    std::forward_list<int> forwardTickets =
    {
        201, 202, 203
    };

    std::forward_list<int>::iterator forwardIterator =
        forwardTickets.begin();

    while (forwardIterator != forwardTickets.end())
    {
        std::cout << *forwardIterator << " ";
        ++forwardIterator;
    }

    std::cout << std::endl;


    std::cout << "\n--- Bidirectional iterator ---" << std::endl;

    std::list<int> bidirectionalTickets =
    {
        201, 202, 203
    };

    std::list<int>::iterator bidirectionalIterator =
        bidirectionalTickets.begin();

    std::cout << "Forward: ";

    for (; bidirectionalIterator != bidirectionalTickets.end();
         ++bidirectionalIterator)
    {
        std::cout << *bidirectionalIterator << " ";
    }

    std::cout << "\nBackward: ";

    bidirectionalIterator = bidirectionalTickets.end();

    while (bidirectionalIterator != bidirectionalTickets.begin())
    {
        --bidirectionalIterator;
        std::cout << *bidirectionalIterator << " ";
    }

    std::cout << std::endl;


    std::cout << "\n--- Random access iterator ---" << std::endl;

    std::vector<int> randomTickets =
    {
        201, 202, 203
    };

    std::vector<int>::iterator randomIterator =
        randomTickets.begin();

    std::cout << "First element: "
        << *randomIterator << std::endl;

    std::cout << "Third element: "
        << *(randomIterator + 2) << std::endl;

    randomIterator += 2;

    std::cout << "After += 2: "
        << *randomIterator << std::endl;
}


void RunSTLAlgorithmsDemo()
{
    std::cout << "\n=== STL ALGORITHMS ===" << std::endl;

    std::vector<Ticket> tickets =
    {
        Ticket(301, 500, "Rock Concert",
            "20.12.2026", "19:00", "Standard",
            1, 10, "Standard", false),

        Ticket(302, 1000, "Rock Concert",
            "20.12.2026", "19:00", "VIP",
            1, 15, "VIP", false),

        Ticket(303, 750, "Rock Concert",
            "20.12.2026", "19:00", "Fan Zone",
            2, 20, "Fan Zone", false)
    };

    std::cout << "\n--- SORT ---" << std::endl;

    std::sort(
        tickets.begin(),
        tickets.end(),
        [](const Ticket& first, const Ticket& second)
        {
            return first.price < second.price;
        }
    );

    for (const Ticket& ticket : tickets)
    {
        std::cout << "ID: " << ticket.id
            << ", Price: " << ticket.price << std::endl;
    }

    std::cout << "\n--- FIND_IF ---" << std::endl;

    auto foundTicket = std::find_if(
        tickets.begin(),
        tickets.end(),
        [](const Ticket& ticket)
        {
            return ticket.price >= 750;
        }
    );

    if (foundTicket != tickets.end())
    {
        std::cout << "Found ticket ID: "
            << foundTicket->id << std::endl;
    }

    std::cout << "\n--- COUNT_IF ---" << std::endl;

    int expensiveTickets = std::count_if(
        tickets.begin(),
        tickets.end(),
        [](const Ticket& ticket)
        {
            return ticket.price >= 750;
        }
    );

    std::cout << "Tickets with price >= 750: "
        << expensiveTickets << std::endl;

    std::cout << "\n--- FOR_EACH ---" << std::endl;

    std::for_each(
        tickets.begin(),
        tickets.end(),
        [](const Ticket& ticket)
        {
            std::cout << "ID: " << ticket.id
                << ", Price: " << ticket.price << std::endl;
        }
    );

    std::cout << "\n--- REMOVE_IF ---" << std::endl;

    tickets.erase(
        std::remove_if(
            tickets.begin(),
            tickets.end(),
            [](const Ticket& ticket)
            {
                return ticket.price < 700;
            }
        ),
        tickets.end()
    );

    std::cout << "Tickets after removing prices below 700:"
        << std::endl;

    for (const Ticket& ticket : tickets)
    {
        std::cout << "ID: " << ticket.id
            << ", Price: " << ticket.price << std::endl;
    }
}

// Пункт 3(7) — демонстрація п'яти алгоритмів STL
void RunSTLFunctorsDemo()
{
    std::cout << "\n=== STL FUNCTION OBJECTS ===" << std::endl;

    int first = 20;
    int second = 5;

    std::cout << "\n--- Arithmetic functors ---" << std::endl;

    std::cout << "plus: "
        << std::plus<int>()(first, second) << std::endl;

    std::cout << "minus: "
        << std::minus<int>()(first, second) << std::endl;

    std::cout << "multiplies: "
        << std::multiplies<int>()(first, second) << std::endl;

    std::cout << "divides: "
        << std::divides<int>()(first, second) << std::endl;

    std::cout << "modulus: "
        << std::modulus<int>()(first, second) << std::endl;

    std::cout << "negate: "
        << std::negate<int>()(first) << std::endl;

    std::cout << "\n--- Comparison functors ---" << std::endl;

    std::cout << "equal_to: "
        << std::equal_to<int>()(first, second) << std::endl;

    std::cout << "not_equal_to: "
        << std::not_equal_to<int>()(first, second) << std::endl;

    std::cout << "greater: "
        << std::greater<int>()(first, second) << std::endl;

    std::cout << "less: "
        << std::less<int>()(first, second) << std::endl;

    std::cout << "greater_equal: "
        << std::greater_equal<int>()(first, second) << std::endl;

    std::cout << "less_equal: "
        << std::less_equal<int>()(first, second) << std::endl;

    std::cout << "\n--- Logical functors ---" << std::endl;

    bool firstCondition = true;
    bool secondCondition = false;

    std::cout << "logical_and: "
        << std::logical_and<bool>()(
            firstCondition, secondCondition
            ) << std::endl;

    std::cout << "logical_or: "
        << std::logical_or<bool>()(
            firstCondition, secondCondition
            ) << std::endl;

    std::cout << "logical_not: "
        << std::logical_not<bool>()(
            firstCondition
            ) << std::endl;
}