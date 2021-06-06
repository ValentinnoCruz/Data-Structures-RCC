#pragma once
#include "RowAray.h"
template<class T>
class Table {
protected:
    int szRow;
    int szCol;
    RowAray<T>** columns;
public:
    Table(unsigned int, unsigned int);
    Table(const Table<T>&);
    virtual ~Table();
    int getSzRow()const { return szRow; }
    int getSzCol()const { return szCol; }
    T getData(int, int)const;
    void setData(int, int, T);
    Table<T> operator+(const Table<T>&);
};

/* ====================================================
         Implementation of Table class methods 
==================================================== */

// Parameterised constructor
template<class T>
Table<T>::Table(unsigned int row, unsigned int col)
{
    // setting up rows and cols by casting to int
    szRow = row;
    szCol = col;
    // Allocating the memory to double pointer
    columns = new RowAray<T>*[szRow];
    T data;
    for (int i = 0; i < szRow; i++) {
        // Allocating the memory to each row of table
        columns[i] = new RowAray<T>(szCol);
        for (int j = 0; j < szCol; j++) {
            // setting the values randomly
            columns[i]->setData(j, rand() % 100);
            
            // Uncomment the code below if you want to take input from the user
            
            /*cin >> data;
            columns[i]->setData(j, data);*/
        }
    }
}

// Copy constructor
template<class T>
Table<T>::Table(const Table<T>& tab)
{
    // setting up rows and cols by casting to int
    szRow = tab.szRow;
    szCol = tab.szCol;

    // Allocating the memory to double pointer
    columns = new RowAray<T> * [szRow];
    for (int i = 0; i < szRow; i++) {
        // Allocating the memory to each row of table
        columns[i] = new RowAray<T>(szCol);
        for (int j = 0; j < szCol; j++)
            // copying the data
            columns[i]->setData(j, tab.columns[i]->getData(j));
    }
}

// default destructor
template<class T>
Table<T>::~Table()
{
    // if columns is not NULL
    if (columns != NULL) {
        //deleting columns
        delete[] columns;
    }
}

// it return data from the index i, j
template<class T>
T Table<T>::getData(int i, int j) const
{
    // checking if index is in range
    if (i < szRow && j < szCol && i >= 0 && j >= 0) {
        if (columns != NULL)
            return columns[i]->getData(j);
        else {
            // if table empty return 0
            cout << "Table is empty" << endl;
            return 0;
        }
    }
    // if index out of bound return 0
    cout << "Index out of bound" << endl;
    return 0;
}


// setter function
template<class T>
inline void Table<T>::setData(int row, int col, T data)
{
    columns[row]->setData(col, data);
}

// overloading + operator
template<class T>
Table<T> Table<T>::operator+(const Table<T>& tab)
{
    // creating a Table pointer to store result
    Table<T>* result = new Table<T>(*this);
    // adding two tables if their size are aqual
    if (szRow == tab.szRow && szCol == tab.szCol) {  
        for (int i = 0; i < szRow; i++)
            for (int j = 0; j < szCol; j++)
                result->setData(i, j, result->columns[i]->getData(j) + tab.columns[i]->getData(j));
    }
    // otherwise returning the result with the values of calling object
    cout << "Table size does not match" << endl;
    return *result;
}