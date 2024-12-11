#ifndef STORE_H
#define STORE_H

#include "book.h"      
#include "magazine.h"  
#include <vector>     
#include"Item.h"

#pragma once

class store{

public:
    store() = default;

    // Add an item (book or magazine) to the inventory
    void addItem(Item* item) {
        inventory.push_back(item);
        cout << "Item added: " << item->getTitle() << endl;
    }

    // Remove a book by ISBN
    void removeBook( string& ISBN) {
        for (auto it = inventory.begin(); it != inventory.end();) {
            book* bookItem = dynamic_cast<book*>(*it); 
            if (bookItem && bookItem->getISBN() == ISBN) {
                cout << "Removing book: " << bookItem->getTitle() << " (ISBN: " << ISBN << ")" << endl;
                delete *it;               
                it = inventory.erase(it); 
            } else {
                ++it; // Increment only if no deletion
            }
        }
    }

    // Update book stock by ISBN
    void updateBookStock(const string& ISBN, int quantity) {
        for (auto& item : inventory) {
            book* bookItem = dynamic_cast<book*>(item); 
            if (bookItem && bookItem->getISBN() == ISBN) {
                bookItem->updateStock(quantity);
                cout << "Updated stock for: " << bookItem->getTitle() << endl;
                return;
            }
        }
        cout << "Book with ISBN " << ISBN << " not found." << endl;
    }
    // Update book price by ISBN
    void updateBookPrice(const string& ISBN, double price) {
        for (auto& item : inventory) {
            book* bookItem = dynamic_cast<book*>(item);
            if (bookItem && bookItem->getISBN() == ISBN) {
                bookItem->update_price(price);
                cout << "Updated price for: " << bookItem->getTitle() << endl;
                return;
            }
        }
        cout << "Book with ISBN " << ISBN << " not found." << endl;
    }

    // Display all inventory
    void displayInventory() const {
        cout << "\nInventory:" << endl;
        for (const auto& item : inventory) {
            item->displayDetails(); 
        }
    }

    // Generate inventory report 
    void generateReport() const {
        cout << "\nOut-of-Stock Items:" << endl;
        for (const auto& item : inventory) {
            if (item->getStock() == 0) {
                item->displayDetails();
            }
        }
    }

    // Find a book by title
    Item* findBookByTitle(const string& title) const {
        for (const auto& item : inventory) {
            if (item->getTitle() == title) {
                return item; 
            }
        }
        return nullptr;
    }

    ~store() {
        for (auto& item : inventory) {
            delete item;
        }
        inventory.clear();
    }

private:
    vector<Item*> inventory; 
};



#endif