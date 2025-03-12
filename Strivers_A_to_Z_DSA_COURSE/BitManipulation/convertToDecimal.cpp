#include<bits/stdc++.h>
using namespace std;
int convertToDecimal(string n){
    int sum=0;
    int n1=n.length()-1;
    int p =1;

    for(int i=n.length()-1;i>=0;i--){
      if(n[i]=='1'){
       sum+=p;
      }
      p*=2;
    }
    return sum;
}
int main(){
    string n;
    cin>>n;
    cout<<convertToDecimal(n);
}