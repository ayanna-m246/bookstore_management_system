#ifndef ITEM_H
#define ITEM_H

#include<string>
#include<iostream>
using namespace std;
#pragma once

class Item
{
public:
    Item(string title, string publisher, double price,double cost, int stock): title(title), publisher(publisher), price(price),cost(cost), stock(stock) {}
    virtual ~Item() = default;

    virtual void displayDetails() {
    }

    virtual void updateStock(int quantity){
        stock += quantity;
    }
    virtual void update_price(double q){
        price=q;
     }
    virtual void update_cost(double q){
        cost=q;
     } 


    virtual double getPrice(){
        return price;
    }

    virtual string getTitle() {
        return title;
    }

    virtual int getStock() {
        return stock;
    }

    virtual void reduceStock(int quantity){
        if (quantity <= stock) {
            stock -= quantity;
        } else {
            cout << "Insufficient stock for " << title << endl;
        }
    }

protected:
    string title;
    string publisher;
    double price, cost;
    int stock;
};

#endif