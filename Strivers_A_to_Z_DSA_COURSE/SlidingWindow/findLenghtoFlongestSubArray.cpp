//Find length of the longest subarray containing atmost two distinct integers
#include<bits/stdc++.h>
using namespace std;
int findLongestSubArray(vector<int>& a, int n){
    int i=0, j=0;
    int maxi=0;
    unordered_map<int, int> freq;
    while(j<n){
        freq[a[j]]++;
        while(freq.size()>2){
           freq[a[i]]--;
            if(freq[a[i]]==0){
                freq.erase(a[i]);
            }
            i++;
        }
        maxi=max(maxi,j-i+1);
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
    cout<<findLongestSubArray(a,n);
}