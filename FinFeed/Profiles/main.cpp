#include <iostream>
#include <ctime>
#include "user.h"

using namespace std;

int main(){
    User * kid = new User("RandomUser", "Kid", "idk", "ganchia@lafayette.edu", 8624003944, 4, 13, 2007, "regular");
    User * owner = new User("HectorJuan", "Arman", "Ganchi", "ganchia@lafayette.edu", 8624003944, 4, 13, 2002, "owner");

    owner->addStrike(kid);
    owner->addStrike(kid);

    cout << kid->getStrikes() << endl;

    owner->makeMod(kid);

    cout << kid->getAccnType() << endl;

    owner->addStrike(kid);



    return 0;
}
