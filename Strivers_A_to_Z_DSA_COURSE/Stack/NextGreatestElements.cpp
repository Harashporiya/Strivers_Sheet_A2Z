#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreatestElements(vector<int> &a){
   
    stack<int> s;
    int n=a.size();
     vector<int> v(n,-1);
    for(int i=2*n-1;i>=0;i--){
        while(!s.empty() && s.top()<=a[i%n]){
            s.pop();
        }
6
        if(i<n){
            if(!s.empty()) v[i]=s.top();
        }
        s.push(a[i%n]);
    }
    return v;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int> ans=nextGreatestElements(a);
    for(auto it:ans){
        cout<<it<<" ";
    }
}