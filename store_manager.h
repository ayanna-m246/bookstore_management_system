#ifndef STORE_MANAGER_H
#define STORE_MANAGER_H

#pragma once

class store_manager
{
public:
    store_manager(string n):name(n){};
    void addBook(Item* item){
        obj->addItem(item);
    }
    void addMagazine(Item* item){
        obj->addItem(item);
    }
    void updateBookPrice(string ISBN, double newPrice){
        obj->updateBookPrice(ISBN,newPrice);
    }
    void updateBookStock(string ISBN, int newStock){
        obj->updateBookStock(ISBN,newStock);
    }

private:
    string name;
    store* obj;
};

#endif