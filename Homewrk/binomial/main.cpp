#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>


using namespace std;
int biased();

int main () {
    biased();
    srand(time(NULL));
int count=0;
    for(int i=0;i<10000;i++)
{
    int sum=0;
    for(int j=0;j<4;j++)
{
        
    int num=rand()%2;
    sum=sum+num;
}
    
    if(sum==1)
    count++;
}

cout<<"Result from simulation is "<<(double)count/(double)10000;

return 0;
}

int biased()
{
    srand(time(NULL));
    int count=0;
    for(int i=0;i<10000;i++)
    {
        int sum=0;
        for(int j=0;j<4;j++)
    {
    double n=(double)rand()/(double)RAND_MAX;
    int num=0;
        if(n<=0.4)
        num=1;
        sum=sum+num;
}

    if(sum==3)
    count++;
}
    
cout<<"Result from simulation(biased) is "<<(double)count/(double)10000<<endl;
}