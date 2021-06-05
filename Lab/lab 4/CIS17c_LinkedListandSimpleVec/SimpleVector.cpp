
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       
#include <cstdlib>   
#include "LinkedList.h"
using namespace std;

template <class T>
class SimpleVector {
private:
    LinkedList<T> *aptr;
   int arraySize;   
   void memError();  
   void subError();  

public:
    
   // constructor
   SimpleVector()
      { aptr = NULL; arraySize = 0;}
      
   // Construct. declar.
   SimpleVector(int);
   
   //  Construct. declar. COPY
   SimpleVector(const SimpleVector &);
   
   // Destruct. declar,
   ~SimpleVector();
   
   // return the array size with Accessor
   int size() const
      { return arraySize; }

   // return a specific element with Accessor
   T getElementAt(int position);

   // Overloaded op declar.
   T &operator[](const int &);
   
   // Funct. to add 1 new value to the array
   void push_back(T);
   
   // Funct. to subtract 1 value from the array
   void pop_off();
};


// constructor for the simple vector class. will se the size of the array
// and also alloceate the mem for it. 

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arraySize = s;

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
       aptr->addEnd(NULL);
}


// Constructor copy for the simplevec. class

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
      
   // Copy the elements of obj's array.
   this->aptr(obj.aptr);
}


//Destructor for the SV class

template <class T>
SimpleVector<T>::~SimpleVector()
{
    delete aptr;
}


//Display error and terminate when memory allocation fails

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}


// display error message & terminate when subscript is out of range.

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}


//function which returns the value stores at the subscript in the array.

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   return aptr->fndLnk(sub);
}


//Function which returns a reference to the element in the array 
// indexed by the sub.

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

template <class T>
void SimpleVector<T>::push_back(T val){
    
    aptr->addEnd(val);
}

template <class T>
void SimpleVector<T>::pop_off()
{
    aptr->delEnd();
}

#endif