/* 
 * File:   Array_Rows.cpp
 * Author: Valentinno Cruz
 * * CIS 17C - Triangular Matrix
 */

#include "Array_Rows.h"
#include <cstdlib>

Array_Row::Array_Row(int cols) {
    size = cols > 1 ? cols : 1;
    
    rowData = new int[size];
    
    for (int i = 0; i < size; i++) {
        rowData[i] = rand()%90+10;
    }
}

Array_Row::~Array_Row() {
    delete [] rowData;
}
