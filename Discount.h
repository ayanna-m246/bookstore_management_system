#ifndef DISCOUNT_H
#define DISCOUNT_H

#pragma once

class Discount
{
public:
    virtual double apply(double price, int quantity) const = 0;
    virtual ~Discount() = default; 
};

class PercentageDiscount : public Discount 
{
public:
    PercentageDiscount(double percentage) : percentage(percentage) {}

    double apply(double price, int quantity)const override{
        double total = price * quantity;
        return total - (total * percentage / 100);
    }

private:
    double percentage;
};

class FixedAmountDiscount : public Discount
{
public:
    FixedAmountDiscount(double amount) : amount(amount) {}

    double apply(double price, int quantity) const override{
        double total = price * quantity;
        return max(0.0, total - amount); 
    }

private:
    double amount;
};

class BuyOneGetOneDiscount : public Discount {
public:
    double apply(double price, int quantity) const override{
        int chargeableItems = (quantity / 2) + (quantity % 2); 
        return chargeableItems * price;
    }
};

#endif