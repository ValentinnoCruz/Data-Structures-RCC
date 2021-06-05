
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <map>
using namespace std;

#include "Player.h"

class Game {
private:
    int turn; //Game turns
    int cond; //Billboard condition
    int start; //Who starts first
    int elcNum; //Number of electric company
    bool over; //Judge for game over
    bool win; //If player wins
    int *chance; //8 Chance Card
    Player p1; //First player
    Player p2; //Second player
    char dice1; //First dice: the special one
    char dice2; //Second dice: the normal one
    map<int, int>sell; //Brand selling price
    map<int, int>coll; //Brand collecting value
    void initial();
public:
    Game();
    virtual ~Game();
    int sale(int);
    void shuffle(int *);
    string stopAt(int);
    string defineC(int);
    void chanCrd(int);
    void swap();
    void move(int, int);
    void jump(int, int);
    bool compare();
    void tripAI();
    void jail(int);
    bool jailJudge(int);
    void outJail(int, int);
    void buyBrnd(int, int);
    void buyElec(int);
    void payRent(int, int);
    void remove(int);
    void title();
    void output();
    void setOver();
    void setName(string, string);
    void setStart();
    void setDices();
    int getPos(int);
    int getMoney(int);
    string getName(int);
    void rules();

    char getDice1() {
        return dice1;
    }

    char getDice2() {
        return dice2;
    }

    int getStart() {
        return start;
    }

    int getTurn() {
        return ++turn;
    }

    int *getChance() {
        return chance;
    }

    int getSell(int p) {
        return sell[p];
    }

    int getColl(int p) {
        return coll[p];
    }
    int getJail(int);

    bool getOver() {
        return over;
    }

    bool getWin() {
        return win;
    }

    int getElc() {
        return elcNum;
    }
};

#endif /* GAME_H */
