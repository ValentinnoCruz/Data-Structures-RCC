

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

#include "Link.h"

class Player {
private:
    string name; //Player's name
    int money; //Money in player's hand
    int position; //Current position on board
    int bonus; //Bonus player totally collected
    bool jail; //Condition in jail
    int jTurn; //Turns in jail;
    Link *bdName; //The front of Billboard Titles names
    Link *bdFront; //The front of Billboard Titles linked list
    int sum; //Billboard collecting value sum
public:
    Player(); //Constructor
    virtual ~Player(); //Destructor
    Link *endLst(int);
    bool search(int, int);
    void setName(string);
    void setPosition(int);
    void setJump(int);
    void setSum();
    void addBdName(int);
    void addBdFront(int);
    void sptMoney(int);
    void takMoney(int);
    void pop(int);
    void inJail();
    void oJail();
    void jailTurn();
    void prntLst(int);

    string getName() {
        return name;
    }

    int getMoney() {
        return money;
    }

    int getPostion() {
        return position;
    }

    bool getJail() {
        return jail;
    }

    int getJTurn() {
        return jTurn;
    }

    Link *getBdName() {
        return bdName;
    }

    Link *getBdFront() {
        return bdFront;
    }

    int getSum() {
        return sum;
    }
};

#endif /* PLAYER_H */
