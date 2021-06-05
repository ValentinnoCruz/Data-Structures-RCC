


#ifndef LNKLIST_H
#define	LNKLIST_H

#include <iostream>
using namespace std;

template <class T>
class LnkList {
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
        LnkList() {head=nullptr;size=0;}
        LnkList(int);
        //Copy Constructor
        LnkList(const LnkList &);
        //Destructor
        ~LnkList();
        //extract
        void extr(T);
        void prepend(T);
        void append(T);
        void pop();
        void insertAfter(T,T);
        void insertBefore(T,T);
        void dspList() const; //display the list
        T &operator[](const int &);
        int getSize() const {return size;}
        void subError();
    
};
template <class T>
LnkList<T>::LnkList(int n) {
    if(n<1) head=nullptr;
    else {
        for(int i=0;i<n;i++)
            append(0);
    }
}

template <class T>
void LnkList<T>::pop() {
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

//Copy Constructor
template <class T>
LnkList<T>::LnkList(const LnkList &lnk) {
    //New version for copy constructor using append function
    if(lnk.head==nullptr) head=nullptr;
    else {
        head=nullptr;
        List *node=lnk.head;
        do {
            this->append(node->value);
            node=node->next;
        } while(node->next!=nullptr);
    }
}

//Destructor
template <class T>
LnkList<T>::~LnkList() {
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
void LnkList<T>::prepend(T n) {
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
void LnkList<T>::append(T n) {
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

//insert a number n before number a 
template <class T>
void LnkList<T>::insertBefore(T n,T a) {
    List *newNode;//node needed to push
    List *node;
    newNode=new List;
    //set the new node
    newNode->value=n;
    newNode->next=nullptr; 
    if(head==nullptr) return;
    else if(head->value==a) {
            newNode->next=head;
            head=newNode;
    } else {
        node=head;
        while(node->next!=nullptr&&node->next->value!=a) {
            node=node->next;
        } 
        if(node->next!=nullptr&&node->next->value==a) {
            newNode->next=node->next;
            node->next=newNode;
            size++;
        }
    }
}

//insert a number n after number a 
template <class T>
void LnkList<T>::insertAfter(T n,T a) {
    List *newNode;//node needed to push
    List *node;
    newNode=new List;
    //set the new node
    newNode->value=n;
    newNode->next=nullptr; 
    if(head==nullptr) return;
    node=head;
    //loop to find a number a
    while(node->next!=nullptr&&node->value!=a) {
        node=node->next;
    } 
    if(node->value==a) {
        newNode->next=node->next;
        node->next=newNode;
        size++;
    }
    
}

//delete a node that contains value n
template <class T>
void LnkList<T>::extr(T n) {
    List *node=head;
    List *temp;//next node
    if(head==nullptr) return;
    while(node->next!=nullptr) {
        if(node->next->value==n) {
            temp=node->next;
            node->next=temp->next;
            delete temp;
            size--;
        } else {
            node=node->next;
        }
    }
    if(head->value==n) {
        node=node->next;
        delete head;
        head=node;
        size--;
    } 
}

//Output all node of Linked List
template <class T>
void LnkList<T>::dspList() const {
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
T &LnkList<T>::operator[](const int &sub) {
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
void LnkList<T>::subError() {
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

#endif	/* LNKLIST_H */

