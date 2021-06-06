

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
 
void quickSort(int [],int,int,int&,int&,int&,int&);
int pivot(int [],int,int,int&,int&,int&,int&);
void swap(int&,int&);
void print(int [],const int&);
void merge(int*,int,const int, const int,int&,int&,int&,int&);
void merge_sort(int*, const int, const int,int&,int&,int&,int&);
void heapsort(int [],int,int&,int&,int&,int&);
void buildheap(int [],int,int&,int&,int&,int&);
void heapify(int [],int,int,int&,int&,int&,int&);
void bubSrt(int [],int,int&,int&,int&,int&);
void selectSort(int [], int,int &,int &,int &,int &);
int *fillAry(int);

int main(){
    // Heap Sort Test result
    //when size=10 n=700
    //when size=20 n=1800
    //when size=40 n=4400
    //when size=80 n=10400
    
    //Quick Sort Test Result
    //when size=10 n=280
    //when size=20 n=800
    //when size=40 n=1900~2100
    //when size=80 n=4700~5100
    
    //Merge Sort Test Result
    //when size=10 n=300
    //when size=20 n=700
    //when size=40 n=2000
    //when size=80 n=5000
    int size;
    int eq,//Total number of equalities
        lop,//Total number of logical operations
        lsa,//Total number of add/sub operations
        add;//Total number of addressing operations
    srand(static_cast<unsigned int>(time(0)));
    cout<<"*********Quick Sort-----O( n * lgn )*********\n\n";
    for(int i=0;i<4;i++) {
        size=10*pow(2,i);
        int *test=fillAry(size);
        //Set the counters = 0
        eq=lop=lsa=add=0;
//        cout << "Size of test array: "  << size << endl;
        //cout << "Before sorting: " << endl;
    //print(test,size);
 
        quickSort(test, 0,size-1,eq,lop,lsa,add);
        //merge_sort(test, 0, N-1);
        //heapsort(test,size,eq,lop,lsa,add);

        //cout << endl << endl << "After sorting: " << endl;
        //print(test,size);
        //Find something
        cout<<"Size of the array to sort = "<<size<<endl;
        cout<<"Total number of equalities = "<<eq<<endl;
        cout<<"Total number of logical operations = "<<lop<<endl;
        cout<<"Total number of add/sub operations = "<<lsa<<endl;
        cout<<"Total number of addressing operations = "<<add<<endl;
        cout<<"----->Total number of operations = "<<eq+lop+lsa+add<<endl<<endl;

        delete []test;
    }
    
    cout<<"\n*********Merge Sort-----O( n * lgn )*********\n\n";
    for(int i=0;i<4;i++) {
        size=10*pow(2,i);
        int *test=fillAry(size);
        //Set the counters = 0
        eq=lop=lsa=add=0;
//        cout << "Size of test array: "  << size << endl;
        //cout << "Before sorting: " << endl;
    //print(test,size);
 
//        quickSort(test, 0,size-1,eq,lop,lsa,add);
        merge_sort(test, 0,size-1,eq,lop,lsa,add);
        //heapsort(test,size,eq,lop,lsa,add);

        //cout << endl << endl << "After sorting: " << endl;
        //print(test,size);
        //Find something
        cout<<"Size of the array to sort = "<<size<<endl;
        cout<<"Total number of equalities = "<<eq<<endl;
        cout<<"Total number of logical operations = "<<lop<<endl;
        cout<<"Total number of add/sub operations = "<<lsa<<endl;
        cout<<"Total number of addressing operations = "<<add<<endl;
        cout<<"----->Total number of operations = "<<eq+lop+lsa+add<<endl<<endl;

        delete []test;
    }
    
    
        cout<<"\n*********Heap Sort-----O( n * lgn )*********\n\n";
    for(int i=0;i<4;i++) {
        size=10*pow(2,i);
        int *test=fillAry(size);
        //Set the counters = 0
        eq=lop=lsa=add=0;
//        cout << "Size of test array: "  << size << endl;
        //cout << "Before sorting: " << endl;
    //print(test,size);
 
//        quickSort(test, 0,size-1,eq,lop,lsa,add);
//        merge_sort(test, 0,size-1,eq,lop,lsa,add);
        heapsort(test,size,eq,lop,lsa,add);

        //cout << endl << endl << "After sorting: " << endl;
        //print(test,size);
        //Find something
        cout<<"Size of the array to sort = "<<size<<endl;
        cout<<"Total number of equalities = "<<eq<<endl;
        cout<<"Total number of logical operations = "<<lop<<endl;
        cout<<"Total number of add/sub operations = "<<lsa<<endl;
        cout<<"Total number of addressing operations = "<<add<<endl;
        cout<<"----->Total number of operations = "<<eq+lop+lsa+add<<endl<<endl;

        delete []test;
    }
        
    cout<<"\n*********Bubble Sort-----O( n^2 )*********\n\n";
    for(int i=0;i<4;i++) {
        size=10*pow(2,i);
        int *test=fillAry(size);
        //Set the counters = 0
        eq=lop=lsa=add=0;
//        cout << "Size of test array: "  << size << endl;
        //cout << "Before sorting: " << endl;
    //print(test,size);
 
//        quickSort(test, 0,size-1,eq,lop,lsa,add);
        //merge_sort(test, 0,size-1,eq,lop,lsa,add);
        //heapsort(test,size,eq,lop,lsa,add);
        bubSrt(test,size,eq,lop,lsa,add);
        //cout << endl << endl << "After sorting: " << endl;
        //print(test,size);
        //Find something
        cout<<"Size of the array to sort = "<<size<<endl;
        cout<<"Total number of equalities = "<<eq<<endl;
        cout<<"Total number of logical operations = "<<lop<<endl;
        cout<<"Total number of add/sub operations = "<<lsa<<endl;
        cout<<"Total number of addressing operations = "<<add<<endl;
        cout<<"----->Total number of operations = "<<eq+lop+lsa+add<<endl<<endl;

        delete []test;
    }  
    
    cout<<"\n*********Selection Sort-----O( n^2 )*********\n\n";
    for(int i=0;i<4;i++) {
        size=10*pow(2,i);
        int *test=fillAry(size);
        //Set the counters = 0
        eq=lop=lsa=add=0;
//        cout << "Size of test array: "  << size << endl;
        //cout << "Before sorting: " << endl;
    //print(test,size);
 
//        quickSort(test, 0,size-1,eq,lop,lsa,add);
        //merge_sort(test, 0,size-1,eq,lop,lsa,add);
        //heapsort(test,size,eq,lop,lsa,add);
        selectSort(test,size,eq,lop,lsa,add);
        //cout << endl << endl << "After sorting: " << endl;
        //print(test,size);
        //Find something
        cout<<"Size of the array to sort = "<<size<<endl;
        cout<<"Total number of equalities = "<<eq<<endl;
        cout<<"Total number of logical operations = "<<lop<<endl;
        cout<<"Total number of add/sub operations = "<<lsa<<endl;
        cout<<"Total number of addressing operations = "<<add<<endl;
        cout<<"----->Total number of operations = "<<eq+lop+lsa+add<<endl<<endl;

        delete []test;
    }  
    
    return 0;
}
 
