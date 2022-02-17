/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#ifndef POSTFIX_H
#define POSTFIX_H



#include "Tokenizer.h"

using namespace std;

bool isOperator(char test, bool parenthesise);

bool isOperator(char test);
bool isOperator(string test);

bool isNumber(char test);

int pemdas(char op);

bool isSolvable(string infix);

string convert(string infix);
#endif /* POSTFIX_H */

