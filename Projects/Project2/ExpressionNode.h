/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#ifndef EXPRESSIONNODE_H
#define EXPRESSIONNODE_H

#include <cstdlib>

using namespace std;

class ExpressionNode {
private:
	ExpressionNode* left;
	ExpressionNode* right;
	string data;
public:
	ExpressionNode( string data ){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
	virtual ~ExpressionNode(){
		delete left;
		delete right;
	}
	void setRight( ExpressionNode* node ){
		this->right = node;
	}
	
	void setLeft( ExpressionNode* node ){
		this->left = node;
	}

    void setData(string data) {
    	this->data = data;
    }

    string getData() const {
    	return data;
    }

    ExpressionNode* getRight() const {
    	return right;
    }

    ExpressionNode* getLeft() const {
    	return left;
    }
};

#endif /* EXPRESSIONNODE_H */

