#include <iostream>
#include <cstdlib>
#include <iostream>
#include <typeinfo>
using namespace std;



template<class T>
class SimpleVector
{
    private:
        // the vector itself
        T *aptr;
        // the capacity of the vector.
        unsigned int cap;
        // actual size of the vector.
        unsigned int sz; 
    
    public:
    /*
        Constructors
    */
    SimpleVector();
    SimpleVector(unsigned size);
    SimpleVector(unsigned size, T value);
    
    //destruct
    ~SimpleVector(); 
    
    /* 
        Get the priv cap and sz of the vector
    */
    unsigned size() const;
    unsigned capcity() const;
    void push_back(T);
    void pop_back();
    void pop_front();
    void insert(unsigned, T);
    void print() const;
    
    private:
    void expand();
    
        
    
};

template<class T>
SimpleVector<T> :: SimpleVector()
{
    cap = 0;
    sz = 0;
    aptr = 0;
}


// if the val is not give, then we sign 0 to each individual 
//...element in the vector

template<class T>
SimpleVector<T> :: SimpleVector(unsigned size)
{
    sz = size;
    cap = size;
    aptr = new T[cap];
    for(unsigned i = 0; i < cap; i++)
    {
        aptr[i] = 0;
    }
}

template<class T>
SimpleVector<T> :: SimpleVector(unsigned size, T value)
{
    sz = size;
    cap = size;
    aptr = new T[cap];
    for(unsigned i = 0; i < cap; i++)
    {
        aptr[i] = value;
    }
}

template<class T>
unsigned SimpleVector<T> :: size() const
{
    return sz;
}

template<class T>
unsigned SimpleVector<T> :: capcity() const
{
    return cap;
}

template<class T>
SimpleVector<T> :: ~SimpleVector()
{
    delete [] aptr;
}

template<class T>
void SimpleVector<T> :: expand()
{
    cout << "expand called..." << endl;
    cap += 1;
    T *a = new T[cap];
    for(unsigned i = 0; i < sz; i++)
    {
        a[i] = aptr[i];
    }
    delete [] aptr;
    aptr = a;
}

template<class T>
void SimpleVector<T> :: print() const
{
    cout << "Vector Type:" << typeid(T).name() << endl;
    for(unsigned i = 0; i < sz; i++)
    {
        cout << aptr[i] << " ";
    }
    cout << endl;
}

template<class T>
void SimpleVector<T> :: push_back(T a)
{
    cout << "Push_back called..." << endl;
    sz = sz + 1;
    if(sz >= cap) expand();
    aptr[sz - 1] = a;
}

template<class T>
void SimpleVector<T> :: pop_back()
{
    cout << "pop_back..." << endl;
    if(sz == 0) exit(0);
    sz--;
}

template<class T>
void SimpleVector<T> :: pop_front()
{
    cout << "Pop_front called..." << endl;
    if(sz == 0) exit(0);
    for(unsigned i = 0; i + 1 < sz ;i++)
    {
        aptr[i] = aptr[i + 1];
    }
    sz--;
    
}

template<class T>
void SimpleVector<T> :: insert(unsigned index, T value)
{
    cout << "insert called..." << endl;
    sz++;
    if(sz >= cap) expand();
    for(unsigned i = sz; i > index; i--)
    {
        aptr[i] = aptr[i - 1];
    }
    aptr[index] = value;
}