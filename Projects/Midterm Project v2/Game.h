/* 
 * File:   Player.h
 * Author: Val Cruz
 * Created on April 14, 2021
 * Purpose: Game---Monopoly: Empire
 */

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <vector>
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
    map<string, int>value; //Unit value for each brand
    map<string, int>::iterator iter; //Iterator for unit value
    vector<int>score; //Record player's Billboard
    bool winLose; //Record if player win
    void initial();
public:
    Game();
    virtual ~Game();
    void reset();
    void record();
    void valueSort();
    void quickSort(int [], int, int);
    int partition(int [], int, int);
    void qSwap(int &, int &);
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
    void pntScore();
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

    int getScore(int n) {
        return score[n];
    }

    int getScoreSize() {
        return score.size();
    }

    int getWinLose() {
        return winLose;
    }
};

#endif /* GAME_H */