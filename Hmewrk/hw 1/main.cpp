/* 
 * File:   Main.cpp
 * Author: Valentinno Cruz
 * * CIS 17C - Triangular Matrix
 */

//User Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

//User Libraries
#include "Table.h"
#include "Triangle.h"

//Global Constants

//Function Prototype
void prntRow(Array_Row *,int);
void prntTab(Table *);
void Triprnt_out(Triangle *);

//Execution Begins Here!
int main(int argc, char** argv) {
   //Initialize the random seed
   srand(static_cast<unsigned int>(time(0)));
   
   //Declare Variables
   int rows=6,cols=8,perLine=cols/2;
   
   //Testing the Array Row
   Array_Row row(cols);
    
   //Print the array row
   cout<<"The Row Array size = "<<row.getSize()
           <<" printed "<<perLine<<" per Line";

   prntRow(&row,perLine);
   
   //Testing the table
   Table tab(rows,cols);
   
   //Printing out the table
   cout<<"The table size is [row,col] = ["<<rows<<","<<cols<<"]";
   prntTab(&tab);
   
   //Testing out the triangular tablee
   Triangle tri(rows);
   
   //output the triangular table
   cout<<"The trangular table size is [row,row] = ["<<rows<<","<<rows<<"]";
   Triprnt_out(&tri);

   //Exit Stage Right
   return 0;
}

void prntRow(Array_Row *a,int perLine){
    cout<<endl;
    for(int i=0;i<a->getSize();i++){
        cout<<a->getData(i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void prntTab(Table *a){
    cout<<endl;
    for(int row=0;row<a->getSzRow();row++){
        for(int col=0;col<a->getSzCol();col++){
            cout<<a->getData(row,col)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Triprnt_out(Triangle *a){
    cout<<endl;
    for(int row=0;row<a->getSzRow();row++){
        for(int col=0;col<=row;col++){
            cout<<a->getData(row,col)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
