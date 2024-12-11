#ifndef BOOK_H
#define BOOK_H

#include "Item.h" 

#pragma once


class book : public Item
{
public:
    book(string title, string author, string publisher, int stock, double price, double cost, string ISBN)
        : Item(title, publisher, price, cost, stock), author(author), ISBN(ISBN) {}

    void displayDetails() override {
        cout << "Book Title: " << getTitle() << ", Author: " << author
             << ", Publisher: " << Item::publisher << ", Price: Rs. " << getPrice()
             << ", Stock: " << getStock() << ", ISBN: " << ISBN << endl;
    }
    
    string getISBN() { return ISBN; }
    
 private:
      string title,author,publisher,ISBN;
      int stock;
      double price,cost;


};

#endif