

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

    // function for Permutation without replacement
    ll permutation(ll n,ll r){
       ll res=1;
         // loop from n-r+1 to n because n!/(n-r)!
        for(int i=(n-r)+1;i<=n;i++){
                   res=res*i;
              }
       return res;
    }

    // function for Permutation with replacement
    ll P_with_rep(ll n ,ll  r){
      ll res=1;

     // n^r
      for(int i=0;i<r;i++){
        res=res*n;
      }

      return res;
    }

    // function for Combination without replacement
    ll combination(ll n,ll r){
      ll res=1;

      res=permutation(n,r);
      for(int i=1;i<=r;i++)
         res=res/i;

      return res;
    }

    // function for Combination with replacement
    ll C_with_rep(ll n,ll r){
       ll res = 1;

       res = permutation(n+r-1,r);
       for(int i=1;i<=r;i++)
          res=res/i;

       return res;
    }

int main(){
  cout<<"Enter Values for N & M \n";
  ll n,m;
  cin>>n>>m;

  cout <<"P-> Permutation( order Matters )"<<endl;
  cout <<"C-> Combination(Order does not matter)"<<endl;
  cout <<"Rep -> with replacement "<<endl;
  cout <<"no Rep -> no replacement"<<endl;
  cout <<"N -> Number of total elements"<<endl;
  cout <<"M -> Number of elements to take from the total \n"<<endl;

  cout <<"_______________________________________________________________\n";
  cout <<"N   M   P Rep   P no Rep   C Rep   C no Rep "<<endl;
  cout << n <<"   "<<m<<"   " << P_with_rep(n,m) << "     "<<permutation(n,m)<<"     "
            <<combination(n,m)<< "       " <<C_with_rep(n,m)<<"\n";

}