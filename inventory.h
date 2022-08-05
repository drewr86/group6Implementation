//
// Created by Mitchell Toth on 8/2/22.
//

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <utility>
#pragma once
#ifndef GROUPPROJECT_INVENTORY_H
#define GROUPPROJECT_INVENTORY_H

using namespace std;

class Inventory{
private:
    string filename = "inventory.txt";
public:
    Inventory(){
        ifstream myfile;
        myfile.open(filename);
        string line;
        while (getline(myfile, line)){

        }
        myfile.close();
    }
    //parameters still need to be filled in, but I will do that towards the end
    vector<pair<float, float>> priceQuant;

    void ViewInventory(string filename){
        string line;
        ifstream myfile;
        myfile.open(filename);
        std::cout << "Here are the contents of your cart:" <<std::endl;
        while (myfile.good()){
            if (myfile.eof()){
                break;
            }
            if (!myfile.eof() && !myfile){
                cerr << "You Need to add items first!" <<std::endl;
                throw;
            }
            getline(myfile, line);
            cout << line << std::endl;
        }
        cout << std::endl;
        myfile.close();
    }

    vector<pair<string, float>> editInventory(std::string filename, std::vector<std::pair<std::string, float>>& itemchange){
        ifstream myfile;
        vector<int> quantvec;
        vector<string> Devec;
        vector<float> Pvec;
        vector<string> ItemV;
        vector<int> indexc;
        string name;
        string dev;
        int quantity;
        float price;
        int i = -1;


        myfile.open(filename);
        while (myfile >> name >> dev >> quantity >> price){
            i +=1;
            if (itemchange[i].first == name){
                continue;
            }
            else{
                ItemV.push_back(name);
                Devec.push_back(dev);
                quantvec.push_back(quantity);
                Pvec.push_back(price);
            }
        }
        ofstream termFile;
        termFile.open(filename, ofstream::trunc);
        for (int j = 0; j < Pvec.size(); ++j){
            termFile << ItemV.at(j) << " " << Devec.at(j) <<" " << quantvec.at(j) <<" " << Pvec.at(j) << "\n";
        }
        return itemchange;
    }
    
    
    void addItem(string filename, string Item, int quantity, float price, std::string dev){
        //still needs a bit of work like not allowing quantity to be higher than the stock
        // could be done in main as well
        //The paramaters should be passed in via main as well. No real searching necessary
        ofstream outfile;
        outfile.open(filename);

        outfile << Item  << " " << dev << "" << quantity  << " " << price << std::endl;
        outfile.close();
    }
    string getFilename(){
        return filename;
    }
};

#endif //GROUPPROJECT_CART_H

////All the variables below are used in our loops.
//        std::string option;
//        std::string option2;
//        ViewInventory(filename);
//        std::ifstream myfile;
//        std::ofstream outfile;
//        int counter = -1;
//        int check = -1;
//        std::string line;
//
//        //while telling us the item they wish to change we need to validate it
//        while(check == -1){
//            myfile.open(filename);
//            std::cout << "Name of the item you would like to change? ";
//            getline(std::cin, option);
//
//            std::string tempOpt = option;
//            for (int i = 0; i < tempOpt.size(); i++){
//                tempOpt[i] = toupper(tempOpt[i]);
//            }
//
//            while (getline(myfile, line)){
//                counter+=1;
//                //in case of incorrect capital letters
//                std::string tempLine = line;
//                for (unsigned int j = 0; j < tempLine.length(); ++j){
//                    tempLine[j] = toupper(tempLine[j]);
//                }
//                //compare all caps strings. If the item is in the file, the while loop will end
//                if (tempLine.find(tempOpt) != std::string::npos){
//                    check = 1;
//                    myfile.close();
//                }
//                else if (myfile.eof()){
//                    std::cout << "That's not an item in the inventory. Try again.\n\n";
//                    myfile.close();
//                    check = 1;
//                    counter = -1;
//                }
//            }
//        }
//        std::vector<std::string> lineStore;
//        std::string linefill;
//        myfile.open(filename);
//        if (myfile.is_open())
//        {
//            //read lines and push into vector
//            while (getline(myfile, linefill))
//            {
//                lineStore.push_back(linefill);
//            }
//        }
//        vector<std::pair<std::string, int>> invChange;
//
//        lineStore.erase(lineStore.begin() + counter);
//        std::ofstream newFile(filename, std::ofstream::trunc);
//        for (int i = 0; i < lineStore.size(); i++) {
//            newFile << lineStore[i] << std::endl;
//        }
//        newFile.close();
//        myfile.close();
//        return option; //returns the name of the deleted item to update other containers