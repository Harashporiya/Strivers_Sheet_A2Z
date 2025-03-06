#include<bits/stdc++.h>
using namespace std;
double maximumAverageSunbArray(vector<int>&a, int n,int k){
    int i=0,j=0;
    double maxi = INT_MIN;
    double sum=0;
    while(j<n){
        sum += a[j];
        if(j>=k-1){
         maxi=max(maxi,sum/k);
         sum -= a[i];
         i++;
        }
        j++;
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
    cout<<maximumAverageSunbArray(a,n,k);
}