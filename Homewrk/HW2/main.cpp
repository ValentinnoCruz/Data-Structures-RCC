
// System Libraries
#include <iostream>
#include <cstdlib>

// User Libraries
#include "SimpleVector.h"

using namespace std;

int main(int argc, const char * argv[]) {
    const int SIZE = 10;
    SimpleVector<int> simple(SIZE);
    
    //*******************************
    // The following, until the end *
    // is for testing functionality *
    //*******************************
    
    cout << "Original Size: " << simple.size() << endl;;
    simple.print();
    cout << endl;
    
    // push/pop some elemtents
    simple.push(rand()%100+1);
    simple.push(rand()%100+1);
    simple.pop();
    simple.push(rand()%100+1);
    
    cout << "New Size after pushing/popping: " << simple.size() << endl;
    simple.print();
    cout << endl;

    // pop an element off
    cout << "Element popped: " <<  simple.pop() << endl;
    cout << "Size after popping: " << simple.size() << endl;
    
    simple.print();
    cout << endl;
    
    return 0;
}
