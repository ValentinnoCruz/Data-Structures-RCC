#pragma once
#include<string>

template<class T>
class RowAray {
protected:
    int size;
    T* rowData;
public:
    RowAray(int);
    virtual ~RowAray();
    int getSize()const
    { 
        return size;
    }
    T getData(int i)const {
        if (i >= 0 && i < size)
            return rowData[i];
        else return 0;
    }
    void setData(int, T);
};

/* ====================================================
         Implementation of RowAray class methods
==================================================== */

// parameterized constructor
template<class T>
RowAray<T>::RowAray(int n)
{
    // setting up the row size
    size = n;
    // Allocating memory
    rowData = new T[size];
    for (int i = 0; i < size; i++) {
        // filling data with random values
        rowData[i] = rand() % 100;

        // Uncomment the code below if you want to take input from the user
        //cin >> rowData[i];
    }
}

// Default destructor
template<class T>
RowAray<T>::~RowAray()
{
    delete[] rowData;
}

// Setter function
template<class T>
void RowAray<T>::setData(int n, T obj)
{
    rowData[n] = obj;
}