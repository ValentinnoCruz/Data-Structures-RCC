
#include "Game.h"

Game::Game() {
    turn = 0; //Initialize game turns to 1
    cond = 0; //Initialize all Billboard Titles are not sold
    start = 0; //Initialize start to 0;
    elcNum = 4; //Four electric company in total
    over = false; //Game not over
    win = false; //Player not win
    chance = new int[8];
    for (int i = 0; i < 8; i++)
        chance[i] = i;
    initial();
}

void Game::initial() {
    //Selling price
    sell[2] = 50;
    sell[4] = 100;
    sell[6] = 100;
    sell[8] = 150;
    sell[9] = 150;
    sell[10] = 200;
    sell[11] = 200;
    sell[13] = 250;
    sell[15] = 250;
    sell[16] = 300;
    sell[18] = 300;
    sell[20] = 350;
    sell[21] = 350;
    sell[23] = 400;
    //Collecting value
    coll[2] = 50;
    coll[4] = 50;
    coll[6] = 50;
    coll[8] = 100;
    coll[9] = 50;
    coll[10] = 100;
    coll[11] = 100;
    coll[13] = 150;
    coll[15] = 150;
    coll[16] = 150;
    coll[18] = 150;
    coll[20] = 200;
    coll[21] = 200;
    coll[23] = 200;
}

int Game::sale(int n) {
    if (p1.search(1, n) == true) cond = 1;
    else if (p2.search(1, n) == true) cond = 2;
    else cond = 0;
    return cond;
}

Game::~Game() {
    delete [] chance;
}

void Game::setName(string n1, string n2) {
    p1.setName(n1);
    p2.setName(n2);
}

void Game::setStart() {
    start = rand() % 2;
    //    start = 0;
}

void Game::setDices() {
    dice1 = rand() % 6 + 49;
    if (dice1 == 49)
        dice1 = 's';
    dice2 = rand() % 6 + 49;
}

void Game::setOver() {
    if (p1.getMoney() <= 0) {
        cout << "You run out of money!" << endl;
        over = true;
        win = false;
    }
    if (p2.getMoney() <= 0) {
        cout << "Computer runs out of money!" << endl;
        over = true;
        win = true;
    }
    p1.setSum();
    if (p1.getSum() >= 800) {
        cout << "Your billboard reach the top!" << endl;
        over = true;
        win = true;
    }
    p2.setSum();
    if (p2.getSum() >= 800) {
        cout << "Computer's billboard reach the top!" << endl;
        over = true;
        win = false;
    }
}

string Game::stopAt(int n) {
    string pos;
    if (p1.getPostion() == n)
        pos = "[1] ";
    else pos = "    ";
    if (p2.getPostion() == n)
        pos += " [2]";
    else pos += "    ";
    return pos;
}

void Game::shuffle(int *card) {
    int temp;
    int r; //Hold a random number
    for (int i = 0; i < 8; i++) {
        r = rand() % 8;
        temp = card[r];
        card[r] = card[i];
        card[i] = temp;
    }
    //    //For test
    //    for (int i = 0; i < 8; i++)
    //        cout << card[i] << " ";
}

void Game::swap() {
    if (p1.getBdName() == NULL || p2.getBdName() == NULL || p1.getBdFront() == NULL || p2.getBdFront() == NULL) return;
    Link *end1 = p1.endLst(1);
    Link *end2 = p2.endLst(1);
    Link *temp;
    temp->data = end1->data;
    end1->data = end2->data;
    end2->data = temp->data;

    Link *end3 = p1.endLst(2);
    Link *end4 = p2.endLst(2);
    temp->data = end3->data;
    end3->data = end4->data;
    end4->data = temp->data;
}

void Game::move(int p, int n) {
    if (p == 1)
        p1.setPosition(n);
    else if (p == 2)
        p2.setPosition(n);
    else return;
}

void Game::jump(int p, int pos) {
    if (p == 1) {
        p1.setJump(pos);
        p1.sptMoney(100);
    } else if (p == 2) {
        p2.setJump(pos);
        p2.sptMoney(100);
    } else return;
}

