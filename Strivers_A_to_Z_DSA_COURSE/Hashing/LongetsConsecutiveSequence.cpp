#include<bits/stdc++.h>
using namespace std;
int longestConsecutiveSequence(vector<int> &a, int n){
    unordered_set<int> s(a.begin(), a.end());
    int maxLength=0;

    for(int num:s){
        if(s.find(num-1)==s.end()){
            int cur = num;
            int count=1;
            while(s.find(cur+1)!=s.end()){
                cur++;
                count++;
            }
            maxLength = max(maxLength, count);
        }
    }
    return   maxLength;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<longestConsecutiveSequence(a,n);
}