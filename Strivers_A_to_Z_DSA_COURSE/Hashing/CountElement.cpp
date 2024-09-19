#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    // precompute
    int hash[100000] = {0};
    for(int i=0;i<n;i++){
        hash[a[i]]+=1;
    }
    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        // fetch
        cout<<hash[number]<<endl;
    }
}