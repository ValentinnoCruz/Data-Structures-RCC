/* 
 * File:   Player.cpp
 * Author: Val Cruz
 * Created on April 14, 2021
 * Purpose: Game---Monopoly: Empire
 */

#include "Player.h"

Player::Player() {
    name = " "; //Initialize name to empty
    password = " "; //Initialize password to empty
    money = 1000; //Initialize money to 800K
    position = 0; //Initialize position at starting point
    bonus = 0; //Initialize total bonus to 0
    jail = false; //Not in jail
    jTurn = 0; //Initialize turns in jail to 0
    bdName = NULL; //Have no Billboard Titles
    bdFront = NULL; //Have no Billboard Titles
    sum = 0;
}

Player::~Player() {
    if (bdName == NULL && bdFront == NULL) return;
    if (bdName != NULL) {
        do {
            Link *temp = bdName->LinkPtr;
            delete bdName;
            bdName = temp;
        } while (bdName != NULL);
    }
    if (bdFront != NULL) {
        do {
            Link *temp = bdFront->LinkPtr;
            delete bdFront;
            bdFront = temp;
        } while (bdFront != NULL);
    }
}

void Player::reset() {
    name = " "; //Initialize name to empty
    password = " "; //Initialize password to empty
    money = 1000; //Initialize money to 800K
    position = 0; //Initialize position at starting point
    bonus = 0; //Initialize total bonus to 0
    jail = false; //Not in jail
    jTurn = 0; //Initialize turns in jail to 0
    bdName = NULL; //Have no Billboard Titles
    bdFront = NULL; //Have no Billboard Titles
    sum = 0;
}

Link *Player::endLst(int n) {
    Link *lnk, *end;
    if (n == 1) {
        if (bdName == NULL) end = NULL;
        else {
            lnk = bdName;
            do {
                end = lnk; //Are we at the end yet?
                lnk = lnk->LinkPtr; //Traverse to the next link
            } while (lnk != NULL); //Finally found the end when NULL
        }
    } else if (n == 2) {
        if (bdFront == NULL) end = NULL;
        else {
            lnk = bdFront;
            do {
                end = lnk; //Are we at the end yet?
                lnk = lnk->LinkPtr; //Traverse to the next link
            } while (lnk != NULL); //Finally found the end when NULL
        }
    }
    return end;
}

bool Player::search(int s, int n) {
    if (s == 1) {
        if (bdName == NULL) return false;
        Link *lnk = bdName;
        while (lnk->data != n) {
            lnk = lnk->LinkPtr;
            if (lnk == NULL) return false;
        }
    } else if (s == 2) {
        if (bdFront == NULL) return false;
        Link *lnk = bdFront;
        while (lnk->data != n) {
            lnk = lnk->LinkPtr;
            if (lnk == NULL) return false;
        }
    }
    return true;
}

void Player::setName(string n) {
    name = n;
}

void Player::setPosition(int n) {
    position += n;
    if (position > 23) {
        position -= 24;
        setSum();
        money += sum;
        cout << name << " passed start point and collect " << sum << "K from bank." << endl;
    }
}

void Player::setJump(int n) {
    position = n;
}

void Player::setSum() {
    sum = 0;
    Link *lnk = bdFront;
    while (lnk != NULL) {
        sum += lnk->data;
        lnk = lnk->LinkPtr;
    }
}

void Player::inJail() {
    //    if (jail == true) jail = false;
    //    if (jail == false) jail = true;
    jail = true;
}

void Player::oJail() {
    jail = false;
    position = 7;
}

void Player::jailTurn() {
    if (jTurn >= 0 && jTurn <= 3) jTurn++;
    else return;
}

void Player::addBdName(int n) {
    Link *lnk = new Link;
    lnk->data = n;
    lnk->LinkPtr = NULL;
    if (bdName == NULL) {
        bdName = lnk;
    } else {
        Link *end = endLst(1);
        if (end != NULL) end->LinkPtr = lnk;
    }
}

void Player::addBdFront(int n) {
    Link *lnk = new Link;
    lnk->data = n;
    lnk->LinkPtr = NULL;
    if (bdFront == NULL) {
        bdFront = lnk;
    } else {
        Link *end = endLst(2);
        if (end != NULL) end->LinkPtr = lnk;
    }
}

void Player::pop(int n) {
    if (n == 1) {
        if (bdName == NULL) return;
        else if (bdName->LinkPtr == NULL)
            bdName = NULL;
        else {
            Link *lnk = bdName;
            Link *end = endLst(1);
            while (lnk->LinkPtr != end)
                lnk = lnk->LinkPtr;
            lnk->LinkPtr = NULL;
        }//End of else
    } else if (n == 2) {
        if (bdFront == NULL) return;
        else if (bdFront->LinkPtr == NULL)
            bdFront = NULL;
        else {
            Link *lnk = bdFront;
            Link *end = endLst(2);
            while (lnk->LinkPtr != end)
                lnk = lnk->LinkPtr;
            lnk->LinkPtr = NULL;
        }//End of else
    }
}

void Player::sptMoney(int m) {
    money -= m;
}

void Player::takMoney(int m) {
    money += m;
}

void Player::prntLst(int n) {
    if (n == 1) {
        if (bdName == NULL) {
            cout << " ";
            return;
        }
        Link *next = bdName;
        do {
            cout << next->data << " ";
            next = next->LinkPtr;
        } while (next != NULL);
    } else if (n == 2) {
        if (bdFront == NULL) {
            cout << " " << endl;
            return;
        }
        Link *next = bdFront;
        do {
            cout << next->data << " ";
            next = next->LinkPtr;
        } while (next != NULL);
    }
    cout << endl;
}