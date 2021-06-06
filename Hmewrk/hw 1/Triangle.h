
#ifndef TRIANGLE_H
#define	TRIANGLE_H

#include "Array_Rows.h"

class Triangle{
    private:
        int szRow;
        Array_Row **records;
    public:
        Triangle(int);
        ~Triangle();
        int getSzRow(){return szRow;}
        int getData(int, int);
};


#endif	/* TRIANGLE_H */
