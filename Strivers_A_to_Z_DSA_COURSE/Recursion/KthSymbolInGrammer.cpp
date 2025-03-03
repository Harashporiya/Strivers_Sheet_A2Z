#include<bits/stdc++.h>
using namespace std;
int kthSymbolInGrammer(int n, int k){
    if(n==1 && k==1){
        return 0;
    }

    int mid = pow(2,n-1)/2;

    if(k<=mid){
        return kthSymbolInGrammer(n-1,k);
    }else{
        return !kthSymbolInGrammer(n-1,k-mid);
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<kthSymbolInGrammer(n,k);
}