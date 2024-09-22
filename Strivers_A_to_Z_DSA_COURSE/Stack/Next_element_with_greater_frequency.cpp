#include<bits/stdc++.h>
using namespace std;
vector<int> rightNextGreatestFrequency(vector<int> & a, int n){
     vector<int> v;
     stack<int> s;
     unordered_map<int, int>mpp;
     for(int i=0;i<n;i++){
        mpp[a[i]]++;
     } 
     for(int i=n-1;i>=0;i--){
        if(s.size()==0){
            v.push_back(-1);
        }else if(s.size()>0 && mpp[a[s.top()]]>mpp[a[i]]){
            v.push_back(a[s.top()]);
        }else if(s.size()>0 && mpp[a[s.top()]]<=mpp[a[i]]){
            while(s.size()>0 && mpp[a[s.top()]]<=mpp[a[i]]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(-1);
            }else{
                v.push_back(a[s.top()]);
            }
        }
        s.push(i);
     }
     reverse(v.begin(), v.end());
     return v;
     
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
   vector<int> ans = rightNextGreatestFrequency(a,n);
   for(auto it:ans){
    cout<<it<<" ";
   }
}