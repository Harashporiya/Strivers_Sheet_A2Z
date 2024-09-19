#include<iostream>
#include<map>
using namespace std;
int main(){
    string n;
    cin>>n;
   

    // precompute
    map<char,int> mpp;
    for(int i=0;i<n.size();i++){
      mpp[n[i]]++;
    }
    for(auto it:mpp){
        cout<<it.first<<" -> "<<it.second<<endl;
    }
    // int q;
    // cin>>q;
    // while(q--){
    //     char number;
    //     cin>>number;
    //     // fetch
    //     cout<<hash[number]<<endl;
    // }
}