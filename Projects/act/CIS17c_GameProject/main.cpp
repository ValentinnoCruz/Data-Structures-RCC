


#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <limits>

#include "Game.h"

using namespace std;

void Gamerunner( Game* game );
void won( Game* );
void clear();

int main( int argc, char** argv ) {
	int inInt = 2;
	printf( "How many Disks?: " );
	cin >> inInt;
	cin.ignore();
	Game *game = new Game( inInt );
	Gamerunner( game );
	delete game;
	return 0;
}

void Gamerunner( Game* game ){
	bool runnin = true;
	char inChar;
	string inStr;
	do {
		printf( "Follow along mode? (y or n): ");
		getline( cin, inStr );
	} while( inStr.compare( "y" ) != 0 && inStr.compare( "n" ) != 0 );
	if( inStr.compare( "y" ) == 0 ){
		game->setGuided( true );
	}
	clear();
	while( runnin ){
		game->print();
		cout << endl;
		if( game->isGuided() ){
			pair<char, char> move = game->pop();
			cout << "Your best move would be " << move.first << " to " << move.second << endl;
		}
		printf( "Enter the letter of the poles you wish to move.\n");
		printf( "Source ( char ): " );
		getline( cin, inStr );
//		cin.get( inChar );
		printf( "Destination ( char ): " );
		string temp;
//		cin.ignore();
		getline( cin, temp );
//		cin.get( temp );
		if( !game->move( inStr[0], temp[0] ) ){
			//invalid move
			cout << "Unable to move disk\n";
			if( temp[0] == 'z' ){
				runnin = false;
			}
		} 
		clear();
		//check if we won
		if( game->won() ){
			game->print();
			cout << "\nYou Win!!\nIn " << game->getMoves() << " moves.\n";
			runnin = false;
			if( !game->isGuided() ){
				game->save();
				game->displayScores();				
			}
			won( game );
		}
		
//		cout << inChar << ", " << temp;	
	}
	//game->solution();

}

void won( Game *game ) {
	char inChar;
	do {
		cout << "Try again? (y or n): ";
		cin >> inChar;
	} while ( inChar != 'n' && inChar != 'y' );
	if ( inChar == 'y' ) {
		game->reset( );
		system( "cls" );
		cin.ignore( );
		Gamerunner( game );
	}
}

void clear(){
	//clear the terminal

	#ifdef _WIN32
//	system( "CLS" ); // breaks netbeans for some reason.
	for( int i = 0; i < 50; i++ ){
		cout <<endl;
	}
	#else
	system( "clear" );
	#endif

	
}


