#include<bits/stdc++.h>
using namespace std;
int f(int i,int j,string s1,string s2){
    int n=s1.size();
    int m=s2.size();

    if(i==n){
        int s=0;
        for(int k=j;k<m;k++){
            s+=s2[k];
        }
        return s;
    }

    if(j==m){
        int s=0;
        for(int k=i;k<n;k++){
            s+=s1[k];
        }
        return s;
    }

    if(s1[i]==s2[j]){
        return f(i+1,j+1,s1,s2);
    }

    int d1=s1[i]+f(i+1,j,s1,s2);
    int d2=s2[j]+f(i,j+1,s1,s2);

    return min(d1,d2);
}
int minimumDeleteSum(string s1,string s2){
    return f(0,0,s1,s2);
}
int main(){
    string s1="sea";
    string s2="eat";

    cout<<minimumDeleteSum(s1,s2);
}