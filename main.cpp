#include "book.h"
#include "magazine.h"
#include "Item.h"
#include "store.h"
#include "store_manager.h"
#include "customer.h"
#include "cashier.h"
#include "Discount.h"
#include<iostream>
#include<string>

int main() {
    // Create store and add books & magazines
    store bookstore;

    bookstore.addItem(new book("Sherlock Holmes", "Arthur Conan Doyle","Penguin Random House India",10, 50.0, 10.0,"12345"));
    bookstore.addItem(new book("Harry Potter and the Goblet of fire", "JK.Rowling","Bloomsbury Publishing",10, 50.0, 25.0,"12456"));
    bookstore.addItem(new book("The Hunger Games", "Suzanne Collins","Scholastic India",5, 50.0, 20.0,"23451"));

    bookstore.addItem(new magazine("National Geographic", "NatGeo", "March 2024", 50.0,30.0, 20));
    bookstore.addItem(new magazine("Time", "Time Inc.", "April 2024", 75.0,47.0, 10));


    bookstore.updateBookStock("23451", 10);

    // Create a cashier
    cashier cashier("John",&bookstore);

    // Create a customer
    customer customer("Alice","987654321");

    // Create specific discounts
    PercentageDiscount percentageDiscount(10.0);  // 10% off
    FixedAmountDiscount fixedDiscount(50.0);      // Rs. 50 off
    BuyOneGetOneDiscount bogoDiscount;

    // Display initial inventory
    cout << "Initial Inventory:" << endl;
    bookstore.displayInventory();

    // Customer adds items to the cart
    cout << "\nAdding items to cart:" << endl;
    customer.addToCart("Harry Potter and the Goblet of fire", 3); 
    customer.addToCart("Sherlock Holmes", 2); 
    customer.addToCart("The Hunger Games", 7); 

    // Customer can check out with one out of many discounts

    cout << "\nProcessing Checkout with 10% Discount:" << endl;
    customer.checkout(cashier, &percentageDiscount);

    // cout << "\nProcessing Checkout with Fixed Rs. 50 Discount:" << endl;
    // customer.checkout(cashier, &fixedDiscount);

    // cout << "\nProcessing Checkout with Buy One Get One Free Discount:" << endl;
    // customer.checkout(cashier, &bogoDiscount);


    // Display updated inventory
    cout << "\nUpdated Inventory:" << endl;
    bookstore.displayInventory();

    return 0;
}

