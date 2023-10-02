#ifndef USER_H
#define USER_H

#include <string>
#include <ctime>
#include <vector>
#include <iostream>

using namespace std;

class User{
public:
    static int ID;

    User(string userName, string firstName, string lastName, string email, long phoneNum, int birthMonth, int birthDay, int birthYear, string accnType);

    void addFriend(User* u);
    void findFriend(User* u);

    //General Set methods
    int setAge();
    void setAccnType();

    //General Get methods
    string getUserName();
    string getFirstName();
    string getLastName();
    string getEmail();
    long getPhoneNum();
    int getBirthMonth();
    int getBirthDay();
    int getBirthYear();
    string getAccnType();
    int getID();
    int getStrikes();

    //Mod Methods
    void deleteAccount(User* u);
    void addStrike(User* u);
    void makeExpert(User* u);

    //Owner Methods
    void makeMod(User* u);


    ~User();

private:
    string username;
    string firstName;
    string lastName;
    string email;
    string accnType;
    long phoneNum;
    int birthMonth;
    int birthDay;
    int birthYear;
    int age;

    int id;
    int strikes;  //strike system for community violations?

    vector<User*> friends;
};



#endif // USER_H
