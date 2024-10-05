#include<bits/stdc++.h>
using namespace std;
int findNthRoot(int m,int n){
    for(int i=0;i<=m;i++){
           if(pow(i,n)==m){
            return i;
           }else if(pow(i,n)>m){
            break;
           }
    }
    return -1;
}
int main(){
    int n,m;
    cin>>n>>m;
    int ans =findNthRoot(m,n);
    cout<<ans;
}
