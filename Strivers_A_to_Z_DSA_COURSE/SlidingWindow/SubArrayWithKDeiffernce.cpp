//Subarrays with K Different Integers
#include<bits/stdc++.h>
using namespace std;
int countAtMostK(vector<int>& a, int n, int k){
    int i=0, j=0;
    int maxi=0;
    unordered_map<int, int> freq;
    while(j<n){
        freq[a[j]]++;
        while(freq.size()>k){
            freq[a[i]]--;
            if(freq[a[i]]==0){
                freq.erase(a[i]);
            }
            i++;
        }
        maxi+=j-i+1;
        j++;
    }
    return maxi;
}
int findLongestSubArray(vector<int> &a, int n , int k){
    return countAtMostK(a,n,k) - countAtMostK(a,n,k-1);
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
    cout<<findLongestSubArray(a,n,k);
}