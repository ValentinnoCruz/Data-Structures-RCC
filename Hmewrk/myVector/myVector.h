

#ifndef AVECTOR_H
#define	AVECTOR_H

#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class MyVector {
    private:
       T *aptr;          // To point to the allocated array
       int actSize;      // Actual Size of the array
       int usdSize;      // Number of elements in the array
       void memError();  // Handles memory allocation errors
       void subError();  // Handles subscripts out of range
       
    public:
       //Default constructor
       MyVector();
       T *getPtr() const {return aptr;}
       // Constructor declaration
       MyVector(int);
       
       // Copy constructor declaration
       MyVector(const MyVector &);

       // Destructor declaration
       ~MyVector();

       // Accessor to return the array size
       int size() const { return usdSize; }

       // Accessor to return a specific element
       T getElementAt(int position);

       // Overloaded [] operator declaration
       T &operator[](const int &);
       void push(T);
       void pull();
       void clear();
       void sort();
};

template <class T>
MyVector<T>::MyVector() {
    actSize = 1;
    usdSize = 0;
    aptr=new T[actSize];
    *aptr=0;
}

// Constructor with size argument
template <class T>
MyVector<T>::MyVector(int s) {
   usdSize = 0;
   actSize = 2*s;
   // Allocate memory for the array.
   try {
      aptr = new T[actSize];
   } catch (bad_alloc) {
      memError();
   }
   
   // Initialize the array.
   for (int count=0;count<actSize;count++)
      aptr[count] = 0;
}


// Copy Constructor for MyVector class. 
template <class T>
MyVector<T>::MyVector(const MyVector &obj) {
   // Copy the array size.
   actSize=obj.actSize;
   usdSize=obj.usdSize;
   // Allocate memory for the array.
   aptr = new T[actSize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of object's array.
   for(int count = 0; count < obj.usdSize; count++)
      aptr[count]= obj.aptr[count];
   for(int i=usdSize;i<actSize;i++)
       aptr[i]=0;
}   

// Destructor
template <class T>
MyVector<T>::~MyVector() {
    delete []aptr;
}

//Sort
template <class T>
void MyVector<T>::sort() {
    for(int i=0;i<usdSize-1;i++) {
        for(int j=i+1;j<usdSize;j++) {
            if(aptr[i]>aptr[j]) {
                T temp=aptr[i];
                aptr[i]=aptr[j];
                aptr[j]=temp;
            }
        }
    }
}

//Clear
template <class T>
void MyVector<T>::clear() {
    for(int i=0;i<usdSize;i++) {
        aptr[i]=0;
    }
    usdSize=0;
}

//push function
template <class T>
void MyVector<T>::push(T o) {
    if(usdSize>=actSize) {
        actSize*=2;
        T *arr=new T[actSize];
        if(arr==0) memError();
        for(int i=0;i<usdSize;i++) {
            arr[i]=aptr[i];
        }
        for(int i=usdSize;i<actSize;i++) {
            arr[i]=0;
        }
        arr[usdSize]=o;
        usdSize++;
        delete []aptr;
        aptr=arr;
    } else {
       aptr[usdSize]=o;
       usdSize++;
    }
}

template <class T>
void MyVector<T>::pull() {
    if(usdSize==0) {
        subError();
    } else {
        T* arr=new T[actSize];
        if(arr==0) memError();
        for(int i=0;i<usdSize-1;i++) {
            arr[i]=aptr[i];
        }
        for(int i=usdSize-1;i<actSize;i++) {
            arr[i]=0;
        }
        usdSize--;
        delete []aptr;
        aptr=arr;
    }
}

// memError function. Displays an error message and    
// terminates the program when memory allocation fails. 
template <class T>
void MyVector<T>::memError() {
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

// subError function. Displays an error message and         
// terminates the program when a subscript is out of range. 
template <class T>
void MyVector<T>::subError() {
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

// getElementAt function. The argument is a subscript.  
// This function returns the value stored at the subscript   
// in the array.                                  
template <class T>
T MyVector<T>::getElementAt(int sub) {
   if (sub<0||sub>=usdSize)
      subError();
   return *(aptr+sub);
}


// Overloaded [] operator. The argument is an integer
// This function returns a reference to the element     
// in the array indexed by the integer.
template <class T>
T &MyVector<T>::operator[](const int &sub) {
   if (sub < 0 || sub >= usdSize)
      subError();
   return aptr[sub];
}


#endif