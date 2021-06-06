
#ifndef CIRLIST_H
#define	CIRLIST_H

#include <iostream>
using namespace std;

template <class T>
class CirList {
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
        CirList() {head=nullptr;rear=nullptr;size=0;}
        CirList(int);
        void append(T);
        void prepend(T);
        void pop();
        void dspList() const;
        void revDsp() const;//reversely display the list
        
};


//Something wrong here
template <class T>
CirList<T>::CirList(int n) {
    head=nullptr;
    rear=nullptr;
    size=0;
    if(n>=1) {
        for(int i=0;i<n-1;i++) {
            append(0);
        }
    }
}

template <class T>
void CirList<T>::append(T n) {
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
        head->next=rear;
        rear->next=head;
        rear->prev=head;
        head->prev=rear;
    } else {
        newNode->prev=rear;
        newNode->next=head;
        rear->next=newNode;
        rear=newNode;
        head->prev=rear;
    }    
    size++;
}

template <class T>
void CirList<T>::prepend(T n) {
    List *newNode;//node needed to push
    newNode=new List;
    //set the new node
    newNode->value=n;
    newNode->next=nullptr;
    newNode->prev=nullptr;
    if(head==nullptr) {
        head=newNode;
        rear=newNode;
        head->next=rear;
        rear->next=head;
        rear->prev=head;
        head->prev=rear;
    } else {
        newNode->next=head;
        newNode->prev=rear;
        head->prev=newNode;
        head=newNode;
        rear->next=head;
    }
    size++;
}

template <class T>
void CirList<T>::pop() {
    if(head==nullptr) return;
    else {
        List *node=rear;
        rear->prev->next=head;
        head->prev=rear->prev;
        rear=rear->prev;
        delete []node;
        size--;
    }
}

template <class T>
void CirList<T>::dspList() const {
    List *node=head;
    //output the Linked List
    for(int i=0;i<2*size;i++) {
        cout<<node->value<<endl;
        node=node->next;
    }
}

template <class T>
void CirList<T>::revDsp() const {
    List *node=rear;
    for(int i=0;i<2*size;i++) {
        cout<<node->value<<endl;
        node=node->prev;
    }
}

#endif	/* CIRLIST_H */

