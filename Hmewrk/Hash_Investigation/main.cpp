
//System Libraries
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <ctime>
#include <sstream>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

//user libraries
#include "GeneralHashFunctions.h"

//Execution Begins here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Create a message
    string msg="What a difference a day makes!";
    cout<<"The base message = "<<msg<<endl;
    
    vector<unsigned int> vec; //vector to store the result of hash
    set<unsigned int> s; //set to store the result of hash
    map<int,unsigned int> range;    //get the frequency of different range
    unsigned int n=10;//number of loops
    unsigned int fstColl=0;//first collision
//    unsigned int ttColl;//total collision
    bool hasColl=false;//has collision
    unsigned int res;//result of hash function  
    
    //Record the start time
    int strTime=time(0);
    //initial the map
    for(int j=9;j>=0;j--) {
        range.insert(make_pair(j,0));
    }
    
    //Loop until you have reached the number of size
    for(int hash=1;hash<12;hash++) {
        switch(hash) {
            case 1:cout<<endl<<"------------RSHash------------"<<endl; break;
            case 2:cout<<endl<<"------------JSHash------------"<<endl; break;
            case 3:cout<<endl<<"------------PJWHash------------"<<endl; break;
            case 4:cout<<endl<<"------------ELFHash------------"<<endl; break;
            case 5:cout<<endl<<"------------BKDRHash------------"<<endl; break;
            case 6:cout<<endl<<"------------SDBMHash------------"<<endl; break;
            case 7:cout<<endl<<"------------DJBHash------------"<<endl; break;
            case 8:cout<<endl<<"------------DEKHash------------"<<endl; break;
            case 9:cout<<endl<<"------------BPHash------------"<<endl; break;
            case 10:cout<<endl<<"------------FNVHash------------"<<endl; break;
            case 11:cout<<endl<<"------------APHash------------"<<endl; break;
            default:;
        }
        for(int j=n;j<pow(10,4);j*=10) {
            
        
            map<unsigned int, unsigned int> test;
            fstColl=0;
            hasColl=false;
            s.clear();
            vec.clear();
            for(int i=0;i<10;i++) {
                range[i]=0;
            }


            //Choose a random number
            unsigned int randNum=rand();
            cout<<"The initial random number = "<<randNum<<endl;

            for(unsigned int i=1;i<=j;i++) {
                ostringstream convert;   // stream used for the conversion
                convert << randNum++;      // insert the textual representation of 'Number' in the characters in the stream
                string strRnd = convert.str();
                string newMsg=msg+strRnd;
                //use hash function
                switch(hash) {
                    case 1:res=RSHash(newMsg)%j; break;
                    case 2:res=JSHash(newMsg)%j; break;
                    case 3:res=PJWHash(newMsg)%j; break;
                    case 4:res=ELFHash(newMsg)%j; break;
                    case 5:res=BKDRHash(newMsg)%j; break;
                    case 6:res=SDBMHash(newMsg)%j; break;
                    case 7:res=DJBHash(newMsg)%j; break;
                    case 8:res=DEKHash(newMsg)%j; break;
                    case 9:res=BPHash(newMsg)%j; break;
                    case 10:res=FNVHash(newMsg)%j; break;
                    case 11:res=APHash(newMsg)%j; break;
                    default:;
                }


                //insert the result of hash to set
                if(s.insert(res).second){
                    test[res]=0;
                }
                vec.push_back(res);
                range[static_cast<int>(log10(res))]++;

                if((!hasColl)&&(s.size()!=vec.size())) {
                    fstColl=i;
                    hasColl=true;
//                    cout<<"Has 1111"<<endl;
                } 
            }
            for(int i=0;i<vec.size();i++){
                test[vec[i]]++;
            }
            //print out result
    //        prntRes(range,9);
                cout<<"Range      Frequency"<<endl;
            for(int k=9;k>=0;k--) {
                cout<<"10^"<<k<<"-10^"<<(k+1)<<": "<<range[k]<<endl;
            }  
    //        ttColl=n-s.size();
    //        cout<<"Total collision: "<<ttColl<<endl;
            cout<<"First collision at i = "<<fstColl<<endl;

            //Take the time it took
            int endTime=time(0);
            //Output the result
            cout<<"Size of set = "<<s.size()<<endl;
            cout<<"Size of vec = "<<vec.size()<<endl;
            cout<<"The time since running program = "<<endTime-strTime<<" (secs)"<<endl;
            map<unsigned int, unsigned int>::iterator iter=test.begin();
            int max=0;
            for(;iter!=test.end();iter++){
    //            cout<<iter->first<<" "<<iter->second<<endl;
                if(iter->second>max) max = iter->second;
            }
            if(max>1) {
                cout<<"There are "<<max<<" collision"<<endl<<endl;
            } else {
                cout<<"There is no collision"<<endl<<endl;
            }
        }
//        cout<<max<<endl;
    }

    //Exit stage right
    return 0;
}
