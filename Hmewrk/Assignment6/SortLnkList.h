

#ifndef SORTLNKLIST_H
#define	SORTLNKLIST_H

#include <iostream>
using namespace std;

template <class T>
class SortLnkList {
    protected:
        struct List {
            T value;
            struct List *next;
        };
        List *head;
        int size;
    public:
        //Constructor
        SortLnkList() {head=nullptr;size=0;}
        SortLnkList(int);
        SortLnkList(const SortLnkList &);
        ~SortLnkList();
        void sort();
        void prepend(T);
        void append(T);
        void pop();
        void dspList() const; //display the list
        T &operator[](const int &);
        int getSize() const {return size;}
        void subError();
    
};
template <class T>
SortLnkList<T>::SortLnkList(int n) {
    if(n<1) head=nullptr;
    else {
        for(int i=0;i<n;i++)
            append(0);
    }
}

template <class T>
void SortLnkList<T>::pop() {
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

template <class T>
void SortLnkList<T>::sort() {
    T temp;
    for(int i=0;i<size-1;i++) {
        for(int j=i+1;j<size;j++) {
            if(operator[](i)>operator[](j)) {
                temp=operator[](i);
                operator[](i)=operator[](j);
                operator[](j)=temp;
            }
        }
    }
}

//Copy Constructor
template <class T>
SortLnkList<T>::SortLnkList(const SortLnkList &lnk) {
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
SortLnkList<T>::~SortLnkList() {
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
void SortLnkList<T>::prepend(T n) {
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
void SortLnkList<T>::append(T n) {
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

//Output all node of Linked List
template <class T>
void SortLnkList<T>::dspList() const {
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
T &SortLnkList<T>::operator[](const int &sub) {
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
void SortLnkList<T>::subError() {
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

#endif	/* SORTLNKLIST_H */

