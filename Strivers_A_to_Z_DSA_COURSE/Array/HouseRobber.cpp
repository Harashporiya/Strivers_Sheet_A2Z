#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

\
    int evenSum=0;
    int oddSum=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
           evenSum+=a[i];
        }else if(i%2!=0){
          oddSum+=a[i];
        }
    }

    if(evenSum>oddSum){
        cout<<evenSum;
    }else{
        cout<<oddSum;
    }
}