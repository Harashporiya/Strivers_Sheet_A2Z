//Maximum Points You Can Obtain from Cards
#include<bits/stdc++.h>
using namespace std;
int maximumCardPoints(vector<int> &a, int n, int k){
    // int i=0,j=0;
    int sum = 0;
    // while(j<n){
    //   sum += a[i];
    //   if(j-i+1 > k){

    //   }
    // }

    for(int i=0;i<k;i++){
        sum += a[i];
    }
     int maxi=sum;
    for(int i=0;i<k;i++){
        sum -= a[k - i - 1];
        sum += a[n - i - 1];
         maxi = max(maxi,sum);
    }
   

    return maxi;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int k;
    cin>>k;

    cout<<maximumCardPoints(a,n,k);
}