int *fillAry(int n) {
    int *a=new int[n];
    for(int i=0;i<n;i++) {
        a[i]=rand()%90+10;
    }
    return a;
}

/**
 * Quicksort.
 * @param a - The array to be sorted.
 * @param first - The start of the sequence to be sorted.
 * @param last - The end of the sequence to be sorted.
*/
void quickSort(int a[], int first, int last,int &eq, int &lop, int &lsa, int &add) {
    int pivotElement;
    lop++;
    if(first < last) {
        eq++;
        pivotElement = pivot(a,first,last,eq,lop,lsa,add);
        quickSort(a, first, pivotElement-1,eq,lop,lsa,add);
        quickSort(a, pivotElement+1, last,eq,lop,lsa,add);
    }
}
 
/**
 * Find and return the index of pivot element.
 * @param a - The array.
 * @param first - The start of the sequence.
 * @param last - The end of the sequence.
 * @return - the pivot element
*/
int pivot(int a[], int first, int last,int &eq, int &lop, int &lsa, int &add) {
    int  p = first;
    int pivotElement = a[first];
    eq+=2;
    add++;
    for(int i = first+1 ; i <= last ; i++) {
        lop+=2;lsa+=2;eq++;add++;
        /* If you want to sort the list in the other order, change "<=" to ">" */
        if(a[i] <= pivotElement) {
            lsa++;
            add+=2;
            eq+=3;
            p++;
            swap(a[i], a[p]);
        }
    }
    add+=2;
    eq+=3;
    swap(a[p], a[first]);
    
    return p;
}
 
 
/**
 * Swap the parameters.
 * @param a - The first parameter.
 * @param b - The second parameter.
*/
void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}
 
/**
 * Print an array.
 * @param a - The array.
 * @param N - The size of the array.
*/
void print(int a[], const int& N){
    for(int i = 0 ; i < N ; i++)
        cout << "array[" << i << "] = " << a[i] << endl;
} 

