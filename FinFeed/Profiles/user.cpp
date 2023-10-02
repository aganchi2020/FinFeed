#include "user.h"

int User::ID = 0;

User::User(string userName, string firstName, string lastName, string email, long phoneNum, int birthMonth, int birthDay, int birthYear, string accnType){
    this->username    = userName;
    this->firstName   = firstName;
    this->lastName    = lastName;
    this->email       = email;
    this->phoneNum    = phoneNum;
    this->birthMonth  = birthMonth;
    this->birthDay    = birthDay;
    this->birthYear   = birthYear;
    this->accnType    = accnType;
    id                = ID;

    age = setAge();
    setAccnType();

    ID++;
}

User::~User(){
    cout << "account deleted!" << endl;
}

int User::setAge(){
    vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    time_t now = time(0);
    string date_time = ctime(&now);

    string m = date_time.substr(4,3);
    int month = 0;
    for(int i = 0; i < 12; i++){
        if(months[i] == m){
            month = i + 1;
            break;
        }
    }

    string d = date_time.substr(8,2);
    int day = stoi(d);

    string y = date_time.substr(20,4);
    int year = stoi(y);


    if(birthMonth > month){                             //if birthMonth hasn't passed yet this year
        age = year - birthYear - 1;
    } else if (birthMonth < month){                     //if birthMonth already passed this year
        age = year - birthYear;
    } else if(birthMonth == month){                     //if currently in birthMonth
        if(birthDay > day){                             //if birthDay hasn't passed yet
            age = year - birthYear - 1;
        } else if(birthDay < day || birthDay == day){   //if on birthDay or birthDay already passed
            age = year - birthYear;
        }
    }

    return age;
}

void User::setAccnType(){
    if(accnType == "regular"){
        if(age >= 18){
            accnType = "regularAdult";      //create adult (18+) account
        } else{
            accnType = "regularKid";        //create child account
        }
    }
}

void User::deleteAccount(User* u){
    if(accnType == "mod" || accnType == "owner"){
        delete u;
    }
}

void User::addStrike(User *u){
    if(accnType == "mod" || accnType == "owner"){
        u->strikes ++;
    }
    if(u->strikes == 3){
        deleteAccount(u);
    }
}

void User::makeExpert(User* u){
    if(accnType == "mod" || accnType == "owner"){
        u->accnType = "expert";
    }
}

void User::makeMod(User *u){
    if(accnType == "owner"){
        u->accnType = "mod";
    }
}

void User::addFriend(User *u){
    friends.push_back(u);
}

void User::findFriend(User* u){

}

string User::getUserName(){
    return username;
}

string User::getFirstName(){
    return firstName;
}

string User::getLastName(){
    return lastName;
}

string User::getEmail(){
    return email;
}

string User::getAccnType(){
    return accnType;
}

long User::getPhoneNum(){
    return phoneNum;
}

int User::getBirthMonth(){
    return birthMonth;
}

int User::getBirthDay(){
    return birthDay;
}

int User::getBirthYear(){
    return birthYear;
}

int User::getID(){
    return id;
}

int User::getStrikes(){
    return strikes;
}



