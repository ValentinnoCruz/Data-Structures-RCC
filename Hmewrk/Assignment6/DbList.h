

#ifndef DBLIST_H
#define	DBLIST_H

#include <iostream>
using namespace std;

template <class T>
class DbList {
    private:
        struct List {
            T value;
            List *prev;
            List *next;
        };
        List *head;
        List *rear;
        int size;
    public:
        DbList() {head=nullptr;rear=nullptr;size=0;}
        DbList(int);
        void append(T);
        void prepend(T);
        void pop();
        void dspList() const;
        void revDsp() const;//reversely display the list
        
};

template <class T>
DbList<T>::DbList(int n) {
    if(n<1) {
        head=nullptr;
        rear=nullptr;
        size=0;
    } else {
        for(int i=0;i<n;i++)
            append(0);
    }
}

template <class T>
void DbList<T>::append(T n) {
    List *node;
    List *newNode;//node needed to push
    newNode=new List;
    //set the new node
    newNode->value=n;
    newNode->next=nullptr;
    newNode->prev=nullptr;
    //when head is null
    if(head==nullptr) {
        head=newNode;
        rear=newNode;
    } else {
        newNode->prev=rear;
        rear->next=newNode;
        rear=newNode;
    }    
    size++;
}

template <class T>
void DbList<T>::prepend(T n) {
    List *newNode;//node needed to push
    newNode=new List;
    //set the new node
    newNode->value=n;
    newNode->next=nullptr;
    newNode->prev=nullptr;
    if(head==nullptr) {
        head=newNode;
        rear=newNode;
    } else {
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
    size++;
}

template <class T>
void DbList<T>::pop() {
    if(head==nullptr) return;
    else {
        List *pre;
        List *node=head;
        while(node->next) {
            pre=node;
            node=node->next;
        }
        rear=pre;
        pre->next=nullptr;
        delete []node;
        size--;
    }
}

template <class T>
void DbList<T>::dspList() const {
    List *node=head;
    //output the Linked List
    while(node) {
        cout<<node->value<<endl;
        node=node->next;
    }
}

template <class T>
void DbList<T>::revDsp() const {
    List *node=rear;
    while(node) {
        cout<<node->value<<endl;
        node=node->prev;
    }
}

#endif	/* DBLIST_H */

