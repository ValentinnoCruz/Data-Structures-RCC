

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

#include "Tree.h"

int main(int argc, char** argv) {
    //set seed
    srand(static_cast<unsigned int>(time(0)));
    vector<int> vec;
    Tree t;
    //insert random number and store them into vector and tree
    for(int i=0;i<10;i++) {
        int temp=rand()%90+10;
        cout<<"Insert "<<temp<<" to tree"<<endl;
        t.insert(temp);
        vec.push_back(temp);
    }
    //Traversing the tree
    cout<<endl;
    cout<<"Traversing the tree: "<<endl;
    t.inPnt();
    t.prePnt();
    t.postPnt();
    cout<<endl;
    //randomly select 5 elements from vector, and delete this number from the tree
    for(int i=0;i<5;i++) {
        int temp=vec[rand()%vec.size()];
        cout<<"Delete "<<temp<<" from the tree"<<endl;
        t.dele(temp);
    }
    //Traversing the tree again
    cout<<endl;
    cout<<"Traversing the tree: "<<endl;
    t.inPnt();
    t.prePnt();
    t.postPnt();
    return 0;
}

