

#ifndef LNKLIST_H
#define	LNKLIST_H

#include <iostream>
using namespace std;

template <class T>
class LnkList {
    private:
        struct List {
            T value;
            struct List *next;
        };
        List *head;
        int size;
    public:
        //Constructor
        LnkList() {head=nullptr;size=0;}
        
        //Copy Constructor
        LnkList(const LnkList &);
        
        //Destructor
        ~LnkList();
        
        //extract
        void extr(T);
        void prepend(T);
        void append(T);
        void insertAfter(T,T);
        void insertBefore(T,T);
        void dspList() const; //display the list
        T &operator[](const int &);
        int getSize() const {return size;}
        void subError();
    
};

//Copy Constructor
template <class T>
LnkList<T>::LnkList(const LnkList &lnk) {
//    List *node1;//node for new Linked List
//    List *node2;//node For old Linked List
//    List *temp;//Temp int
//    this->size=lnk.size;
//    //cout<<"New List size: "<<size<<endl;
//    if(size==0) head=nullptr;
//    else {
//        //connect all the node together
//        head=new List;
//        head->next=nullptr;
//        temp=head;
//        for(int i=0;i<size-1;i++) {
//            temp->next=new List;
//            temp=temp->next;
//        }
//        node1=head;
//        node2=lnk.head;
//        //fill the list
//        for(int i=0;i<size;i++) {
//            node1->value=node2->value;
//            node1=node1->next;
//            node2=node2->next;
//        }
//    }
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

