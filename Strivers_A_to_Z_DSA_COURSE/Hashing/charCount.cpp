#include<iostream>
using namespace std;
int main(){
    string n;
    cin>>n;
   

    // precompute
    int hash[256] = {0};
    for(int i=0;i<n.size();i++){
        hash[n[i]]+=1;
    }
    int q;
    cin>>q;
    while(q--){
        char number;
        cin>>number;
        // fetch
        cout<<hash[number]<<endl;
    }
}