
#include<bits/stdc++.h>
using namespace std;
int longestSubString(string a, int k){
    int i=0,j=0;
    int maxi=INT_MIN;
    unordered_map<int, int> freq;

    while(j<a.length()){
        freq[a[j]]++;
          while(freq.size()>k){
            freq[a[i]]--;
            if(freq[a[i]]==0){
                freq.erase(a[i]);
            }
            i++;
        }

        if( freq.size()==k){
            maxi = max(maxi, j-i+1);
        }
        j++;
    }
   return (maxi==INT_MIN) ? -1 : maxi;
  
}
int main(){
    string n;
    cin>>n;
    int k;
    cin>>k;
    cout<<longestSubString(n,k);
}