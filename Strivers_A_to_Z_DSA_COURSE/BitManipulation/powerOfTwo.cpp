#include<bits/stdc++.h>
using namespace std;
int powerOfTwo(int n){
    return (n > 0) && ((n & (n - 1)) == 0);
}
int main(){
    int n;
    cin>>n;
    cout<<powerOfTwo(n);
}