/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include <cstdlib>
#include <iostream>
#include <string>

#include "ExpressionTree.h"
#include "PostFix.h"
#include "HashTable.h"


using namespace std;

int main( int argc, char** argv ) {
	cout<< "expression tree solver\n";
	ExpressionTree tree;
	
	char inC;
	string str;
	bool isPost = false;
	bool isRunning = true;
	while( isRunning ){
		do{
			cout << "\ninput an infix or post-fix notation or q to quit (i or p or q): " << endl;
	//		cin.ignore();
			getline( cin, str );
			str[0] = (char)tolower( str[0] );
		} while( str[0] != 'i' && str[0] != 'p' && str[0] != 'q' );
		if( str[0] == 'q' ) { 
			isRunning = false;
			break;
		}
		isPost = ( str[0] == 'i' ? false : true );
		if( isPost ){
			cout << "input a post-fix expression\n";
		} else {
			cout << "input a infix expression\n";
		}

		getline( cin, str );
		tree.create( str, isPost );
		cout << ( tree.isStored() ? "Stored in hashtable\n" : "Not stored in hashtable\n" );
		cout << str << " = " << tree.evaluate() << endl;
	}
	
//	cout << str;
		
//	tree.clear();
//	tree.create( "3+3" );
//	cout << ( tree.isStored() ? "Stored in hashtable\n" : "Not stored in hashtable\n" );
//	tree.create( "2 2 +", true );
//	tree.evaluate();
//	tree.inOrder( );
//	tree.postOrder( );
//	tree.preOrder( );
//	tree.evaluate( );

//	cout << convert( "2+2" ) << endl;;
//	cout << convert( "3 * ( 4 + 5 )" )<< endl;;
//	cout << convert( "2 * ( ( 3 + 5 ) * ( 3 + 2 ) )" )<< endl;;
//	cout << convert( "6 * (3+(7*8)*(5+2))" )<< endl;

//	HashTable test( 100000 ); // .1% error for 100 elements
//	test.put( "hello", "test" );
//	cout << test.exists( "hello" );

	/*TODO
	 create hash table 
	 store the completed solutions in the hash table
	 check the hash table before making tree
	 */

	return 0;
}

