#include<bits/stdc++.h>
using namespace std;
string convertBinary(int n){
    string res;
    while(n!=0){
        if(n%2==1){
            res+="1";
        }else{
            res+="0";
        }
        n/=2;
    }
      reverse(res.begin(), res.end());
    return res;
}
int main(){
    int n;
    cin>>n;
    cout<<convertBinary(n);
}