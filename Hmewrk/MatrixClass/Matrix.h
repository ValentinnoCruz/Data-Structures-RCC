

#ifndef MATRIX_H
#define	MATRIX_H

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class Matrix {
    private:
        int **d2ary;
        int *d1ary;
        int nCols;
        void filAry(int);
    public:
        Matrix();
        Matrix(int);
        ~Matrix();
        void pntAray();
};

//Default Constructor
template <class T>
Matrix<T>::Matrix() { }

//Constructor
template <class T>
Matrix<T>::Matrix(int n) {
    srand(static_cast<unsigned int>(time(0)));
    filAry(n);
}

//Destructor
template <class T>
Matrix<T>::~Matrix() {
    delete []d1ary;
    for(int i=0;i<nCols;i++) {
        delete []d2ary[i];
    }
    delete []d2ary;
}

template <class T>
void Matrix<T>::pntAray() {
    //1-d array
    cout<<endl;
    for(int i=0;i<nCols;i++) {
        cout<<d1ary[i]<<" ";
    }
    cout<<endl;
    //2-d array
    cout<<endl;
    //fill the allocate memory
    for(int row=0;row<nCols;row++) {
        for(int col=0;col<d1ary[row];col++) {
            cout<<d2ary[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl; 
}

//fill 1-d array
template <class T>
void Matrix<T>::filAry(int n) {
    nCols=n;
    d1ary=new int[nCols];
    for(int i=0;i<nCols;i++) {
        d1ary[i]=i+1;
    }
    d2ary=new int*[nCols];
    for(int i=0;i<nCols;i++){
        d2ary[i]=new int[d1ary[i]];
    }
    //Fill the allocated memory
    for(int row=0;row<nCols;row++){
        for(int col=0;col<d1ary[row];col++){
            d2ary[row][col]=rand()%90+10;
        }
    }
}
#endif	/* MATRIX_H */

