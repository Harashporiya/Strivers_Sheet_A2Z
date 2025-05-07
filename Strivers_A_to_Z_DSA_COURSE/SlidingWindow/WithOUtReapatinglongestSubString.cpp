#include<bits/stdc++.h>
using namespace std;
int longestSubString(string s){
    int i=0,j=0;
    int maxi=INT_MIN;
    unordered_map<char, int> freq;
    int count=0;
    while(j<s.length()){
        freq[s[j]]++;
        count++;
        if( freq.size()==count){
            maxi = max(maxi, j-i+1);
        }else{
            while(freq.size()<count){
                freq[s[i]]--;
                count--;
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
    cout<<longestSubString(n);
}