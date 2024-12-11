#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "Item.h" 

#pragma once

class magazine : public Item
{
public:
    magazine(string title, string publisher, string issue, double price,double cost, int stock)
        : Item(title, publisher, price,cost, stock), issue(issue) {}

   void displayDetails() override {
        cout << "Magazine Title: " << getTitle() << ", Publisher: " << Item::publisher<< ", Issue: " << issue << ", Price: Rs. " << getPrice()
             << ", Stock: " << getStock() << endl;
    }

    string getIssue() {
        return issue;
    }


private:
    string title, publisher,issue;
    int stock;
    double price,cost;
};

#endif