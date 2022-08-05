#include "Cart.h"

/*
I tried to clean it up. If you can help, try to figure out how to manage the edit cart function file swapping
when the quantity is to be replaced.
*/

Cart::Cart()
{
    user = "";
    filename = "carts.txt";
}

Cart::Cart(std::string user, std::string filename = "carts.txt"){
    this->user = user;
    this->filename = filename;
    std::ifstream myfile;
    std::string line;
    myfile.open(filename);
    bool checkHistory = false;
    while(getline(myfile, line)){
        if (line.find(user) != std::string::npos){
            bool checkHistory = true;
        }
    }
    myfile.close();
    if (checkHistory == true){
        std::cout << "Welcome back " << user;
        ViewCart(filename);
    }
}





void Cart::ViewCart(std::string filename){
    std::string line;
    std::ifstream myfile;
    myfile.open(filename);
    std::cout << "Here are the contents of your cart:" <<std::endl;
    while (myfile.good()){
        if (myfile.eof()){
            break;
        }
        if (!myfile.eof() && !myfile){
            std::cerr << "You Need to add items first!" <<std::endl;
            throw;
        }
        getline(myfile, line);
        std::cout << line << std::endl;
    }
    std::cout << std::endl;
    myfile.close();
}


void Cart::editCart(std::string filename){
    //All the variables below are used in our loops.
    std::string option;
    std::string option2;
    ViewCart(filename);
    std::ifstream myfile;
    std::ofstream outfile;
    int counter = -1;
    int check = -1;
    std::string line;

    //while telling us the item they wish to change we need to validate it
    while(check == -1){
        myfile.open(filename);
        std::cout << "Name of the item you would like to change? ";
        getline(std::cin, option);

        std::string tempOpt = option;
        for (int i = 0; i < tempOpt.size(); i++){
            tempOpt[i] = toupper(tempOpt[i]);
        }

        while (getline(myfile, line)){
            counter+=1;
            //in case of incorrect capital letters
            std::string tempLine = line;
            for (unsigned int j = 0; j < tempLine.length(); ++j){
                tempLine[j] = toupper(tempLine[j]);
            }
            //compare all caps strings. If the item is in the file, the while loop will end
            if (tempLine.find(tempOpt) != std::string::npos){
                check = 1;
                myfile.close();
            }
            else if (myfile.eof()){
                std::cout << "That's not an item in your cart. Try again.\n\n";
                myfile.close();
                check = 1;
                counter = -1;
            }
        }
    }
    std::vector<std::string> lineStore;
    std::string linefill;
    myfile.open(filename);
    if (myfile.is_open())
    {
        //read lines and push into vector
        while (getline(myfile, linefill))
        {
            lineStore.push_back(linefill);
        }
    }

    lineStore.erase(lineStore.begin() + counter);
    std::ofstream newFile(filename, std::ofstream::trunc);
    for (int i = 0; i < lineStore.size(); i++) {
        newFile << lineStore[i] << std::endl;
    }
    newFile.close();
    myfile.close();
}



void Cart::addItem(std::string filename, std::string Item, int quantity, float price, std::string user){
    //The paramaters should be passed in via main as well. No real searching necessary
    std::ofstream outfile;
    outfile.open(filename);
    float quantityStorer = quantity;
//    std::pair<float, float> temp = std::make_pair(price, quantityStorer);
//    priceQuant.push_back(temp);
    float Total = quantity * price * 1.07; //if u want tax
    outfile << user << " " << Item  << " " << quantity  << " " << Total << std::endl;
    outfile.close();
}


std::vector<std::pair<std::string, float>> Cart::CheckOut(std::string filename, std::vector<std::pair<std::string, float>>& itemchange){
    ViewCart(filename);
    float total = 0.0;
    std::string user;
    std::string itm;
    int quant;
    float price;
    std::ifstream myfile;
    myfile.open(filename);
    //need to grab the final price just for show
    while (std::cin >> user >> itm >> quant >> price){
        total += price;
        int i = itemchange.size() - 1;
        itemchange[i].first = itm;
        itemchange[i].second = quant;
    }
    myfile.close();
    std::cout << "Your total is: " << total << std::endl;

    //implement deletion of file/destuction of the cart
    std::ofstream outfile;
    outfile.open(filename, std::ofstream::out | std::ofstream::trunc);
    outfile.close();
    return itemchange;
}


/*
View all items in a category
View all items in the user's shopping cart
Add item from a category to their shopping cart
Remove an item from their shopping cart
Checkout the items currently in their cart
Removes items from the user's shopping cart
Edits stock information to lower the stock accordingly
*/

//int check2 = 0;
//while (check2 == 0){
//std::cout << "Would you like to 1.) Delete the item from your cart? or 2.) Edit the quantity? ";
//getline(std::cin, option2);
//if (option2 == "1"){
//
//check2 = -1;
//}
// If they want to change the quantity
//else if (option2 == "2") {
//int quantChange;
//bool truthcheck = false;
//
//while (truthcheck == false){
//std::cout << "What is the quantity you desire? ";
//std::cin >> quantChange;
//if (!std::cin.fail()){
//truthcheck = true;
//
//}
//else{
//std::cout <<"Not a valid quantity. Try again." << std::endl;
//
//std::cin.clear();
//
//std::cin.ignore(50, '\n');
//}
//
//}

//float priceHolder;
//float newQuant = quantChange;
//std::cin.clear();
//priceHolder = priceQuant[counter].first;
//priceQuant[counter].second = newQuant;
//float total = newQuant * priceHolder;
//std::string dummyline;
//int IDhold;
//int Quanthold;
//std::string itemHold;
//float Oldtotal;
//myfile.open(filename);
//outfile.open("blankfile.txt");
//
//while (myfile >> IDhold >> itemHold >> Quanthold >> Oldtotal){
//parse until we find the line with the specified item from before
//if (itemHold == option){
//Quanthold = quantChange;
//Oldtotal = total;
//}
//outfile << IDhold << " " << itemHold << " " << Quanthold << " " << Oldtotal <<"\n";
//}
//replace files. Close back up. Change check2 to different value;
//myfile.close();
//outfile.close();
//}
//
//else{
//std::cout << "That's not one of the options. Please try again.";
//continue;
//}


