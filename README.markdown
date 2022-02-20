**Project 2**

Tittle

**Monopoly: Empire Ver 1.2**

Course

**CSC-17C**

Due Date

**June 7, 2021**

Author

**Valentinno Cruz**

**Introduction**

Monopoly is a common series of American board game which allow multiple
players to roll dices and make movements on the game board. Depending on
the luck of player, player can buy land, pay rent, or even get chance
card to react differently by following the instruction.

Monopoly: Empire is a game that players collect brand billboards instead
of land. Each player has 1000K at the beginning, and tries to use the
money properly to get 800 credits of brands. During the time of
collecting billboards, players also can attack each other to avoid their
opponents to get enough credit.

Also, the chance card in the game plays an important role. Some of the
card can help player get more money or attack opponents, but some can be
harmful to player himself.

In the game, who collect 800 credits is the winner; however, who run out
of money will automatically consider as loser. This asks players to take
care of the usage of their money when busy collecting billboards!

**II. Game Rules**

**A. Basic Rules**

Each player has 1000K at beginning and start at position #0.

In each turn, player roll 2 dices, and move corresponding steps.

When stop at a position, follow the instruction of that position.

\[1\] represent player, \[2\] represent computer.

**B. Game Board**

Total 24 positions (0\~24) of 7 types.

Start

Every player start from here.

When pass start point, collect as much money as your total collecting
value.

Billboard

Containing name, price, collecting value, and condition(0,1 or 2).

The first two lines are the name of the brand.

The third line is price (collecting value), eg.100K (50).

Price ≠ collecting value.

Price is how much cost you to buy the brand.

Collecting value is used for win the game.

The fourth line is (condition), eg. (1).

> (0 = no owner; 1 = player own; 2 = computer own)

The fifth line shows player\'s position, eg.\[1\] \[2\].

The bottom line has the position \# of that box.

Exception: Electric Company Billboard. (See IV. Billboard-E)

Chance Card

Randomly pick a chance card when stop at here.

Total 8 kinds of chance cards.

Chance card may not be good for player who pick it.

Jail

To get out of jail, there are two choice.

During next turn, pay 100K and get out at once.

Roll a double up to 3 turns, if not, pay 50K and get out at 3rd turn.

Position #19 is go to jail, player will be move to jail on Position #7.

Simply stop at position #7 is pass by, is not in jail.

Take a trip

You can spend 100K to move to anywhere on board, or simply do nothing.

If you move to a new position, you have to follow the instruction on
that position.

Tower Tax

Tower Tax: return your topmost billboard to board.

Rival Tower Tax: return your opponent\'s topmost billboard to board.

**C. Dices**

One normal dice, one special dice with a \'swap\' face.

When \'swap\' face is up, you have a chance of sneaky swap.

