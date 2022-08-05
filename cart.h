//
// Created by Mitchell Toth on 8/2/22.
//

#include <iostream>
#include <string>
#include <fstream>
//#include <stdio.h>
#include <vector>
#include <utility>

#ifndef GROUPPROJECT_CART_H
#define GROUPPROJECT_CART_H


class Cart{
private:
    std::string filename;
    std::string user;
public:
    Cart();
    Cart(std::string user, std::string filename);
    //parameters still need to be filled in, but I will do that towards the end
    std::vector<std::pair<float, float>> priceQuant;
    void ViewCart(std::string filename);
    void editCart(std::string filename);
    std::vector<std::pair<std::string, float>> CheckOut(std::string filename, std::vector<std::pair<std::string, float>>& itemchange);
    void addItem(std::string filename, std::string Item, int quantity, float price, std::string user);
};




#endif //GROUPPROJECT_CART_H

/*
Just reminders of what all needed to be implemented:

View all items in a category
View all items in the user's shopping cart
Add item from a category to their shopping cart
Remove an item from their shopping cart
Checkout the items currently in their cart
Removes items from the user's shopping cart
Edits stock information to lower the stock accordingly
 ****Be able to logout, log back in and come back to the cart progress.
*/