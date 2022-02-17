/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <cstdlib>
#include <list>

#include "GeneralHashFunctions.h"

using namespace std;

/*
 this class is flawed because the hash requires a string 
 */

typedef unsigned int uint;


class HashTable {
private:
	list<string> *table;
	int SIZE;
	uint hash( string key );
public:
	HashTable( int length);
	virtual ~HashTable();
	void put( string key, string val );
	string at( string key );
	bool hasCollision( string key );
	bool exists( string key );
};




#endif /* HASHTABLE_H */

