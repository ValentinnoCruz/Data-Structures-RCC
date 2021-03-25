

#ifndef TABLE_H
#define	TABLE_H

#include "Array_Rows.h"

class Table{
    private:
        int szRow;
        int szCol;
        Array_Row **records;
    public:
        Table(int,int);
        ~Table();
        int getSzRow(){return szRow;}
        int getSzCol(){return szCol;}
        int getData(int,int);
};

#endif	/* TABLE_H */
