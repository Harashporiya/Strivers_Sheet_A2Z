#include<bits/stdc++.h>
using namespace std;
int countSumOfNiceSubArray(vector<int> &a, int n, int k){
    int i=0,j=0;
    int count=0;
    int ans=0;
    int countSubArray=0;
    while(j<n){
        if(a[j]%2!=0){
            count++;
        }
        while(count>k){
            if(a[i]%2!=0){
                count--;
            }
            i++;
        }
         if(count==k){
              while(i<n && a[i]%2==0){
                countSubArray++;
                i++;
            }
            
            ans+=(countSubArray+1);
        }
        j++;
    }
    return ans;
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

    cout<<countSumOfNiceSubArray(a,n,k);
}