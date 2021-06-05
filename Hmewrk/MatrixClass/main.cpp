

#include <iostream>
using namespace std;

#include "Matrix.h"

int main(int argc, char** argv) {
    Matrix<float> first(5);
    first.pntAray();
    cout<<endl<<endl;
    Matrix<int> second(11);
    second.pntAray();
    return 0;
}

