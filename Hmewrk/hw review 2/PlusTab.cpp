/* 
 * File:   PlusTab.cpp
 * Author: Valentinno Cruz
 * 
 * Created on March 22, 2021, 11:09 AM
 */

#include "PlusTab.h"

PlusTab PlusTab::operator +(const PlusTab& right){
    PlusTab res( this->szRow, this->szCol );
	for( int i = 0; i < this->szRow; i++ ){
            for( int j = 0; j < this->szCol; j++ ){
                res.setData( i, j, ( this->getData( i, j ) + right.getData( i, j ) ) );
            }
	}
	return res;
}

