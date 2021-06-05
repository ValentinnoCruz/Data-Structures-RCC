


#include "StLnkdLst.h"

StLnkdLst::StLnkdLst() {
    top=NULL;
}

StLnkdLst::StLnkdLst(const StLnkdLst&) {
    
}

void StLnkdLst::push(int n){
    worker=new Node;
    if(worker==NULL){
        cout<<"- Stack is Full"<<endl;
    }
    worker->data=n;
    worker->next=top;
    top=worker;
}

void StLnkdLst::pop(){
    if(top==NULL){
        cout<<"- Stack Empty"<<endl;
        return;
    }
    int n;
    worker=top;
    n=worker->data;
    top=top->next;
    cout<<worker->data<<endl;
}

StLnkdLst::~StLnkdLst() {
    if(top=NULL)return;
    while(top!=NULL){
        worker=top;
        top=top->next;
        delete worker;
    }
}

