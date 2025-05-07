//Maximum Sum of Distinct Subarrays With Length K
#include<bits/stdc++.h>
using namespace std;
int maxiumSumOfSubarray(vector<int> &a, int n, int k){
    int i=0,j=0;
    int sum=0;
    int maxi=INT_MIN;
    unordered_map<int, int> freq;

    while(j<n){
        sum += a[j];
        freq[a[j]]++;

          while(j-i+1>k){
            sum-=a[i];
            freq[a[i]]--;
            if(freq[a[i]]==0){
                freq.erase(a[i]);
            }
            i++;
        }

        if(j-i+1==k && freq.size()==k){
            maxi = max(maxi, sum);
        }
        j++;
    }
   return (maxi==INT_MIN) ? 0 : maxi;
  
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
    cout<<maxiumSumOfSubarray(a,n,k);
}