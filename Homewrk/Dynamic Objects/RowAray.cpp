/* 
 * File:   RowAray.cpp
 * Author: Valentinno Cruz
 * 
 * Created on March 22, 2021, 11:06 AM
 */

#include "RowAray.h"
#include <cstdlib>

RowAray::RowAray( unsigned int cols ) {
	this->size = cols;
	this->rowData = new int[size];
    for( int i = 0; i < cols; i++ ){
	rowData[i] = ( rand() % 90 ) + 10;
    }
}

RowAray::~RowAray( ) {
	delete [] rowData;
}

void RowAray::setData(int index, int data ){
	this->rowData[ index ] = data;
}

