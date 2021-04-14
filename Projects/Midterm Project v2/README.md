# Monopoly Empire

1. **Introduction**

Monopoly is a common series of American board game which allow multiple players to roll dices and make movements on the game board. Depending on the luck of player, player can buy land, pay rent, or even get chance card to react differently by following the instruction.

Monopoly: Empire is a game that players collect brand billboards instead of land. Each player has 1000K at the beginning, and tries to use the money properly to get 800 credits of brands. During the time of collecting billboards, players also can attack each other to avoid their opponents to get enough credit.

Also, the chance card in the game plays an important role. Some of the card can help player get more money or attack opponents, but some can be harmful to player himself.

In the game, who collect 800 credits is the winner; however, who run out of money will automatically consider as loser. This asks players to take care of the usage of their money when busy collecting billboards!

**A. Basic Rules**
1. Each player has 1000K at beginning and start at position #0. 
1. In each turn, player roll 2 dices, and move corresponding steps.
1. When stop at a position, follow the instruction of that position.
1. [1] represent player, [2] represent computer.

**B. Game Board**
1. Total 24 positions (0~24) of 7 types.
1. Start
   - Every player start from here.
   - When pass start point, collect as much money as your total collecting value.
1. Billboard
   - Containing name, price, collecting value, and condition(0,1 or 2).
   - The first two lines are the name of the brand.
   - The third line is price (collecting value), eg.100K (50).
     - Price ≠ collecting value.
     - Price is how much cost you to buy the brand.
     - Collecting value is used for win the game.
   - The fourth line is (condition), eg. (1).

(0 = no owner; 1 = player own; 2 = computer own)

- The fifth line shows player's position, eg.[1] [2].
- The bottom line has the position # of that box.
- Exception: Electric Company Billboard. (See IV. Billboard-E)
1. Chance Card
   - Randomly pick a chance card when stop at here.
   - Total 8 kinds of chance cards.
   - Chance card may not be good for player who pick it.
1. Jail
   - To get out of jail, there are two choice.
     - During next turn, pay 100K and get out at once.
     - Roll a double up to 3 turns, if not, pay 50K and get out at 3rd turn. 
   - Position #19 is go to jail, player will be move to jail on Position #7.
   - Simply stop at position #7 is pass by, is not in jail.
1. Take a trip
   - You can spend 100K to move to anywhere on board, or simply do nothing.
   - If you move to a new position, you have to follow the instruction on that position.
1. Tower Tax
   - Tower Tax: return your topmost billboard to board.
   - Rival Tower Tax: return your opponent's topmost billboard to board.

**C. Dices**

1. One normal dice, one special dice with a 'swap' face.
1. When 'swap' face is up, you have a chance of sneaky swap.

(sneaky swap: swap your topmost billboard with your opponent's)

1. When you roll a double, you can have another turn until you don't have a double.

(double: two dices have same number)

**D. Billboard**

1. 14 billboards total; different price with different collecting value; choose smartly!
1. You can buy billboards when you stop at the corresponding position if the condition is no owner.
1. You have to pay rent fee if you stop at a position whose billboard is owner by your opponents.
1. Nothing will happen if you stop at the position that is owned by yourself.
1. One exception is Electric Company Billboard at position #9.
   - Has 4 in total
   - Doesn't own by anyone.

**E. Chance Card**
**
Total 8 cards has different functions.



**F.  Win**

1. Whoever first get 800 collecting value wins.
1. Whoever first run out of money loses.

**III. Summary**

|**Total Line of Code**|**1496**|
| :-: | :-: |
|**Comment Line**|-|
|**Variable**|36|
|**Class**|2|

**	Basically, the game is for 2 players playing. There is a player class contain a single player’s information, and a game class to control all process happened during the game. I make all the decisions in main function to see the structure clearly. 

My program basically build on the linked list and its extending usage. In these function, I utilized linked list to contain the collecting value, and use linked list to be act like a stack. I also use map to match the corresponding position #, selling price and collecting value. 

I tried to use clear windows function, but it seems somewhere is not so correct; there will be some remaining from last step showing in the window when clear it, and I do not really know how to fix it now, but I will work on it later.

**IV.  Description**




`	`**B. Concepts**

|Concept of STL|Type|Code|Location(line)|
| :-: | :-: | :-: | :-: |
|Linked list|Link \*|<p>struct Link {</p><p>int data;</p><p>Link \*LinkPtr; };</p>|Link.h|
|||Link \*bdName;|Player.h<br>24|
|||Link \*bdFront;|Player.h<br>25|
|Stack|Linked list|void addBdName(int);<br>void addFront(int);|Player.h<br>36-37|
|||void pop(int);|Player.h<br>40|
|Find end|Linked list|Link \*endLst(int);|Player.h<br>30|
|Search|Linked list|bool search(int, int);|Player.h<br>31|
|Print list|Linked list|void prntLst(int);|<p>Player.h</p><p>44</p>|
|Map|<int, int>|map<int, int>sell;<br>map<int, int>coll;|<p>Game.h</p><p>32-33</p>|
| | <string,int >| map<string, int>value; | Game.h 33; |
| | 	Iterator|	|map<string, int>::iterator iter;|	Game.h 36|
| Vector	| <int>	| vector<int>score;	| Game.h 37|
| Hash	| string—>int	| RSHash(); BPHash(); ELFHash();	| main.cpp 77-79|
| AVL Tree	| Linked list	| Self Balance, Pre-order, In-orderk Post-order	| main.cpp 512-528|
| Quick Sort	| int array[]	| void valueSort(); void quic Sort(int [], int, int); int partition(int [], int, int); void qSwap(int &, int &);	| Game.cpp 99-150 |

