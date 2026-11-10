#pragma once

#include <iostream>

// Пункт 5(6) — шаблон класу з п'ятьма параметрами типів
template <
    typename TId,
    typename TName,
    typename TPrice,
    typename TQuantity,
    typename TAdditional
>
class TemplateContainer
{
public:
    TemplateContainer(
        const TId& id,
        const TName& name,
        const TPrice& price,
        const TQuantity& quantity,
        const TAdditional& additional)
        : id_(id),
        name_(name),
        price_(price),
        quantity_(quantity),
        additional_(additional)
    {
    }

    void SetId(const TId& id)
    {
        id_ = id;
    }

    void SetName(const TName& name)
    {
        name_ = name;
    }

    void SetPrice(const TPrice& price)
    {
        price_ = price;
    }

    void SetQuantity(const TQuantity& quantity)
    {
        quantity_ = quantity;
    }

    void SetAdditional(const TAdditional& additional)
    {
        additional_ = additional;
    }

    const TId& GetId() const
    {
        return id_;
    }

    const TName& GetName() const
    {
        return name_;
    }

    const TPrice& GetPrice() const
    {
        return price_;
    }

    const TQuantity& GetQuantity() const
    {
        return quantity_;
    }

    const TAdditional& GetAdditional() const
    {
        return additional_;
    }

    void ShowInfo() const
    {
        std::cout << "ID: " << id_ << std::endl;
        std::cout << "Name: " << name_ << std::endl;
        std::cout << "Price: " << price_ << std::endl;
        std::cout << "Quantity: " << quantity_ << std::endl;
        std::cout << "Additional: " << additional_ << std::endl;
    }

private:
    TId id_;
    TName name_;
    TPrice price_;
    TQuantity quantity_;
    TAdditional additional_;
};
