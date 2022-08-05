#include "account.h"

Account::Account()
{
    userid = 0;
    username = "";
    password = "";
}

Account::Account(int userid, string username, string password)
{
    this->userid = userid;
    this->username = username;
    this->password = password;
}

// getters
int Account::getuserid()
{
    return userid;
}

string Account::getusername()
{
    return username;
}

string Account::getpassword()
{
    return password;
}

// setters
void Account::setuserid(int userid)
{
    this->userid = userid;
}

void Account::setusername(string username)
{
    this->username = username;
}

void Account::setpassword(string password)
{
    this->password = password;
}