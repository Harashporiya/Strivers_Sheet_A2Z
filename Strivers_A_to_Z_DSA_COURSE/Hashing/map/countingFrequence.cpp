#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,p;
    cin>>n>>p;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int, int> mpp;
    for(int i=0;i<n;i++){
        mpp[a[i]]++;
    }

    for(int i=1;i<=p;i++){
        if(mpp.find(i)!=mpp.end()){
            cout<<mpp[i]<<" ";
        }else{
            cout<<"0 ";
        }
    }

}