> (sneaky swap: swap your topmost billboard with your opponent\'s)

When you roll a double, you can have another turn until you don\'t have
a double.

(double: two dices have same number)

**D. Billboard**

14 billboards total; different price with different collecting value;
choose smartly!

You can buy billboards when you stop at the corresponding position if
the condition is no owner.

You have to pay rent fee if you stop at a position whose billboard is
owner by your opponents.

Nothing will happen if you stop at the position that is owned by
yourself.

One exception is Electric Company Billboard at position #9.

Has 4 in total

Doesn\'t own by anyone.

**E. Chance Card**

Total 8 cards has different functions.

**F. Win**

Whoever first get 800 collecting value wins.

Whoever first run out of money loses.

**G. Bonus**

The bonus area will be open for player each time when player win a game.

**G. Tips For Brand Buying**

The unit value for different brand is different. Be wise to choose which
brand to buy!

1.  The brand unit value sorting (See program).

**III. Summary**

  -----------------------------------------------------------------------
  **Total Line of Code**                    **2179**
  ----------------------------------------- -----------------------------
  **Utilized from other source**            457

  **Variable**                              50

  **Classes**                               4
  -----------------------------------------------------------------------

Basically, this game is designed for single player playing with
computer. There is a player class contains each player's information,
including computer, and a game class to control all process happened
during the game. I make all the decisions in main function to see the
structure clearly. In the new 1.2 version, I utilized two new classes
from other source, combined with my original code. One is a hash classes
that contains 11 hash functions; the other is a AVL Tree class that
helps me insert, balance, and output an AVL Tree.

My program basically build on the linked list and its extending usage.
In these function, I utilized linked list to contain the collecting
value, and use linked list to be act like a stack. I also use map to
match the corresponding position #, selling price and collecting value.

In new 1.2 version, I had problems of thinking how to use all the
knowledge we learned recently. The first thing I utilized is the hash
function. I set a password for player each time start a game, and use
merkle tree and hash to test if the password is correct. Then I created
a bonus area, and this area will only appear when the player wins the
game. In the bonus area, player can see his Billboard values in last
game, and even in pre-order, in-order, and post-order of a tree. I also
utilized quick sort and map to sort all their brands by their unit
value, so that player can see which brand is more worth to buy from
"Reading Rules" part. I did not use all methods within Hash and AVL Tree
classes, but I kept them so that I can make developments based on them
later.

**IV. Description**

**A. Flowcharts**

Main:

![](media/image1.png){width="5.317307524059492in"
height="7.764326334208224in"}

Process:![](media/image2.png){width="5.5736843832020995in"
height="7.756300306211724in"}

**B. Concepts**

+-----------+---------------+---------------------------+-------------+
| Concept   | Type          | Code                      | Loc         |
| of STL    |               |                           | ation(line) |
+===========+===============+===========================+=============+
| Linked    | Link \*       | struct Link {             | Link.h      |
| list      |               |                           |             |
|           |               | int data;                 |             |
|           |               |                           |             |
|           |               | Link \*LinkPtr; };        |             |
+-----------+---------------+---------------------------+-------------+
|           |               | Link \*bdName;            | Player.h\   |
|           |               |                           | 25-26       |
|           |               | Link \*bdFront;           |             |
+-----------+---------------+---------------------------+-------------+
| Stack     | Linked list   | void addBdName(int);\     | Player.h\   |
|           |               | void addFront(int);       | 38-39       |
+-----------+---------------+---------------------------+-------------+
|           |               | void pop(int);            | Player.h\   |
|           |               |                           | 40          |
+-----------+---------------+---------------------------+-------------+
| Find end  | Linked list   | Link \*endLst(int);       | Player.h\   |
|           |               |                           | 30          |
+-----------+---------------+---------------------------+-------------+
| Search    | Linked list   | bool search(int, int);    | Player.h\   |
|           |               |                           | 31          |
+-----------+---------------+---------------------------+-------------+
| Print     | Linked list   | void prntLst(int);        | Player.h    |
| list      |               |                           |             |
|           |               |                           | 44          |
+-----------+---------------+---------------------------+-------------+
| Map       | \<int, int\>  | map\<int, int\>sell;\     | Game.h      |
|           |               | map\<int, int\>coll;      |             |
|           |               |                           | 32-33       |
+-----------+---------------+---------------------------+-------------+
|           | \<string,     | map\<string, int\>value;  | Game.h      |
|           | int\>         |                           |             |
|           |               |                           | 35          |
+-----------+---------------+---------------------------+-------------+
|           | Iterator      | map\<string,              | Game.h      |
|           |               | int\>::iterator iter;     |             |
|           |               |                           | 36          |
+-----------+---------------+---------------------------+-------------+
| Vector    | \<int\>       | vector\<int\>score;       | Game.h      |
|           |               |                           |             |
|           |               |                           | 37          |
+-----------+---------------+---------------------------+-------------+
| Hash      | s             | RSHash();                 | main.cpp    |
|           | tring---\>int |                           |             |
|           |               | BPHash();                 | 77-79       |
|           |               |                           |             |
|           |               | ELFHash();                |             |
+-----------+---------------+---------------------------+-------------+
| AVL Tree  | Linked list   | Self Balance              | main.cpp    |
|           |               |                           |             |
|           |               | Pre-order                 | 512-528     |
|           |               |                           |             |
|           |               | In-order                  |             |
|           |               |                           |             |
|           |               | Post-order                |             |
+-----------+---------------+---------------------------+-------------+
| Quick     | int array\[\] | void valueSort();         | Game.cpp    |
| Sort      |               |                           |             |
|           |               | void quickSort(int \[\],  | 99-150      |
|           |               | int, int);                |             |
|           |               |                           |             |
|           |               | int partition(int \[\],   |             |
|           |               | int, int);                |             |
|           |               |                           |             |
|           |               | void qSwap(int &, int &); |             |
+-----------+---------------+---------------------------+-------------+

