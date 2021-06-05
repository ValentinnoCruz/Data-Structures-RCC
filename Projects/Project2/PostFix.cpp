/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include <algorithm>
#include <sstream>
#include <stack>
#include <iostream>
#include <cmath>
#include "PostFix.h"

using namespace std;

bool isOperator(char test, bool parenthesise) {
	if ( parenthesise ) {
		if ( test == ')' || test == '(' ) {
			return true;
		}
	}
	switch ( test ) {
		case '+':
		case '-':
		case '/':
		case '*':
		case '^':
			return true;
		default:
			return false;
	}
}

bool isOperator(char test) {
	return isOperator( test, true );
}

bool isOperator( string test ){
	if( test.length() > 1){
		bool op = isOperator( test[0], true );
		bool num = isNumber( test[1] );
		if( num && op ){ //negatives
			return false;
		} else if( num && !op ){ //decimals
			return false;
		} else {
			return true;
		}
	} else {
		return isOperator( test[0], true );
	}
	
}

bool isNumber(char test) {
	if ( ( (int) test >= 48 && (int) test <= 57 ) || test == '.' ) {
		return true;
	}
	return false;
}

int pemdas(char op) {
	//factorial does not fall under this
	//http://mathforum.org/library/drmath/view/57493.html
	if ( op == '(' || op == ')' ) {
		return 4;
	} else if ( op == '^' ) {
		return 3;
	} else if ( op == '*' || op == '/' ) {
		return 2;
	} else if ( op == '-' || op == '+' ) {
		return 1;
	}
	return -1; //should never happen but ya should check for it
}

bool isSolvable(string infix) {
	//remove space
	infix.erase( std::remove( infix.begin( ), infix.end( ), ' ' ), infix.end( ) );
	bool error = false;

	Tokenizer token( infix );
	int parenthesise = 0;
	for ( int i = 0; i < infix.length( ); i++ ) {
		if ( isOperator( token.get( ) ) ) {
			if ( token.get( ) == '(' ) {
				parenthesise++;
			} else if ( token.get( ) == ')' ) {
				parenthesise--;
			} else {
				if ( token.get( ) == '-' ) {
					if ( isOperator( token.behind( ), false ) && isOperator( token.forward( ), false ) ) { //is looks like this +-* something is wrong
						error = true;
					}
				} else {
					if ( token.behind( ) == 0 ) {
						error = true;
					}

					if ( isOperator( token.forward( ), false ) && token.forward( ) != '-' && token.get( ) != '!' ) {
						error = true;
					}
				}
			}
//			return false;
		}
		token.next( );
	}
	if ( parenthesise != 0 ) {
		error = true;
	}
	return !error;
}

string convert(string infix) {
	if ( !isSolvable( infix ) ) {
		cout << infix << " is not solvable!\n";
		return "";
	}


	//remove space
	infix.erase( std::remove( infix.begin( ), infix.end( ), ' ' ), infix.end( ) );

	Tokenizer token( infix );
	stringstream postfix;
	stack<char> ops;

	for ( int i = 0; i < infix.length( ); i++ ) {
		if ( isOperator( token.get( ) ) ) {
			if ( ops.empty( ) ) {
				if ( token.get( ) == '-' ) {
					if ( token.behind( ) == 0 ) {
						postfix << token.get( );
						token.next( );
						continue;
					} else if ( isOperator( token.behind( ), false ) ) {
						postfix << token.get( );
						token.next( );
						continue;
					} else {
						ops.push( token.get( ) );
					}
				} else { //no factorial
					ops.push( token.get( ) );
				}
			} else if ( token.get( ) == ')' ) {
				while ( !ops.empty( ) && ops.top( ) != '(' ) {
					postfix << ops.top( ) << " ";
					ops.pop( );
				}
				//removing the opening paren
				ops.pop( );
			} else {
				if ( token.get( ) == '-' ) {
					if ( token.behind( ) == 0 ) {
						postfix << token.get( );
						token.next( );
						continue;
					} else if ( isOperator( token.behind( ), false ) ) {
						postfix << token.get( );
						token.next( );
						continue;
					}
				}

				if ( ( token.get( ) == '(' && ops.top( ) == '(' ) ||
						( pemdas( ops.top( ) ) >= pemdas( token.get( ) ) ) ) { //if not an open paren and the stack is of higher or equal order pop into final
					while ( !ops.empty() && ops.top( ) != '(' && pemdas( ops.top( ) ) >= pemdas( token.get( ) ) ) {
						postfix << ops.top( ) << " ";
						ops.pop();
					}
					ops.push( token.get( ) );
				} else {
					ops.push( token.get( ) );
				}
			}
		} else if ( isNumber( token.get() ) ) {
				//DONE look for whole numbers, decimals, negatives
				if ( isNumber( token.forward() ) || token.forward() == '!' ) {
					//if the next char is a number or factorial put it in without space
					postfix << token.get();
				} else {
					postfix << token.get() << " ";
				}
		}
		token.next();
	}

	//pop whatever is left in the stack off be atleast 1
	while ( !ops.empty() ) {
		postfix << ops.top() << " ";
		ops.pop();
	}

	return postfix.str();
}
