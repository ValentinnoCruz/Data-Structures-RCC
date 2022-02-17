



//System Libraries
#include <cstdlib>
#include <iostream>
#include "LnkdLst.h"
#include "StLnkdLst.h"

using namespace std;

int main(int argc, char** argv) {
    //Sorted linked list
    cout<<"------Sorted Linked List------"<<endl;
    int index=0;
    LnkdLst<int> link(10);
    index++;
    link.append(4);
    index++;
    link.append(25);
    index++;
    cout<<link.toString()<<endl;
    link.sort(index);
    cout<<link.toString()<<endl;
    //Stack using linked list
    cout<<"------Using Stacks on Linked List------"<<endl;
    StLnkdLst stack;
    stack.push(25);
    stack.push(23);
    stack.push(14);
    stack.push(13);
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();


    return 0;
}

