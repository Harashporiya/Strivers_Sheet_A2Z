#include<bits/stdc++.h>
using namespace std;
int numberOfSubString(string s){
    int i=0,j=0;
    unordered_map<char, int> freq({{'a',0},{'b',0},{'c',0}});
     int maxi=0; 
    while(j<s.length()){
      freq[s[j]]++;
      while(freq['a']>0 && freq['b'] > 0 && freq['c']>0){
        maxi += s.length() - j;
        freq[s[i]]--;
        i++;
      }
      j++;
    }
    return maxi;
}
int main(){
    string s;
    cin>>s;
    cout<<numberOfSubString(s);
}