bool Game::compare() {
    if (p1.getBdFront() == NULL || p2.getBdFront() == NULL) return false;
    Link *end1 = p1.endLst(2);
    Link *end2 = p2.endLst(2);
    if (end1->data > end2->data) return true;
    else return false;
}

void Game::tripAI() {
    int pos;
    if (p2.getMoney() > 500) {
        if (rand() % 5 < 3) {
            do {
                pos = rand() % 24;
            } while (p1.search(1, pos) || pos == 12 || pos == 19 || pos == 22);
            cout << "\nComputer jumps to position #" << pos << endl;
            jump(2, pos);
        }
    }
}

void Game::jail(int p) {
    if (p == 1) {
        if (p1.getJTurn() == 0 && p1.getJail() == false) {
            p1.inJail();
            p1.jailTurn();
            //            p1.setJump(7);
        }
    } else if (p == 2) {
        if (p2.getJTurn() == 0 && p2.getJail() == false) {
            p2.inJail();
            p2.jailTurn();
            //            p2.setJump(7);
        }
    } else return;
}

bool Game::jailJudge(int n) {
    if (n == 1) {
        if (p1.getMoney() <= 100) return false;
        else return true;
    } else return true;
}

void Game::outJail(int p, int n) {
    if (p == 1) {
        if (n == 1) {
            cout << "You spent 100K to get out of jail." << endl;
            p1.sptMoney(100);
            p1.oJail();
        } else {
            char roll1, roll2;
            setDices();
            roll1 = getDice1();
            roll2 = getDice2();
            cout << "You choose to roll dices." << endl;
            cout << "Your result is: " << roll1 << " " << roll2 << endl << endl;
            if (roll1 == roll2) {
                cout << "Congratulation! You rolled double." << endl;
                p1.oJail();
            } else {
                cout << "Sorry, you did not get double in this turn." << endl;
                if (p1.getJTurn() == 3) {
                    cout << "You paid 50K to get out of jail." << endl;
                    p1.sptMoney(50);
                    p1.oJail();
                } else p1.jailTurn();
            }
        }
    } else if (p == 2) {
        if (p2.getMoney() > 400) {
            cout << "Computer spent 100K to get out of jail" << endl;
            p2.sptMoney(100);
            p2.oJail();
        } else {
            char roll1, roll2;
            setDices();
            roll1 = getDice1();
            roll2 = getDice2();
            cout << "Computer choose to roll dices." << endl;
            cout << "Computer's result is: " << roll1 << " " << roll2 << endl << endl;
            if (roll1 == roll2) {
                cout << "Computer rolled double and get out of jail." << endl;
                p2.oJail();
            } else {
                cout << "Computer did not get double." << endl;
                if (p2.getJTurn() == 3) {
                    cout << "computer paid 50K to get out of jail." << endl;
                    p2.sptMoney(50);
                    p2.oJail();
                } else p2.jailTurn();
            }
        }
    }
}

void Game::buyBrnd(int p, int pos) {
    if (p == 1) {
        p1.sptMoney(sell[pos]);
        p1.addBdName(pos);
        p1.addBdFront(coll[pos]);
    } else if (p == 2) {
        p2.sptMoney(sell[pos]);
        p2.addBdName(pos);
        p2.addBdFront(coll[pos]);
    } else return;
}

void Game::buyElec(int p) {
    if (p == 1) {
        p1.sptMoney(sell[9]);
        p1.addBdName(9);
        p1.addBdFront(coll[9]);
        elcNum--;
    } else if (p == 2) {
        p2.sptMoney(sell[9]);
        p2.addBdName(9);
        p2.addBdFront(coll[9]);
        elcNum--;
    } else return;
}

void Game::payRent(int p, int pos) {
    if (p == 1) {
        p1.sptMoney(sell[pos]);
        p2.takMoney(sell[pos]);
    } else if (p == 2) {
        p2.sptMoney(sell[pos]);
        p1.takMoney(sell[pos]);
    } else return;
}

