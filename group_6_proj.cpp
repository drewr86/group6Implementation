/************************************************************************************
  group 6 project.cpp : This file contains the 'main' function for the program.
  by: Connor Chrismond - CC3906
      Drew Russell - DRR257
      Mitchell Toth - MJT371
      Ethan Heverly - eah611
      
*************************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
//#include <random>
#include "login.h"
#include "account.h"
#include "inventory.h"
#include "item.h"
#include "Cart.h"

using namespace std;

//I decided to put the menus into funtions to keep them seperate and to keep the main funtion unclutterd 
// I deffined all the funtions here then added the code down below the main
int loginmenu();
int mainmenu(std::string loggedUser);
int itemsmenu();
//int cartmenu();
//int accountmenu();
vector<Item> items;
string loggedUser;

void buildItems(vector<Item> &items){
    ifstream infile;
    infile.open("inventory.txt");
    
    int itemid, qty;
    string title, developer;
    float price;
    
    while(infile >> itemid >> title >> developer >> qty >> price){
        Item temp(itemid, title, developer, qty, price);
        items.push_back(temp);
    }
}

//removes spaces for title
string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

//this is the main funtion for the whole program 
int main(){
    buildItems(items);
    // main calls the login menu first thing
    loginmenu();
    return 0;
}

// this is the login menu 
int loginmenu() {
    while (1) {
        int option = -1;
        cout << "1. login" << endl << "2. create new account" << endl << "3. exit program" << endl;
        cout << "What do you want to do? (type the number you want and hit enter) ";
        cin >> option;
        cout << endl;

        if (option == 1) {
            //needs to ask for login information then take you to the main menu if success or ask to repeat if not 
            loggedUser = LoginManager().login();
            
            if(LoginManager().accessGranted == 1){
                mainmenu(loggedUser);
            }
            else{
                cout << endl << "Please enter a correct username and password" << endl << endl;
                loginmenu();
            }
        }

        else if (option == 2) {
            //needs to ask for information to create new accont then take you to the main menu when done
            //creataccount();
        }

        else if (option == 3) {
            // this exits the program entirely
            cout << "ending program goodbye" << endl;
            break;
        }

        //this is the catch all for invalid inputs
        else {
            cout << "not a valid option" << endl << endl;
        }
    }
    return 0;
}



// this is the main menu
int mainmenu(std::string loggedUser) {
    while (1) {
        int option = -1;
        cout <<"Welcome " << loggedUser << endl;
        cout << endl <<"1. view available items by category" << endl << "2. view all items in your cart" << endl << "3. add item to cart" << endl << "4. remove item from cart" << endl << "5. checkout" << endl << "6. logout" << endl;
        cout << "What do you want to do? (type the number you want and hit enter) ";
        cin >> option;
        cout << endl;
        std::string filehold = "carts.txt";
        Cart userCart(loggedUser, filehold);

        if (option == 1) {
            itemsmenu();
        }
        else if (option == 2) {
            userCart.ViewCart(filehold);
        }
        else if (option == 3) {
            bool check42 = true;
            float price;
            int quant;
            string category, name;
            while (check42 == true){

            }
        }
        else if (option == 4) {
           userCart.ViewCart(filehold);
        }
        else if (option == 5) {
            userCart.CheckOut(filehold);
        }
        else if (option == 6) {
            //logout
            loginmenu();
        }
        else {
            cout << "not a valid option" << endl << endl;
        }
    }
    return 0;
}

// the items menu that branches from the main menu
int itemsmenu() {
    while (1) {
        int option = -1;
        cout << "1. show all items" << endl << "2. search by developer" << endl << "3. search by title" << endl << "4. return to main menu" << endl;
        cout << "What do you want to do? (type the number you want and hit enter) ";
        cin >> option;
        cout << endl;

        if (option == 1) {
          Inventory().ViewInventory();
        }
        else if (option == 2) {
            cout << endl << "What is developer's first name? Ex:john, jane, etc" << endl << "Developer:";
            string dev = "";
            bool foundDev = false;
            cin >> dev;
            
            int i = 0;
            while(i < items.size()-1 && !foundDev){
                if (dev == items.at(i).getdeveloper()){
                    cout << endl << "We have " << items.at(i).getqty() << " books written by " << dev << endl;
                    foundDev = true;
                }
                i++;
            }
        }
        else if (option == 3) {
            string title;
            bool foundTitle = false;
            
            cout << endl << "What is title? Ex: Coding for Dummies" << endl << "Title:";
            cin.ignore();
            getline(cin, title);
            
            int i = 0;
            while(i < items.size()-1 && !foundTitle){
                string tempTitle = removeSpaces(title);
                
                if (tempTitle == items.at(i).gettitle()){
                    cout << endl << "We have " << items.at(i).getqty() << " books written called " << title << endl;
                    foundTitle = true;
                }
                i++;
            }
        }
        else if (option == 4) {
            break;
        }
        else {
            cout << "not a valid option" << endl << endl;
        }
    }
    return 0;
}
