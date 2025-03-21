#include<bits/stdc++.h>
using namespace std;
int powerOfFour(int n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }

    return (n%4==0) && powerOfFour(n/4);
}
int main(){
    int n;
    cin>>n;
    cout<<powerOfFour(n);
}