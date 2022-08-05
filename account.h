#include <string>

using std::string;

#ifndef ACCOUNTS_H
#define ACCOUNTS_H


class Account
{
    private:
        int userid;
        string username, password;

    public:
        Account();
        Account(int userid, string username, string password);

        // getters
        int getuserid();
        string getusername();
        string getpassword();

        // setters
        void setuserid(int userid);
        void setusername(string username);
        void setpassword(string password);
};

#endif // ACCOUNTS_H