#include<bits/stdc++.h>
using namespace std;
int powerOfThree(int n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }

    return (n%3==0) && powerOfThree(n/3);
}
int main(){
    int n;
    cin>>n;
    cout<<powerOfThree(n);
}