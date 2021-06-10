
//System Libraries
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

//User Libraries
#include "Game.h"
//Global Constants

//Function Prototypes
void enterRcd(char);

//Execution Begins here!

int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int> (time(0)));

    //Declare Variables
    Game game; //New game
    char enter; //Record enter
    char cho; //Record player's choice
    int choice; //Transfer cho to int for calculation
    string pName; //Player's name
    char sneaky; //Answer for sneaky swap
    int pos; //Hold the position info
    char buy; //Hold buying info
    char jum; //Hold answer for jump
    int jail; //choice in jail
    int start; //start the game first
    bool doub; //Judge for rolling double


    //Title
    game.title();


    //Start Menu
    do {
        //Next page
        enterRcd(enter);

        cout << "\n Monopoly: Empire" << endl;
        cout << "\n Start Menu" << endl;
        cout << " 1. Start New Game" << endl;
        cout << " 2. Read Rules" << endl;
        cout << " 0. Quit" << endl;
        cout << "(For a better playing experience,strongly suggest read rules before you start the game!!!)" << endl;
        do {
            cout << "\nPlease enter the number of your choice (0~2):" << endl;
            cin >> cho;
            if (cho != 48 && cho != 49 & cho != 50)
                cout << "Invalid input! Please enter a number between 0 to 2." << endl;
        } while (cho != 48 && cho != 49 & cho != 50);
        //Transfer cho to int
        choice = cho - 48;

        //Quit the game
        if (choice != 1 && choice != 2) {
            system("clear");
            cout << "You quit the game." << endl;
        }

        switch (choice) {
            case 1:
                system("clear");
                //Promote for players' name
                cout << "Please enter your name correctly:" << endl;
                cin >> pName;
                game.setName(pName, "Computer");

                system("clear");
                //Output the game board
                cout << "Monopoly: Empire Game Board:" << endl;
                game.output();

                //Randomly choose who starts first
                cout << "\nRandomly choosing who starts first..." << endl;
                game.setStart();
                start = game.getStart();

                if (start == 0) cout << "You are first to start!" << endl;
                else cout << "Computer starts first." << endl;

                //Next page
                cout << "\nPress enter to continue." << endl;
                cin.ignore();
                enterRcd(enter);

                do {
                    //Turn 1
                    system("clear");
                    cout << "\n Turn #" << game.getTurn() << endl;
                    game.output();

                    switch (start) {
                        case 0://Player starts first
                            //If player is in jail
                            do {
                                doub = false;
                                cout << "Your turn:" << endl;
                                if (game.getJail(1) == true) {
                                    cout << "\nYou are currently in jail, and you have two choices: " << endl;
                                    cout << " 1. Pay 100K to get out." << endl;
                                    cout << " 2. Roll a double up to 3 turns; if not, pay 50K." << endl;
                                    do {
                                        cout << "\nPlease enter your choice (1 or 2): ";
                                        cin >> jail;
                                        cout << endl;
                                        if (jail < 1 || jail > 2)
                                            cout << "Invalid input! Please enter 1 or 2." << endl;
                                        if (game.jailJudge(jail) == false)
                                            cout << "You are unable to pay the fee." << endl;
                                    } while (jail < 1 || jail > 2 || game.jailJudge(jail) == false);
                                    game.outJail(1, jail);

                                    //Next page
                                    cout << "\nPress enter to continue." << endl;
                                    cin.ignore();
                                    enterRcd(enter);

                                    //Output
                                    game.output();
                                }
                                if (game.getJail(1) == false) {
                                    //First roll two dice
                                    cout << "\nRolling dice..." << endl;
                                    game.setDices();
                                    cout << "Your result is: " << game.getDice1() << " " << game.getDice2() << endl << endl;
                                    if (game.getDice1() == game.getDice2()) doub = true;
                                    //If get the swap face up
                                    if (game.getDice1() == 's') {
                                        cout << "Do you want to use the sneaky swap?" << endl;
                                        cout << "(Switch your topmost billboard with your opponent's topmost billboard," << endl;
                                        cout << "then don't move this turn; or just use the second dice to move.)" << endl;
                                        do {
                                            cout << "\nPlease enter yes or no (y or n): ";
                                            cin >> sneaky;
                                            if (tolower(sneaky) != 'y' && tolower(sneaky) != 'n')
                                                cout << "Invalid input! Please enter y or n." << endl;
                                        } while (tolower(sneaky) != 'y' && tolower(sneaky) != 'n');
                                        //Do sneaky swap
                                        if (tolower(sneaky) == 'y') {
                                            cout << "\nYou use sneaky swap." << endl;
                                            game.swap();
                                            //Or just use the second dice
                                        } else {
                                            cout << "\nYou did not use sneaky swap." << endl;
                                            game.move(1, game.getDice2() - 48);
                                        }
                                        cout << "\nPress enter to continue." << endl;
                                        cin.ignore();
                                    } else {//Normally just move by using two dices
                                        game.move(1, (game.getDice1() - 48) + (game.getDice2() - 48));
                                        cout << "\nPress enter to continue." << endl;

                                    }
                                    enterRcd(enter);

                                    //Output
                                    game.output();

                                    //Ask player to buy brand if land on it
                                    pos = game.getPos(1);
                                    if (pos == 12) {
                                        cout << "\nDo you want to take a trip (100K)?" << endl;
                                        cout << "(You can spend 100K to move to anywhere on board or do nothing)" << endl;
                                        do {
                                            cout << "\nPlease enter yes or no (y or n): ";
                                            cin >> jum;
                                            cout << endl;
                                            if (tolower(jum) != 'y' && tolower(jum) != 'n')
                                                cout << "Invalid input! Please enter y or n." << endl;
                                        } while (tolower(jum) != 'y' && tolower(jum) != 'n');
                                        if (tolower(jum) == 'y') {
                                            cout << "Where do you want to go?" << endl;
                                            do {
                                                cout << "Please enter the position # (0~23): ";
                                                cin >> pos;
                                                cout << endl;
                                                if (pos < 0 || pos > 23 || pos == 12)
                                                    cout << "Invalid input! Please enter a number between 0~23." << endl;
                                            } while (pos < 0 || pos > 23 || pos == 12);
                                            game.jump(1, pos);
                                            cout << "\nYou jump to position #" << pos << endl;
                                        }
                                        //Next page
                                        cout << "\nPress enter to continue." << endl;
                                        cin.ignore();
                                        enterRcd(enter);

                                        //Output
                                        game.output();
                                    }
                                    if (pos == 2 || pos == 4 || pos == 6 || pos == 8 || pos == 10 || pos == 11 || pos == 13
                                            || pos == 15 || pos == 16 || pos == 18 || pos == 20 || pos == 21 || pos == 23) {
                                        cout << game.sale(pos) << endl;
                                        if (game.sale(pos) == 0) {
                                            cout << "\nYou stopped at position #" << pos << endl;
                                            cout << "Do you want to spend " << game.getSell(pos) << "K to buy this brand?" << endl;
                                            do {
                                                cout << "\nPlease enter yes or no (y or n): ";
                                                cin >> buy;
                                                cout << endl;
                                                if (tolower(buy) != 'y' && tolower(buy) != 'n')
                                                    cout << "Invalid input! Please enter y or n." << endl;
                                            } while (tolower(buy) != 'y' && tolower(buy) != 'n');
                                            //Buy the brand
                                            if (tolower(buy) == 'y') {
                                                cout << "You bought the brand at position " << pos << " with " << game.getSell(pos) << "K." << endl;
                                                game.buyBrnd(1, pos);
                                            }
                                            cin.ignore();
                                        } else if (game.sale(pos) == 2) {
                                            if (game.getJail(2)) {
                                                cout << "\nComputer is currently in jail." << endl;
                                                cout << "You don't need to pay the fee." << endl;
                                            } else {
                                                cout << "\nThis brand belongs to " << game.getName(2) << "." << endl;
                                                cout << "You have to pay " << game.getName(2) << " " << game.getSell(pos) << "K." << endl;
                                                game.payRent(1, pos);
                                            }
                                        } else cout << "\nYou stop at the brand belongs to you." << endl;
                                        //Next page
                                        cout << "\nPress enter to continue." << endl;
                                        enterRcd(enter);

                                        //Output
                                        game.output();
                                    } else if (pos == 19) {
                                        cout << "\nYou are sending to jail!" << endl;
                                        game.jail(1);
                                        //Next page
                                        cout << "\nPress enter to continue." << endl;
                                        enterRcd(enter);

                                        //Output
                                        game.output();
                                    } else if (pos == 1) {
                                        cout << "\nYou stopped at Rival Tower Tax." << endl;
                                        cout << "You return Computer's topmost billboard to the board." << endl << endl;
                                        game.remove(2);
                                        //Next page
                                        cout << "\nPress enter to continue." << endl;
                                        enterRcd(enter);

                                        //Output
                                        game.output();
                                    } else if (pos == 22) {
                                        cout << "\nYou stopped at Tower Tax." << endl;
                                        cout << "You return your topmost billboard to the board." << endl << endl;
                                        game.remove(1);
                                        //Next page
                                        cout << "\nPress enter to continue." << endl;
                                        enterRcd(enter);

                                        //Output
                                        game.output();
                                    } else if (pos == 3 || pos == 5 || pos == 14 || pos == 17) {
                                        cout << "\nYou randomly pick a chance card!" << endl;
                                        game.chanCrd(1);
                                        //Next page
                                        cout << "\nPress enter to continue." << endl;
                                        enterRcd(enter);

                                        //Output
                                        game.output();
                                    } else if (pos == 9) {
                                        if (game.getElc() > 0) {
                                            cout << "\n Do you want to spend 150K to buy a Electric Company Billboard?" << endl;
                                            do {
                                                cout << "\nPlease enter yes or no (y or n): ";
                                                cin >> buy;
                                                cout << endl;
                                                if (tolower(buy) != 'y' && tolower(buy) != 'n')
                                                    cout << "Invalid input! Please enter y or n." << endl;
                                            } while (tolower(buy) != 'y' && tolower(buy) != 'n');
                                            if (tolower(buy) == 'y') {
                                                cout << "You bought one Electric Company Billboard with " << game.getSell(pos) << "K." << endl;
                                                game.buyElec(1);
                                            }
                                            cin.ignore();
                                        } else cout << "\nNo Electric Company Billboard available!" << endl;
                                        //Next page
                                        cout << "\nPress enter to continue." << endl;
                                        enterRcd(enter);

                                        //Output
                                        game.output();
                                    }
                                }
                            } while (doub);
                        case 1:
                            do {
                                doub = false;
                                cout << "Computer's turn: " << endl;
                                //If player is in jail
                                if (game.getJail(2) == true) {
                                    cout << "\nComputer is currently in jail." << endl << endl;
                                    game.outJail(2, 0);
                                    //Next page
                                    cout << "\nPress enter to continue." << endl;
                                    enterRcd(enter);

                                    //Output
                                    game.output();
                                }
                                if (game.getJail(2) == false) {
                                    //First roll two dices
                                    cout << "\nRolling dice..." << endl;
                                    game.setDices();
                                    cout << "Computer's result is: " << game.getDice1() << " " << game.getDice2() << endl << endl;
                                    if (game.getDice1() == game.getDice2()) doub = true;
                                    //If get the swap face up
                                    if (game.getDice1() == 's') {
                                        if (game.compare()) {
                                            cout << "Computer used sneaky swap!" << endl;
                                            game.swap();
                                        } else {
                                            cout << "Computer didn't use sneaky swap!" << endl;
                                            game.move(2, game.getDice2() - 48);
                                        }
                                    } else {
                                        game.move(2, (game.getDice1() - 48) + (game.getDice2() - 48));

                                    }
                                    //Next page
                                    cout << "\nPress enter to continue." << endl;
                                    enterRcd(enter);

                                    //Output
                                    game.output();

                                    //Ask player to buy brand if land on it
                                    pos = game.getPos(2);
                                    if (pos == 12) {
                                        game.tripAI();
                                        //Next page
                                        cout << "\nPress enter to continue." << endl;
                                        enterRcd(enter);

                                        //Output
                                        game.output();
                                    }
                                    if (pos == 2 || pos == 4 || pos == 6 || pos == 8 || pos == 10 || pos == 11 || pos == 13
                                            || pos == 15 || pos == 16 || pos == 18 || pos == 20 || pos == 21 || pos == 23) {
                                        if (game.sale(pos) == 0) {
                                            if (game.getMoney(2) > 500) {
                                                cout << "\nComputer bought the brand at position " << pos << " with " << game.getSell(pos) << "K." << endl;
                                                game.buyBrnd(2, pos);
                                            } else if (game.getMoney(2) > 2 * game.getSell(pos)) {
                                                cout << "\nComputer bought the brand at position " << pos << " with " << game.getSell(pos) << "K." << endl;
                                                game.buyBrnd(2, pos);
                                            }
                                        } else if (game.sale(pos) == 1) {
                                            if (game.getJail(1)) {
                                                cout << "\nYou are currently in jail." << endl;
                                                cout << "Computer did not pay you." << endl;
                                            } else {
                                                cout << "\nComputer stop at the brand belongs to you." << endl;
                                                cout << "Computer paid you " << game.getSell(pos) << "K." << endl;
                                                game.payRent(2, pos);
                                            }
                                        }
                                        //Next page
                                        cout << "\nPress enter to continue." << endl;
                                        enterRcd(enter);

                                        //Output
                                        game.output();
                                    } else if (pos == 19) {
                                        cout << "\nComputer is sending to jail!" << endl;
                                        game.jail(2);
                                        //Next page
                                        cout << "\nPress enter to continue." << endl;
                                        enterRcd(enter);

                                        //Output
                                        game.output();
                                    } else if (pos == 1) {
                                        cout << "\nComputer stopped at Rival Tower Tax." << endl;
                                        cout << "Computer return your topmost billboard to the board." << endl << endl;
                                        game.remove(1);
                                        //Next page
                                        cout << "\nPress enter to continue." << endl;
                                        enterRcd(enter);

                                        //Output
                                        game.output();
                                    } else if (pos == 22) {
                                        cout << "\nComputer stopped at Tower Tax." << endl;
                                        cout << "Computer return its topmost billboard to the board." << endl << endl;
                                        game.remove(2);
                                        //Next page
                                        cout << "\nPress enter to continue." << endl;
                                        enterRcd(enter);

                                        //Output
                                        game.output();
                                    } else if (pos == 3 || pos == 5 || pos == 14 || pos == 17) {
                                        cout << "\nComputer randomly picks a chance card!" << endl;
                                        game.chanCrd(2);
                                        //Next page
                                        cout << "\nPress enter to continue." << endl;
                                        enterRcd(enter);

                                        //Output
                                        game.output();
                                    } else if (pos == 9) {
                                        if (game.getElc() > 0) {
                                            if (game.getMoney(2) > 500) {
                                                cout << "\nComputer bought one Electric Company Billboard with " << game.getSell(pos) << "K." << endl;
                                                game.buyElec(2);
                                            } else if (game.getMoney(2) > 2 * game.getSell(pos)) {
                                                cout << "\nComputer bought one Electric Company Billboard with " << game.getSell(pos) << "K." << endl;
                                                game.buyElec(2);
                                            }
                                        }
                                        //Next page
                                        cout << "\nPress enter to continue." << endl;
                                        enterRcd(enter);

                                        //Output
                                        game.output();
                                    }
                                }
                            } while (doub);
                    }//End of switch (start first)
                    start = 0;
                    game.setOver();
                } while (game.getOver() == false);
                //Next page
                cout << "\nPress enter to continue." << endl;
                enterRcd(enter);

                //Output
                game.output();
                if (game.getWin() == true) {
                    cout << "\nCongratulation! You win the game." << endl;
                } else {
                    cout << "\nSorry you lose the game." << endl;
                }
            case 2:
                system("clear");
                game.rules();
                break;
        }//End of switch (game menu)
        cout << "\n Press enter to go back to Game Menu." << endl;
        do {
            enter = getchar();
        } while (enter != '\n');
    } while (enter == '\n');

    //Exit Stage right!
    return 0;
}

void enterRcd(char en) {
    do {
        en = getchar();
    } while (en != '\n');
    system("clear");
}