void Game::remove(int p) {
    if (p == 1) {
        p1.pop(1);
        p1.pop(2);
    } else if (p == 2) {
        p2.pop(1);
        p2.pop(2);
    } else return;
}

int Game::getJail(int p) {
    if (p == 1) return p1.getJail();
    else if (p == 2) return p2.getJail();
    else return false;
}

void Game::title() {
    cout << "                                            [][][][][]                                            " << endl;
    cout << "                                        [][][]      [][][]                                        " << endl;
    cout << "[][][][][][][][][][][][][][][][][][][][][]              [][][][][][][][][][][][][][][][][][][][][]" << endl;
    cout << "[]                                                                                              []" << endl;
    cout << "[]  []          []    [][][]    []      []    [][][]    [][][]      [][][]    []    []      []  []" << endl;
    cout << "[]  [][]      [][]  []      []  [][]    []  []      []  []    []  []      []  []    []      []  []" << endl;
    cout << "[]  []  []  []  []  []      []  []  []  []  []      []  []    []  []      []  []      []  []    []" << endl;
    cout << "[]  []    []    []  []      []  []    [][]  []      []  [][][]    []      []  []        []      []" << endl;
    cout << "[]  []          []    [][][]    []      []    [][][]    []          [][][]    [][][]  []        []" << endl;
    cout << "[]                                                                                              []" << endl;
    cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << endl;
    cout << "\nPress enter to continue." << endl;
}

void Game::output() {

    cout << " _______________________________________________________________________________________________________  " << endl;
    cout << "|    FREE    | GUITARHERO |   CHANCE   |   YAHOO!   |    Ford    |   CHANCE   |    ebay    |   GO TO    | " << "Player's Info:" << endl;
    cout << "|   PARKING  |    LIVE    |    CARD    |            |            |    CARD    |            |   JAIL!    | " << "------------------------" << endl;
    cout << "|            | 250K (150) |            | 250K (150) | 300K (150) |            | 300K (150) |            | " << p1.getName() << endl;
    cout << "|            |    (" << sale(13) << ")     |            |    (" << sale(15) << ")     |    (" << sale(16) << ")     |            |    (" << sale(18) << ")     |            | " << "Money: " << p1.getMoney() << "K" << endl;
    cout << "|  " << stopAt(12) << "  |  " << stopAt(13) << "  |  " << stopAt(14) << "  |  " << stopAt(15) << "  |  " << stopAt(16) << "  |  " << stopAt(17) << "  |  " << stopAt(18) << "  |            | " << "Brand Value: " << endl;
    cout << "|_____12_____|_____13_____|_____14_____|_____15_____|_____16_____|_____17_____|_____18_____|_____19_____| ";
    p1.prntLst(2);
    cout << "|   Candy    |                                                                             | UNIVERSAL  | " << "------------------------" << endl;
    cout << "|   Crush    |                                                                             |            | " << p2.getName() << endl;
    cout << "| 200K (100) |                                                                             | 350K (200) | " << "Money: " << p2.getMoney() << "K" << endl;
    cout << "|    (" << sale(11) << ")     |                                                                             |    (" << sale(20) << ")     | " << "Brand Value: " << endl;
    cout << "|  " << stopAt(11) << "  |                                                                             |  " << stopAt(20) << "  | ";
    p2.prntLst(2);
    cout << "|_____11_____|                                                                             |_____20_____|" << endl;
    cout << "|    LEVIS   |                                                                             |    XBOX    |" << endl;
    cout << "|            |                                                                             |            |" << endl;
    cout << "| 200K (100) |                                                                             | 350K (200) |" << endl;
    cout << "|    (" << sale(10) << ")     |                                                                             |    (" << sale(21) << ")     |" << endl;
    cout << "|  " << stopAt(10) << "  |                                                                             |  " << stopAt(21) << "  |" << endl;
    cout << "|_____10_____|                                                                             |_____21_____|" << endl;
    cout << "|  ELECTRIC  |                                                                             |   TOWER    |" << endl;
    cout << "|  COMPANY   |                                                                             |    TAX     |" << endl;
    cout << "| 150K(50," << elcNum << ") |                                                                             |            |" << endl;
    cout << "|            |                                                                             |            |" << endl;
    cout << "|  " << stopAt(9) << "  |                                                                             |  " << stopAt(22) << "  |" << endl;
    cout << "|_____09_____|                                                                             |_____22_____|" << endl;
    cout << "|    PUMA    |                                                                             |   skype    |" << endl;
    cout << "|            |                                                                             |            |" << endl;
    cout << "| 150K (100) |                                                                             | 400K (200) |" << endl;
    cout << "|    (" << sale(8) << ")     |                                                                             |    (" << sale(23) << ")     |" << endl;
    cout << "|  " << stopAt(8) << "  |                                                                             |  " << stopAt(23) << "  |" << endl;
    cout << "|_____08_____|_____________________________________________________________________________|_____23_____|" << endl;
    cout << "|  IN JAIL!  |  POLAROID  |   CHANCE   |    RAZOR   |   CHANCE   |TRANSFORMERS|   RIVAL    |    START   |" << endl;
    cout << "|__" << stopAt(19) << "__|            |    CARD    |            |    CARD    |            |   TOWER    |            |" << endl;
    cout << "|  PASS BY   | 100K (50)  |            | 100K (50)  |            |  50K (50)  |    TAX     |     GO!    |" << endl;
    cout << "|            |    (" << sale(6) << ")     |            |    (" << sale(4) << ")     |            |    (" << sale(2) << ")     |            |            |" << endl;
    cout << "|  " << stopAt(7) << "  |  " << stopAt(6) << "  |  " << stopAt(5) << "  |  " << stopAt(4) << "  |  " << stopAt(3) << "  |  " << stopAt(2) << "  |  " << stopAt(1) << "  |  " << stopAt(0) << "  |" << endl;
    cout << "|_____07_____|_____06_____|_____05_____|______04____|______03____|_____02_____|_____01_____|_____00_____|" << endl;

}

