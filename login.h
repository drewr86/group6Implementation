#include <iostream>
#include <fstream>
#include <vector>
#include "account.h"

using namespace std;

class LoginManager{
    private:
        int userid;
        string username, password;
    public:
        string userNameAttempt;
        string passwordAttempt;
        bool accessGranted;
        vector<Account> accounts;
        
    LoginManager(){
    }
    
    string login(){
        processFile(accounts);
        
        cout << "Please enter username. \nUsername:";
        cin >> userNameAttempt;
        
        bool found = false;
        bool deadEnd = false;
        int usernameIndex = 0;
        
        while (!found && !deadEnd){
            for(int i = 0; i < accounts.size(); i++){
                if (userNameAttempt == accounts[i].getusername()){
                    userid = accounts[i].getuserid();
                    username = accounts[i].getusername();
                    usernameIndex = i;
                    found = true;
                }
            }
            deadEnd = true;
        }
        
        if(found){
            cout << "Password:";
            cin >> passwordAttempt;
            if(passwordAttempt == accounts[usernameIndex].getpassword()){
                
                accessGranted = 1;
                cout << endl << "Welcome to your shopping cart " << username << endl << endl;
                return username;
            }
        }
        
        return 0;
    }
    
    void processFile(vector<Account> &accounts){
        ifstream infile;
        string line;
    
        infile.open("accounts.txt");
    
        if(infile.is_open()){
        }
        else{
            cout << "Please use accounts.txt file provided." << endl;
            exit(EXIT_FAILURE);
        }
    
        while(getline(infile, line)){
            // first line --> userid
            // second line --> username
            // third  line --> password
            
            if(line != ""){
                int userid;
                string username, password;
                
                userid = stoi(line);
                
                getline(infile, username);
                
                getline(infile, password);
                
                Account temp(userid, username, password);
                
                accounts.push_back(temp);
            }
        }
        return;
    }
};
