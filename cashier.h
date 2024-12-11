#ifndef CASHIER_H
#define CASHIER_H
#include "discount.h"

#pragma once

class cashier
{
public:
    cashier(string n, store* storeObj) : name(n), obj(storeObj) {}

    // Process a single cart item (works for both books and magazines)
    double processCartItem(string title, int quantity,Discount* discount) {
        Item* item = obj->findBookByTitle(title); 
        if (item) {
            if (item->getStock() >= quantity) {
                double totalCost = item->getPrice() * quantity;
            if (discount) {
                totalCost = discount->apply(item->getPrice(), quantity);
            }
                item->reduceStock(quantity);
                cout << item->getTitle() << "\t" << quantity << "\t\tRs. " << totalCost << endl;
                return totalCost;
            } else {
                cout << "Insufficient stock for " << item->getTitle() << ". Skipping." << endl;
                return 0.0;
            }
        } else {
            cout << title << " not found. Skipping." << endl;
            return 0.0;
        }
    }
private:
    string name;
    store*obj;

};

#endif