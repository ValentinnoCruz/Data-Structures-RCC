
//System Libraries
#include <iostream>
using namespace std;

//User libraries
#include "myVector.h"

int main(int argc, char** argv) {
    //call constructor
    MyVector<int> cc;
    
    //output the size
    cout<<"Original Size: "<<cc.size()<<endl<<endl;
    //push some number to it
    for(int i=0;i<20;i++) {
        cc.push(i);
    }
    //output the size again
    cout<<"After pushing..."<<endl;
    cout<<"Size: "<<cc.size()<<endl<<endl;
    cout<<"Here are all the elements: "<<endl;
    //output all the elements in the MyVector
    for(int i=0;i<cc.size();i++) {
        cout<<cc.getElementAt(i)<<endl;
    }
    
    cout<<endl<<endl;
    //pull out some elements
    for(int i=0;i<5;i++) {
        cc.pull();
    }
    cout<<"After pulling..."<<endl;
    cout<<"Size: "<<cc.size()<<endl<<endl;
    //output all the elements again
    cout<<"Here are all the elements: "<<endl;
    for(int i=0;i<cc.size();i++) {
        cout<<cc.getElementAt(i)<<endl;
    }
    cout<<endl<<"Copying MyVector..."<<endl;
    MyVector<int> dd(cc);
    cout<<"Size of copy: "<<dd.size()<<endl;
    for(int i=0;i<dd.size();i++) {
        cout<<dd.getElementAt(i)<<endl;
    }
    return 0;
}

