#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    // precompute
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[a[i]]++;
    }
    // // iterate int the map
    // for(auto it: mpp){
    //     cout<<it.first<<" -> "<<it.second<<endl;
    // }
    // int q;
    // cin>>q;
    // while(q--){
    //     // int number;
    //     // cin>>number;
    //     // fetch
    //     cout<<mpp[q]<<endl;
    // }
    int P;
    cin>>P;
     for(int i=1;i<=P;i++){
           cout<<mpp[i]<<" ";
       }
}