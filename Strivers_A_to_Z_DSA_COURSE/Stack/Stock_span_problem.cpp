#include<bits/stdc++.h>
using namespace std;
vector<int> stockSpanProblem(vector<int> & a, int n){
     vector<int> v;
     vector<int> ans;
     stack<pair<int, int>> s;
     for(int i=0;i<n;i++){
        if(s.size()==0){
            v.push_back(-1);
        }else if(s.size()>0 && s.top().first>a[i]){
            v.push_back(s.top().second);
        }else if(s.size()>0 && s.top().first<=a[i]){
            while(s.size()>0 && s.top().first<=a[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(-1);
            }else{
                v.push_back(s.top().second);
            }
        }
        

        s.push({a[i],i});
        ans.push_back(i-v[i]);
     }
     return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
   vector<int> ans = stockSpanProblem(a,n);
   for(auto it:ans){
    cout<<it<<" ";
   }
}