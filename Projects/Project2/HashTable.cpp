/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <string>
#include <cstdlib>
#include <list>

#include "HashTable.h"

using namespace std;

HashTable::HashTable( int length ) {
	this->table = new list<string>[length];
	this->SIZE = length;
}


HashTable::~HashTable( ) {
	delete [] this->table;
}


uint HashTable::hash(string key){
	uint hash = RSHash( key );
	uint index = hash % this->SIZE;
	return index;
}


void HashTable::put( string key, string val ){
	uint index = hash( key );
	if( this->table[index].size() > 1 ){ //if it exists then we have a collision
		this->table[index].push_back( val );
	} else { 
		//there is no value here it is not a collision make the list and insert
		this->table[index].push_back( val );		
	}
}


string HashTable::at(string key){
	uint index = hash( key );
	
	if( this->table[index].size() > 0){
		//it exists return it
		if( this->table[index].size() == 1 ){
			return this->table[index].front();
		} else {
			return "collision"; //TODO fix this
		}
	}
	return "";
}


bool HashTable::hasCollision( string key ){
	uint index = hash( key );
	
	if( this->table[index].size() > 1){
		return true;
	} else {
		return false;
	}
}


bool HashTable::exists( string key ){
	uint index = hash( key );
	
	if( this->table[index].size() > 0){
		return true;
	} else {
		return false;
	}
}
