

#ifndef ROWARAY_H
#define	ROWARAY_H

class Array_Row{
    private:
        int size;
        int *rowData;
    public:
        Array_Row(int);
        ~Array_Row();
        int getSize(){return size;}
        int getData(int i){return rowData[i];}
};

#endif	/* ROWARAY_H */
