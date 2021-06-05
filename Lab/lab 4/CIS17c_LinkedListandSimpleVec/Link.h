#ifndef LINK_H
#define	LINK_H
#include <cstdlib>
using namespace std;

template <class T>
class Link{
public:
    T data;
    Link *linkPtr;
};

#endif	/* LINK_H */