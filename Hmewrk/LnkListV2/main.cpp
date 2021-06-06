
//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "LnkList.h"

int main(int argc, char** argv) {
    //Call constructor
    LnkList<int> a;
    //append 4 numbers to the list
    a.append(4);
    a.append(10);
    a.append(10);
    a.prepend(100);
    a.insertAfter(8,4);
    cout<<a[0]<<endl;
    //output the list after appending
    cout<<"After appending..."<<endl;
    cout<<"Linked List A: "<<endl;
    a.dspList();
    //output the size
    cout<<"Now, size of A is "<<a.getSize()<<endl;
    
    
    cout<<endl<<endl;
    //extract
    a.extr(10);
    //output the list after appending
    cout<<"After extract 10..."<<endl;
    cout<<"Linked List A: "<<endl;
    a.dspList();
    //output the size
    cout<<"Now, size of A is "<<a.getSize()<<endl;
    //output the first value
    cout<<"First Value of A: "<<a[0]<<endl;
    
    //prepend 2
    a.prepend(2);
    cout<<"After prepending 2..."<<endl;
    cout<<"Linked List A: "<<endl;
    a.dspList();
    
    //copy List A to B
    cout<<endl<<endl<<"Copy List a to b..."<<endl;
    LnkList<int> b(a);
    
    //insert number 200 before number 4
    cout<<"In b list, insert 200 before 4..."<<endl;
    b.insertBefore(200,4);
    b.append(50000);
    cout<<"Linked List B: "<<endl;
    b.dspList();

//    b.dspList();
    return 0;
}

