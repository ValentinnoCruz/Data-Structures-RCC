

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
    //set seeds for random numbers
    srand(static_cast<unsigned int>(time(0)));
    int n=50;//number of elements
    int pl=10;//per line
    vector<int> vec;
    set<int> s;
    set<int>::iterator pos;//iterator for set
    int temp;
    float ave=0;//average
    float median=0;//median
    map<int,int> m;
    //insert and output random 2-digit number into vector
    //insert these number to the set
    cout<<"Here are "<<n<<" integers: "<<endl;
    for(int i=0;i<n;i++) {
        temp=rand()%10;
//        temp=rand()%10;
        cout<<temp<<" ";
        if(i%pl==(pl-1)) cout<<endl;
        ave+=temp;
        vec.push_back(temp);
        //when inserting to set successfully, put the elements in sets and set value to 0
        if(s.insert(temp).second) m.insert(pair<int, int>(temp, 0));
    }
    cout<<endl<<endl;
    //sort the vector
    sort(vec.begin(),vec.end());
   
    //get the average
    ave/=n;
    //Get the median
    if(n%2==1) {
        median=vec[n/2];
    } else {
        median=(vec[n/2]+vec[n/2-1])/2.0f;
    }
    cout<<"After sorting: "<<endl;
    
    //output the elements in vector after sorting
    for(int i=0;i<vec.size();i++) {
        m[vec[i]]++;
        cout<<vec[i]<<" ";
        if(i%pl==(pl-1)) cout<<endl;
    }
    cout<<endl<<endl;
    
    set<int> mode;
    int times=0;
    //Output the frequency
    cout<<"Frequency"<<endl;
    cout<<"Key   Value"<<endl;
    int ones=0;
    for(pos=s.begin();pos!=s.end();pos++) {
        cout<<*pos<<"     "<<m[*pos]<<endl;
        //Get the mode from the map
        if(m[*pos]>times) {
            mode.clear();
            mode.insert(*pos);
            times=m[*pos];
        } 
        if(m[*pos]==times) {
            mode.insert(*pos);
        }
        if(m[*pos]==1) {
            ones++;
        }
    }
    
    //Output the result
    cout<<"Average: "<<ave<<endl;
    cout<<"Median: "<<median<<endl;
    if(ones==s.size()) {
        cout<<"There is no mode"<<endl;
    } else {
        cout<<"Mode: ";
        for(pos=mode.begin();pos!=mode.end();++pos) {
            cout<<*pos<<"  ";
        }
    }
    cout<<endl;
    return 0;
}

