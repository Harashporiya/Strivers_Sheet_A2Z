#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s,int i,int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int mcm(string s,int i,int j){
    if(i>=j)return 0;
    if(isPalindrome(s,i,j))return 0;
     int mini=0;
    for(int k=i;k<=j-1;k++){
        int ans = 1+mcm(s,i,k)+mcm(s,k+1,j);
        mini=min(mini,ans);
    }

    return mini;
}
int main(){
    string s;
    cin>>s;
    cout<<mcm(s,0,s.length()-1);
}