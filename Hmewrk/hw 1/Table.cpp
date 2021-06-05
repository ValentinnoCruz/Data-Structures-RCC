/* 
 * File:   Table.cpp
 * Author: Valentinno Cruz
 * * CIS 17C - Triangular Matrix
 */

#include "Table.h"
#include <cstdlib>

Table::Table(int rows, int cols) {
    this->szRow = rows > 0 ? rows : 1;
    
    records = new Array_Row*[this->szRow];
    
    this->szCol = cols > 0 ? cols : 1;
    
    for (int i = 0; i < this->szRow; i++) {
        records[i] = new Array_Row(this->szCol);
    }
}

Table::~Table() {
    for (int i = 0; i < this->szRow; i++) {
        delete records[i];
    }
    delete [] records;
}

int Table::getData(int rows, int cols) {
    if (rows >= 0 && rows < this->szRow && cols >= 0 && cols < records[rows]->getSize()) {
        return records[rows]->getData(cols);
    }
    else {
        return 0;
    }
}
