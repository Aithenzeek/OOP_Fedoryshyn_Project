#pragma once

#include "Ticket.h"

void Service_Static(Ticket tickets[], int& count, double minPrice);

void Service_Dinamic(Ticket*& tickets, int& count, double minPrice);

#include <fstream>
#include <stdexcept>
#include <string>

// Пункт 7(5) - Універсальна функція для роботи з файлами
template <typename T>
void Service(T& object, const std::string& fileName, bool writeMode)
{
    // Випадок 1 - назва файлу не задана
    if (fileName.empty())
    {
        throw std::invalid_argument("File name cannot be empty.");
    }

    if (writeMode)
    {
        // Випадок 2 - файл не вдалося відкрити для запису
        std::ofstream file(fileName);

        if (!file.is_open())
        {
            throw std::runtime_error("Cannot open file for writing.");
        }

        object.Write(file);

        // Випадок 3 - помилка під час запису
        if (!file.good())
        {
            throw std::runtime_error("File writing error.");
        }

        file.close();

        if (file.fail())
        {
            throw std::runtime_error("Cannot close output file.");
        }
    }
    else
    {
        // Випадок 4 - файл не вдалося відкрити для читання
        std::ifstream file(fileName);

        if (!file.is_open())
        {
            throw std::runtime_error("Cannot open file for reading.");
        }

        object.Read(file);

        // Випадок 5 - помилка читання або пошкоджені дані
        if (file.bad())
        {
            throw std::runtime_error("File reading error.");
        }

        file.close();
    }
}