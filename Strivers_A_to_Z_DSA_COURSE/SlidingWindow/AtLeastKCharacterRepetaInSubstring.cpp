#include<bits/stdc++.h>
using namespace std;
int longestSubString(string s, int k){
    int i=0,j=0;
    int maxi=INT_MIN;
    unordered_map<char, int> freq;

    while(j<s.length()){
        freq[s[j]]++;
        if( freq[s[j]]>=k){
            maxi = max(maxi, j-i+1);
        }
           
           if(freq[s[i]]<k){
            while(i<s.length() && freq[s[i]]<k){
            freq[s[i]]--;
             if(freq[s[i]]==0){
               freq.erase(s[i]);
             }
             i++;
           }
           }
        j++;
    }
   return (maxi==INT_MIN) ? 0 : maxi;
  
}
int main(){
    string n;
    cin>>n;
    int k;
    cin>>k;
    cout<<longestSubString(n,k);
}