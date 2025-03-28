// Longest Repeating Character Replacement
#include<bits/stdc++.h>
using namespace std;
int longestRepeatingCharacterReplacement(string s, int k){
    int maxi=0;
    int i=0,j=0; int maxFreq = 0;
    unordered_map<char, int> freq;
    while(j<s.length()){
         freq[s[j]]++;
          maxFreq = max(maxFreq, freq[s[j]]);
         while((j-i+1 - maxFreq) > k ){
            freq[s[i]]--;
           i++;
         }
        maxi=max(maxi, j-i+1);
        j++;
    }
    return maxi;
}
int main(){
    string str;
    cin>>str;

    int k;
    cin>>k;
    cout<<longestRepeatingCharacterReplacement(str,k);
}