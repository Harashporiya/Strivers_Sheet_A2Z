#include<bits/stdc++.h>
using namespace std;
int powerOfTwo(int n){
    // return (n > 0) && ((n & (n - 1)) == 0);
     if(n==0){
            return 0;
        }else if(n==1){
            return 1;
        }

        return (n%2==0) && powerOfTwo(n/2);
}
int main(){
    int n;
    cin>>n;
    cout<<powerOfTwo(n);
}