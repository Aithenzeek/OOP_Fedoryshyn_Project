#pragma once

#include <iostream>

// Пункт 3(5) Базовий клас із невіртуальним деструктором
class NonVirtualBase
{
public:
    ~NonVirtualBase()
    {
        std::cout << "NonVirtualBase destructor" << std::endl;
    }
};

class NonVirtualDerived : public NonVirtualBase
{
public:
    ~NonVirtualDerived()
    {
        std::cout << "NonVirtualDerived destructor" << std::endl;
    }
};

// Пункт 3(5) Базовий клас із віртуальним деструктором
class VirtualBase
{
public:
    virtual ~VirtualBase()
    {
        std::cout << "VirtualBase destructor" << std::endl;
    }
};

class VirtualDerived : public VirtualBase
{
public:
    ~VirtualDerived() override
    {
        std::cout << "VirtualDerived destructor" << std::endl;
    }
};