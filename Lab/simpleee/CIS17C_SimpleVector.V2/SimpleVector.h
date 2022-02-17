
#ifndef SimpleVector_SimpleVector_h
#define SimpleVector_SimpleVector_h

//SimpleVector Class Template

#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
    T *aptr;          // To point to the allocated array
    int current;      // points to one past last element pushed
    int arraySize;    // Number of elements in the array
    void memError();  // Handles memory allocation errors
    void subError();  // Handles subscripts out of range
    
    void create(int); // create a SimpleVector
    void expand();    // double the size of the SimpleVector
    
public:
    // Default constructor
    SimpleVector()
    { aptr = 0; arraySize = 0; current=0;}
    
    // Constructor declaration
    SimpleVector(int);
    
    // Copy constructor declaration
    SimpleVector(const SimpleVector &);
    
    // Destructor declaration
    ~SimpleVector();
    
    // Accessor to return the array size
    int size() const
    { return current; } // changed from arraySize
    
    // Accessor to return a specific element
    T getElementAt(int position);
    
    // Overloaded [] operator declaration
    T &operator[](const int &);
    
    // Pushes new element onto array
    void push(int);
    
    // Remove an element from array
    T pop();
    
    void print() const;
    
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
    create(s);
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
    // Copy the array size.
    arraySize = obj.arraySize;
    current = obj.current; // added by me
    
    // Allocate memory for the array.
    aptr = new T [arraySize];
    if (aptr == 0)
        memError();
    
    // Copy the elements of obj's array.
    for(int count = 0; count < arraySize; count++)
        *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
    if (arraySize > 0)
        delete [] aptr;
}

//************************
// Create a SimpleVector *
//************************

template<class T>
void SimpleVector<T>::create(int s) {
    arraySize = s;
    current = s; // added by me
    // Allocate memory for the array.
    try
    {
        aptr = new T [s];
    }
    catch (bad_alloc)
    {
        memError();
    }
    
    // Initialize the array.
    for (int count = 0; count < arraySize; count++)
        *(aptr + count) = 0;
}

//*************************************************
// expand Function. Doubles the size of the array *
//*************************************************

template<class T>
void SimpleVector<T>::expand() {
    // temporary SimpleArray that holds a copy of the original array
    SimpleVector<T> temp = *this;
    
    create(temp.size()*2); // create a new array with double the size
    
    // copy the elements over
    for (int i = 0; i != temp.size(); ++i) {
        *(aptr + i) = temp[i];
    }
    
    // move the current index back to original position
    current /= 2;
}

//*******************************************************
// push Function. add a new element to end of array     *
// double the size of array if size of array is reached *
//*******************************************************

template <class T>
void SimpleVector<T>::push(int n) {
    // check you're not past the last element
    if (current == arraySize){
        expand();
    }
    // push the new element
    *(aptr+current) = n;
    ++current;
}

//*****************************************
// pop Function. Remove the last element *
//*****************************************

template <class T>
T SimpleVector<T>::pop() {
    --current;
    
    // attempting to pop from empty array
    if (current < 0) {
        subError();
    }

    // elements available to pop
    T popped = *(aptr+current);
    return popped;
}

//***************************************************************
// print Funtion. Print elements until the last pushed element  *
//***************************************************************

template <class T>
void SimpleVector<T>::print() const {
    for (int i = 0; i != current; ++i) {
        cout << *(aptr+i) << " ";
    }
    cout << endl;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
    cout << "ERROR:Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
    cout << "ERROR: Subscript out of range.\n";
    exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

#endif
