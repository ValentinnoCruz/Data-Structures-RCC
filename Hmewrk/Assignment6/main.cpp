

#include <iostream>
using namespace std;

#include "DbList.h"
#include "Stack_Queue.h"
#include "CirList.h"
#include "PrioList.h" 
#include "PrioQueue.h"
#include "SortLnkList.h"
int main(int argc, char** argv) {
    //Check Stack
    cout<<"Check Stack: "<<endl;
    Stack<int> x;
    x.append(10);
    x.append(1000);
    x.prepend(1);
    x.dspList();
    cout<<"After pop, the last element gone"<<endl;
    x.pop();
    x.dspList();
    cout<<endl;
    
    //Check Queue
    cout<<"Check Queue: "<<endl;
    Queue<int> qu;
    qu.append(10);
    qu.prepend(1);
    qu.append(100);
    qu.dspList();
    cout<<endl;
    cout<<"After pop, the first element gone"<<endl;
    qu.pop();
    qu.dspList();
    cout<<endl;
    
    //Check doubly linked list
    cout<<"Check doubly linked list: "<<endl;
    DbList<int> a(2);
    a.append(10);
    a.append(100);
    a.prepend(421);
    a.pop();
    a.append(10000);
    a.dspList();
    cout<<"\nReversely display the List: \n";
    a.revDsp();
    cout<<endl;
    
    //Check circular linked list
    cout<<"Check circular linked list: "<<endl;
    CirList<int> ab(1);
    ab.append(10);
    ab.prepend(45);
    ab.append(1000);
    ab.pop();
    cout<<"The display function contains output two lap of circular List"<<endl;
    cout<<"Output with order: "<<endl;
    ab.dspList();
    cout<<endl<<"Reversely output: "<<endl;
    ab.revDsp();
    cout<<endl;
    
    //Test Priority Linked List
    cout<<"Check Priority Linked List: "<<endl;
    PrioList<int> abc;
    abc.append(100);
    abc.append(4);
    abc.append(212);
    abc.dspList();
    cout<<endl;
    cout<<"Find the 4 and put it to the front"<<endl;
    abc.find(4);
    abc.dspList();
    cout<<endl;
    
    //Check Priority queue
    cout<<"Check Priority queue: "<<endl;
    PrioQueue<int> pq;
    pq.append(1);
    pq.append(200);
    pq.prepend(32);
    pq.append(43);
    pq.dspList();
    cout<<endl;
    cout<<"After pop, the first element gone"<<endl;
    pq.pop();
    pq.dspList();
    cout<<endl;
    cout<<"Find the 43, and put it to the front"<<endl;
    pq.find(43);
    pq.dspList();
    cout<<endl;
    
    cout<<"Check Sort Linked List"<<endl;
    SortLnkList<int> s;
    s.append(1);
    s.append(2);
    s.append(65);
    s.append(43);
    s.append(76);
    s.append(22);
    cout<<"Before sorting..."<<endl;
    s.dspList();
    cout<<endl;
    cout<<"After Sorting..."<<endl;
    s.sort();
    s.dspList();
    
    return 0;
}

