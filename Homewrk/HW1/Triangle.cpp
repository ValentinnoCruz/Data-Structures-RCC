/* 
 * File:   Array_Rows.cpp
 * Author: Valentinno Cruz
 * * CIS 17C - Triangular Matrix
 */


#include "Triangle.h"
#include <cstdlib>

Triangle::Triangle(int rows) {
    this->szRow = rows > 0 ? rows : 1;
    
    records = new Array_Row*[this->szRow];
    
    for (int i = 0; i < this->szRow; i++) {
        records[i] = new Array_Row(i + 1);
    }
}

Triangle::~Triangle() {
    for (int i = 0; i < this->szRow; i++) {
        delete records[i];
    }
    delete [] records;
}

int Triangle::getData(int rows, int cols) {
    if (rows >= 0 && rows < this->szRow && cols >= 0 && cols < records[rows]->getSize()) {
        return records[rows]->getData(cols);
    }
    else {
        return 0;
    }
}