string Game::defineC(int n) {
    string defi;
    switch (n) {
        case 0:
            defi = "Speed ahead!\nMove forward to 5 space.";
            break;
        case 1:
            defi = "Casino night!\nBoth you and your opponent roll.\nHighest-roller collects 200K from the bank.";
            break;
        case 2:
            defi = "Profits soar!\nAdvance to GO to collect your tower value.";
            break;
        case 3:
            defi = "Launch your website!\nSales skyrocket!\nCollect 300K from the bank.";
            break;
        case 4:
            defi = "Solar power bonus!\nTake a free Electric Company billboard.\nAdd it to your tower.\nIf none are available, do nothing.";
            break;
        case 5:
            defi = "Insider trading fine!\nPay the Bank 200K.";
            break;
        case 6:
            defi = "Tallest tower bonus!\nCheck what the highest tower is currently worth.\nCollect that amount from the bank.";

            break;
        default:
            defi = "Go To Jail!\nDo not collect cash for passing GO.";
    }
    return defi;
}

void Game::chanCrd(int p) {
    int n = rand() % 8;
    cout << "You pick Chance Card #" << n << endl << endl;
    cout << defineC(n) << endl << endl;
    switch (n) {
        case 0:
            if (p == 1) {
                cout << "You move forward 5 steps." << endl;
                p1.setPosition(5);
            } else {
                cout << "Computer moves forward 5 steps." << endl;
                p2.setPosition(5);
            }
            break;
        case 1:
            cout << "Both you and Computer roll." << endl << endl;
            char roll1, roll2;
            setDices();
            roll1 = getDice2();
            setDices();
            roll2 = getDice2();
            cout << "Your result is: " << roll1 << endl;
            cout << "Computer's result is: " << roll2 << endl << endl;
            if (roll1 > roll2) {
                cout << "You got higher number; Bank gives you 200K in reward." << endl;
                p1.takMoney(200);
            } else if (roll1 < roll2) {
                cout << "Computer got higher number; Computer collect 200K from bank." << endl;
                p2.takMoney(200);
            } else {
                cout << "Both you and Computer get same number; both of you can collect 200K." << endl;
                p1.takMoney(200);
                p2.takMoney(200);
            }
            break;
        case 2:
            if (p == 1) {
                p1.setSum();
                cout << "You collect " << p1.getSum() << "K from Bank." << endl;
                p1.takMoney(p1.getSum());
            } else {
                p2.setSum();
                cout << "Computer collects " << p2.getSum() << "K from Bank." << endl;
                p2.takMoney(p2.getSum());
            }
            break;
        case 3:
            if (p == 1) {
                cout << "You collect 300K from Bank." << endl;
                p1.takMoney(300);
            } else {
                cout << "Computer collects 300K from Bank." << endl;
                p2.takMoney(300);
            }
            break;
        case 4:
            if (elcNum > 0) {
                if (p == 1) {
                    cout << "You collect a free Electric Company billboard." << endl;
                    p1.addBdName(9);
                    p1.addBdFront(50);
                } else {
                    cout << "Computer collects a free Electric Company billboard." << endl;
                    p2.addBdName(9);
                    p2.addBdFront(50);
                }
                elcNum--;
            } else {
                cout << "Sorry,there are no Electric Company billboards left." << endl;
            }
            break;
        case 5:
            if (p == 1) {
                cout << "You pay Bank 200K." << endl;
                p1.sptMoney(200);
            } else {
                cout << "Computer pays Bank 200K." << endl;
                p2.sptMoney(200);
            }
            break;
        case 6:
            int amount;
            p1.setSum();
            p2.setSum();
            if (p1.getSum() >= p2.getSum()) {
                amount = p1.getSum();
                cout << "You have a higher tower of " << amount << "K." << endl;
            } else {
                amount = p2.getSum();
                cout << "Computer has a higher tower of " << amount << "K." << endl;
            }
            if (p == 1) {
                cout << "You collect " << amount << "K from Bank." << endl;
                p1.takMoney(amount);
            } else {
                cout << "Computer collects " << amount << "K from Bank." << endl;
                p2.takMoney(amount);
            }
            break;
        default:
            if (p == 1) {
                cout << "You are sending to jail!" << endl;
                jail(1);
                p1.setJump(19);
            } else {
                cout << "Computer is sending to jail!" << endl;
                jail(2);
                p2.setJump(19);
            }
    }
}

