#include <map>
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "cashier.h"

#pragma once

class customer
{
public:
    customer(string n, string c):name(n), contact_no(c){};

    void browseItems(){
        obj->displayInventory();
    };

    // Add items to the cart
    void addToCart(string title, int quantity) {
        if (cart.find(title) != cart.end()) {
            cart[title] += quantity; 
        } else {
            cart[title] = quantity;
        }
    }

    // Generate the bill and finalize the purchase
     void checkout(cashier& cashierObj,Discount* discount) {
        double totalCost = 0.0;
        cout << "Bill for " << name << ":" << endl;
        cout << "------------------------------------" << endl;
        cout << "Title\t\tQuantity\tPrice" << endl;

        for (const auto& item : cart) {
            string title = item.first;
            int quantity = item.second;
            double cost = cashierObj.processCartItem(title, quantity, discount); 
            if (cost > 0) {
                totalCost += cost;
            }
        }

        cout << "------------------------------------" << endl;
        cout << "Total Cost: Rs." << totalCost << endl;
        cout << "Thank you for your purchase, " << name << "!" << endl;
        cart.clear(); 
    }


    
    
private:
    string name;
    string contact_no;
    store* obj;
    map<string, int> cart; // title and quantity of books purchased

};

#endif