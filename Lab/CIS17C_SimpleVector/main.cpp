

#include<iostream>
#include "SimpleVector.h"

using namespace std;

int main()
{
    cout << "Hello World" << endl;
    SimpleVector<int> a(10, 1);
    SimpleVector<float> b(10, 0.22);
    a.print();
    b.print();
    cout << endl;
    
    a.push_back(100);
    a.print();
    a.pop_back();
    a.print();
    a.pop_front();
    a.print();
    a.insert(3, 4);
    a.print();
    return 0;
}