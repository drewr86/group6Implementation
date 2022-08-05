#include <string>

using namespace std;

#ifndef ITEM_H
#define ITEM_H

class Item{
    private:
        int itemid = 0, qty = 0;
        string title = "", developer = "";
        float price = 0.00;
    public:
        Item();
        Item(int itemid, string title, string developer, int qty, float price){
            this->itemid = itemid;
            this->title = title;
            this->developer = developer;
            this->qty = qty;
            this->price = price;
        };
        
        int getitemid() {return itemid; };
        string gettitle() {return title; };
        string getdeveloper() {return developer; };
        int getqty() {return qty; };
        float getprice() {return price; };
        
        void setitemid(int itemid) {this->itemid = itemid; };
        void settitle(string title) {this->title = title; };
        void setdeveloper(string developer) {this->developer = developer; };
        void setqty(int qty) {this->qty = qty; };
        void setprice(float price) {this->price = price; };
};

#endif // ITEM_H