

#ifndef PRIOLIST_H
#define	PRIOLIST_H

#include <iostream>
using namespace std;

template <class T>
class PrioList {
    protected:
        struct List {
            T value;
            struct List *next;
        };
        List *head;
        List *temp;
        int size;
    public:
        //Constructor
        PrioList() {head=nullptr;size=0;}
        PrioList(int);
        //Destructor
        ~PrioList();
        //extract
        void prepend(T);
        void append(T);
        void pop();
        void find(T);
        void dspList() const; //display the list
        T &operator[] (const int &);
        int getSize() const {return size;}
        void subError();
    
};
template <class T>
PrioList<T>::PrioList(int n) {
    if(n<1) head=nullptr;
    else {
        for(int i=0;i<n;i++)
            append(0);
    }
}

template <class T>
void PrioList<T>::pop() {
    if(head==nullptr) return;
    else {
        List *pre;
        List *node=head;
        while(node->next) {
            pre=node;
            node=node->next;
        }
        pre->next=nullptr;
        delete []node;
        size--;
    }
}

//Destructor
template <class T>
PrioList<T>::~PrioList() {
    List *node;
    List *nextNode;
    if(head!=nullptr) {
    node=head;
    //loop to delete the pointer
        do {
            //get the next node
            nextNode=node->next;
            //delete the current node
            delete node;
            node=nextNode;//point to the next one
        }while(node!=nullptr);
    }
}


//push the node containing value n at the beginning
template <class T>
void PrioList<T>::prepend(T n) {
    List *newNode;//node needed to push
    newNode=new List;
    //set the new node
    newNode->value=n;
    newNode->next=nullptr;
    //when head is null
    if(!head) head=newNode;
    else {
        newNode->next=head;
        head=newNode;
    }
    size++;
}
//push the node containing value n to the end
template <class T>
void PrioList<T>::append(T n) {
    List *node;
    List *newNode;//node needed to push
    newNode=new List;
    //set the new node
    newNode->value=n;
    newNode->next=nullptr;
    //when head is null
    if(head==nullptr) head=newNode;
    else {
        node=head;
        //loop to the last node
        while(node->next)
            node=node->next;
        node->next=newNode;
    }    
    size++;
}

template <class T>
void PrioList<T>::find(T n) {
    if(head==nullptr) return;
    else {
        List *node=head;
        List *temp;
        for(int i=0;i<size-1;i++) {
            if(node->next->value==n) {
                temp=node->next;
                node->next=temp->next;
                temp->next=head;
                head=temp;
            } else {
                node=node->next;
            }
        }
    }
}

//Output all node of Linked List
template <class T>
void PrioList<T>::dspList() const {
    List *node;
    node=head;
    //output the Linked List
    while(node) {
        cout<<node->value<<endl;
        node=node->next;
    } 
}

//Override operation
template <class T>
T &PrioList<T>::operator[](const int &sub) {
   if (sub < 0||sub >=size)
      subError();
   List *node=head;
   for(int i=0;i<sub;i++) {
       node=node->next;
   }
   return node->value;
}

// subError function. Displays an error message and         
// terminates the program when a subscript is out of range. 
template <class T>
void PrioList<T>::subError() {
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

#endif	/* PRIOLIST_H */

