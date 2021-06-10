

#ifndef GAME_H
#define GAME_H

#include <map>
#include <set>
#include <queue>
#include <fstream>
#include <list>


#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

typedef set< int > diskSet;

class Game {
private:
	map < int, diskSet > poles;
	int disks;
	int numPoles;
	bool guided;
	bool isSolved;
	int moves;
	list<int> scores;
	queue< pair< char, char > > steps;
	void towers(int, char, char, char);
public:

	Game(int disks) {
		this->numPoles = 3;
		this->disks = disks;
		this->guided = false;
		this->isSolved = false;
		this->moves = 0;
		//init the disks
		diskSet first;
		for ( int i = 1; i <= disks; i++ ) {
			first.insert( i );
		}
		poles.insert( pair< int, diskSet >( 1, first ) );
		for ( int i = 2; i <= numPoles; i++ ) {
			diskSet tempSet;
			poles.insert( pair< int, diskSet >( i, tempSet ) );
		}
	};

	~Game() {
	};

	void print() {
		diskSet::iterator setIts[numPoles];
		int j = 0;
		for ( map< int, diskSet >::iterator i = poles.begin( ); i != poles.end( ); ++i ) {
			setIts[j++] = i->second.begin();
		}
//		int j = 0;
		// find the max size
		int highest = max( poles[1].size(), max( poles[2].size(), poles[3].size() ) );
		for( int layer = highest; layer > 0; layer-- ){
			j = 0;
			for ( map< int, diskSet >::iterator i = poles.begin( ); i != poles.end( ); ++i ) {
				if( i->second.size() >= layer ){
					color( j, *(setIts[j]++) );
					color( j, "\t" );
					//cout << color(j) << *(setIts[j]++) << color(-1) << '\t';
				} else {
					color( j, " \t");
				}
				j++;
			}
			cout << endl;
		}
//		cout << "A\tB\tC" << endl;
		color( 0, "A\t");
		color( 1, "B\t");
		color( 2, "C\t");
	}

//	string color(){ return color(-1);}
	template<class T>
	void color( int i, T item ){
		#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
		int k;
		switch( i ){
			case 0: k = 12; break;
			case 1: k = 10; break;
			case 2: k = 9;  break;
			default: k = 0; break;;
		}
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, k);
		cout << item;
		SetConsoleTextAttribute(hConsole, 15);
		#else
		switch( i ){
			case 0:  cout << "\033[31m"; break;
			case 1:  cout << "\033[32m"; break;
			case 2:  cout << "\033[34m"; break;
			default: cout << "\033[39m";
		}
		cout << item << "\033[39m";
		#endif
	}

	void solution() {
		if( !isSolved ){
			towers( disks, 'a', 'b', 'c' );
			isSolved = true;
		}
		while ( !steps.empty( ) ) {
			cout << steps.front().first << " => " << steps.front().second << endl;
			steps.pop( );
		}
	}
	
	bool move( char _src, char _dest ){
		//check if both are valid and convert to nums
		int src = (int) ( tolower( _src ) ) - 96;
		int dest = (int) ( tolower( _dest ) )  - 96;
		if( src < 1 || src > numPoles ){
			cout << "Invalid Input\n";
			return false;
		}
		if( dest < 1 || dest > numPoles ){
			cout << "Invalid Input\n";
			return false;
		}
		
		//check that you didn't put it in twice
		if( src == dest ){
			return false;
		}
                // if the value for the sources is > the destination than move cant be done
//		cout << *( poles.at( src ).begin() ) << endl;
                
		//check if src if not empty, than go on
		if( !poles.at( src ).empty() ){
			//if the pole is empty thne we just move
			if( poles.at( dest ).empty() ){
				//switch to new pole
				int value = *( poles.at( src ).begin() );
				poles.at( src ).erase( value );
				poles.at( dest ).insert( value );
				moves++;
				return true;
			} else {
                                //if element at src > top element at destination then we fail it
				if( *( poles.at( src ).begin() ) > *( poles.at( dest ).begin() ) ){
					return false;
				} else {
					int value = *( poles.at( src ).begin() );
					poles.at( src ).erase( value );
					poles.at( dest ).insert( value );
					moves++;
					return true;
				}
			}
		} else{
			return false;
		}
		return false;
	}
	
	void setGuided( bool flag ){
		this->guided = flag;
		if( flag && !isSolved ){
			towers( disks, 'a', 'b', 'c' );
			isSolved = true;
		}
	}
	
	bool won(){
		if( poles.at( 1 ).empty() && poles.at( 2 ).empty() ){
			return true;
		} else {
			return false;
		}
	}
	
	int getMoves(){
		return moves;
	}
	
	bool isGuided(){
		return guided;
	}
	
	pair<char, char> pop(){
		pair<char, char> temp = steps.front();
		steps.pop();
		return temp;
	}
	
	void save(){
		scores.push_back( moves );
		scores.sort();
	}
	
	void displayScores(){
		int j = 1;
		cout << "Scores\n";
		for( list<int>::iterator i = scores.begin(); i != scores.end(); ++i ){
			cout << j++ << ": Moves " << *i << endl;
		}
	}
	
	void reset(){
		this->disks = disks;
		this->guided = false;
		this->isSolved = false;
		this->moves = 0;
		poles.clear();
		//init disks
		diskSet first;
		for ( int i = 1; i <= disks; i++ ) {
			first.insert( i );
		}
		poles.insert( pair< int, diskSet >( 1, first ) );
		for ( int i = 2; i <= numPoles; i++ ) {
			diskSet tempSet;
			poles.insert( pair< int, diskSet >( i, tempSet ) );
		}
	}
	
};

void Game::towers(int nDisk, char src, char spare, char dest) {
	if ( nDisk > 1 ){
		towers( nDisk - 1, src, dest, spare );
	}
	steps.push( pair<char, char>( src, dest ) );
	if ( nDisk > 1 ) {
		towers( nDisk - 1, spare, src, dest );
	}
}
#endif /* GAME_H */

