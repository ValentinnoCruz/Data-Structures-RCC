/* 
 * File:   StLnkdLst.h
 * Author: Andrew
 *
 * Created on October 19, 2014, 2:36 PM
 */

#ifndef STLNKDLST_H
#define	STLNKDLST_H
#include <iostream>
using namespace std;

class StLnkdLst {
public:
    StLnkdLst();
    StLnkdLst(const StLnkdLst&);
    void push(int);
    void pop();
    virtual ~StLnkdLst();
private:
    struct Node{
        int data;
        Node *next;
    };
    Node *top;
    Node *worker;
};

#endif	/* STLNKDLST_H */

