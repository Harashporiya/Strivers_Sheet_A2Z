#include<bits/stdc++.h>
using namespace std;
int countPrimes(int n){
    vector<bool> isPrime(n,true);
    isPrime[0]=isPrime[1] =false;
    
    int cnt=0;
    for(int i=2;i*i<n;i++){
       if(isPrime[i]){
         for(int j=i*i;j<n;j+=i){
            isPrime[j]=false;
        }
       }
    }
    for(int i=2;i<n;i++){
          if(isPrime[i]){
            cnt++;
        }
    }
    return cnt;
}
int main(){
    int n;
    cin>>n;
    cout<<countPrimes(n);
}