int Game::getPos(int p) {
    if (p == 1) {
        return p1.getPostion();
    } else {
        return p2.getPostion();
    }
}

int Game::getMoney(int p) {
    if (p == 1) {
        return p1.getMoney();
    } else {
        return p2.getMoney();
    }
}

string Game::getName(int p) {
    if (p == 1) {
        return p1.getName();
    } else {
        return p2.getName();
    }
}

void Game::rules() {
    cout << "****************** Monopoly: Empire Rules ********************************" << endl;
    cout << "I. Basic rules" << endl;
    cout << "   A. Each player has 1000K at beginning and start at position #0." << endl;
    cout << "   B. In each turn, player roll 2 dices, and move corresponding steps." << endl;
    cout << "   C. When stop at a position, follow the instruction of that position." << endl;
    cout << "   D. [1] represent player, [2] represent computer." << endl;
    cout << endl;
    cout << "II. Game Board" << endl;
    cout << "   A. Total 24 positions (0~24) of 7 types." << endl;
    cout << "   B. Start" << endl;
    cout << "       1. Every player start from here." << endl;
    cout << "       2. When pass start point, collect as much money as your total collecting value." << endl;
    cout << "   C. Billboard" << endl;
    cout << "       1. Containing name, price, collecting value, and condition(0,1 or 2)." << endl;
    cout << "       2. The first two lines are the name of the brand." << endl;
    cout << "       3. The third line is price (collecting value), eg.100K (50)." << endl;
    cout << "           a. Price ≠ collecting value." << endl;
    cout << "           b. Price is how much cost you to buy the brand." << endl;
    cout << "           c. Collecting value is used for win the game." << endl;
    cout << "       4. The fourth line is (condition), eg. (1)." << endl;
    cout << "            (0 = no owner; 1 = player own; 2 = computer own)" << endl;
    cout << "       5. The fifth line shows player's position, eg.[1] [2]." << endl;
    cout << "       6. The bottom line has the position # of that box." << endl;
    cout << "       7. Exception: Electric Company Billboard. (See IV. Billboard-E)" << endl;
    cout << "   D. Chance Card" << endl;
    cout << "       1. Randomly pick a chance card when stop at here." << endl;
    cout << "       2. Total 8 kinds of chance cards." << endl;
    cout << "       3. Chance card may not be good for player who pick it." << endl;
    cout << "   E. Jail" << endl;
    cout << "       1. To get out of jail, there are two choice." << endl;
    cout << "           a. During next turn, pay 100K and get out at once." << endl;
    cout << "           b. Roll a double up to 3 turns, if not, pay 50K and get out at 3rd turn." << endl;
    cout << "       2. Position #19 is go to jail, player will be move to jail on Position #7." << endl;
    cout << "       3. Simply stop at position #7 is pass by, is not in jail." << endl;
    cout << "   F. Take a trip" << endl;
    cout << "       1. You can spend 100K to move to anywhere on board, or simply do nothing." << endl;
    cout << "       2. If you move to a new position, you have to follow the instruction on that position." << endl;
    cout << "   E. Tower Tax" << endl;
    cout << "       1. Tower Tax: return your topmost billboard to board." << endl;
    cout << "       2. Rival Tower Tax: return your opponent's topmost billboard to board." << endl;
    cout << endl;
    cout << "III. Dices" << endl;
    cout << "   A. One normal dice, one special dice with a 'swap' face." << endl;
    cout << "   B. When 'swap' face is up, you have a chance of sneaky swap." << endl;
    cout << "       (sneaky swap: swap your topmost billboard with your opponent's)" << endl;
    cout << "   C. When you roll a double, you can have another turn until you don't have a double." << endl;
    cout << "       (double: two dices have same number)" << endl;
    cout << endl;
    cout << "IV. Billboard" << endl;
    cout << "   A. 14 billboards total; different price with different collecting value; choose smartly!" << endl;
    cout << "   B. You can buy billboards when you stop at the corresponding position if the condition is no owner." << endl;
    cout << "   C. You have to pay rent fee if you stop at a position whose billboard is owner by your opponents." << endl;
    cout << "   D. Nothing will happen if you stop at the position that is owned by yourself." << endl;
    cout << "   E. One exception is Electric Company Billboard at position #9." << endl;
    cout << "       1. Has 4 in total" << endl;
    cout << "       2. Doesn't own by anyone." << endl;
    cout << endl;
    cout << "V. Chance Card" << endl;
    cout << "   A. Suggestion: Better read card function before playing game." << endl;
    cout << "   B. Explanation of each card:" << endl;
    cout << "       1.Speed ahead!\nMove forward to 5 space." << endl;
    cout << "       2.Casino night!\nBoth you and your opponent roll.\nHighest-roller collects 200K from the bank." << endl;
    cout << "       3.Profits soar!\nAdvance to GO to collect your tower value." << endl;
    cout << "       4.Launch your website!\nSales skyrocket!\nCollect 300K from the bank." << endl;
    cout << "       5.Solar power bonus!\nTake a free Electric Company billboard.\nAdd it to your tower.\nIf none are available, do nothing." << endl;
    cout << "       6.Insider trading fine!\nPay the Bank 200K." << endl;
    cout << "       7.Tallest tower bonus!\nCheck what the highest tower is currently worth.\nCollect that amount from the bank." << endl;
    cout << "       8.Go To Jail!\nDo not collect cash for passing GO." << endl;
    cout << endl;
    cout << "VI. Win" << endl;
    cout << "   A. Whoever first get 800 collecting value wins." << endl;
    cout << "   B. Whoever first run out of money loses." << endl;
}