void merge(int* A,int p,const int q, const int r,int &eq, int &lop, int &lsa, int &add){
    eq+=4;
    const int n_1=q-p+1;
    const int n_2=r-q;
    int* L=new int[n_1+1];
    int* R=new int[n_2+1];
    add+=2;eq+=2;
    L[n_1]=0;
    R[n_2]=0;
    for(int i = 0; i < n_1; i++) {
        eq+=2;lsa+=2;lop++;add+=2;
        L[i] = A[p+i];
    }
    for (int j = 0; j < n_2; j++) {
        eq+=2;lsa+=2;lop++;add+=2;
        R[j] = A[q+j+1];
    }
    int i=0;
    int j=0;
    eq+=2;
    // for(int k = p; k <= r; p++)   broken code
    int k;
    for(k=p; k <= r && i < n_1 && j < n_2; ++k) {
        eq++;lsa++;lop+=4;add+=2; 
        if(L[i] <= R[j]) {
            add+=2;eq++;lsa++;
            A[k] = L[i];
            i++;
        } else {
            add+=2;eq++;lsa++;
            A[k] = R[j];
            j++;        
        }
    }
    // Added the following two loop.
    // Note only zero or one loop will actually activate.
    while (i < n_1) {
        add+=2;
        lsa+=2;
        eq++;
        lop++;
        A[k++] = L[i++];
    }
    
    while (j < n_2) {
        add+=2;
        lsa+=2;
        eq++;
        lop++;
        A[k++] = R[j++];
    }
    lop+=2;
    delete []L;
    delete []R;
}     

void merge_sort(int* A, const int p, const int r,int &eq, int &lop, int &lsa, int &add){
    lop++;
    if (p < r) {
        lsa+=2;
        eq++;
        int q = (p+r)/2;
        merge_sort(A, p,q,eq,lop,lsa,add);
        merge_sort(A,q+1,r,eq,lop,lsa,add);
        merge(A,p,q,r,eq,lop,lsa,add);
    }
}

//(takes O(n lg n) time)
void heapsort(int A[], int length,int &eq, int &lop, int &lsa, int &add) {  
    int heapsize = length;
    eq+=2;
    buildheap(A,length,eq,lop,lsa,add);	//Take the unsorted list and make it a heap
    for (int i = length-1; i >=1; i--) {
        lop++;lsa+=3;eq+=3;add+=2;
        swap(A[0], A[i]);
        heapsize--;
        heapify(A,heapsize,0,eq,lop,lsa,add);		
    }
}

//     (takes O(n) time)
void buildheap(int A[], int length,int &eq, int &lop, int &lsa, int &add) {	
        
    for(int i=floor((length)/2);i>=0;i--) {
        lop++;eq++;lsa+=2;
        heapify(A,length,i,eq,lop,lsa,add);
    }
}

//(takes O(h) h is the height of root
void heapify(int A[], int heapsize, int root,int &eq, int &lop, int &lsa, int &add) {
    
    int left=2*root+1, 
        right=2*root+2,
        largest;
    eq+=3;
    lsa+=4;
    lop+=2;add+=2;
    if ((left < heapsize)&&(A[left]>A[root])) {
        largest = left;
    } else {
        largest = root;
    }
    add+=2;
    lop+=2;
    if ((right < heapsize)&&(A[right] > A[largest])) {
        largest = right;
        eq++;
    }
    lop++;
    if (largest != root) {
        add+=2;
        eq+=3;
        swap(A[root], A[largest]);
        heapify(A, heapsize, largest,eq,lop,lsa,add);
    }
}

void bubSrt(int a[],int n,int &eq, int &lop, int &lsa, int &add) {
    //Set the counters = 0
    eq=lop=lsa=add=0;
    eq++;
    bool swap;
    do {
        eq++;
        swap=false;
        lsa++;eq++;
        for(int i=0;i<n-1;i++) {
        lop+=2;lsa+=3;add+=2;    
            if(a[i]>a[i+1]) {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swap=true;
                add+=4;
                eq+=4;
            }
        }
        
    }while(swap);
}

void selectSort(int arr[], int n,int &eq, int &lop, int &lsa, int &add) {
    //pos_min is short for position of min
    int pos_min,temp;

    for (int i=0; i < n-1; i++) {
        eq+=2;
        lop++;
        lsa+=2;
        pos_min = i;//set pos_min to the current index of array
        for (int j=i+1; j < n; j++) {
            eq++;
            lop++;
            lsa+=2;
            add+=2;
            lop++;
            if (arr[j] < arr[pos_min]) {
               eq++;
               pos_min=j;
            }
        //pos_min will keep track of the index that min is in, this is needed when a swap happens
        }

        //if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
        lop++;
        if (pos_min != i) {
            eq+=3;
            add+=3;
             temp = arr[i];
             arr[i] = arr[pos_min];
             arr[pos_min] = temp;
        }
    }
}