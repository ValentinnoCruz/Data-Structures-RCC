/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

#include <string>
#include "ExpressionNode.h"
#include "HashTable.h"

using namespace std;

class ExpressionTree {
private:
	ExpressionNode* root;
	HashTable hashmap;
	string equation;
	string recursionEval( ExpressionNode *node );
	void rInOrder( ExpressionNode *node );
	void rPostOrder( ExpressionNode *node );
	void rPreOrder( ExpressionNode *node );
public:
	ExpressionTree() :
		hashmap( 100000 ), 
		root(NULL){};
	virtual ~ExpressionTree();
	void helper( ExpressionNode *node );
	void create( string postfix );
	void create( string postfix, bool isPostfix );
	void inOrder();
	void postOrder();
	void preOrder();
	string evaluate();
	void clear();
	bool isStored();
};

#endif /* EXPRESSIONTREE_H */

