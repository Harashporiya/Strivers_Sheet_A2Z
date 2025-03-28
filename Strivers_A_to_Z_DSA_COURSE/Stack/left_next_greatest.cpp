#include<bits/stdc++.h>
using namespace std;
vector<int> leftNextgreatest(vector<int> & a, int n){
     vector<int> v;
     stack<int> s;
    for(int i=0;i<n;i++){
        if(s.empty()){
            v.push_back(-1);
        }else if(s.size()>0 && s.top()>a[i]){
            v.push_back(s.top());
        }else if(s.size()>0 && s.top()<=a[i]){
            while(s.size()>0 && s.top()<=a[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(-1);
            }else{
                v.push_back(s.top());
            }
        }
        s.push(a[i]);
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
   vector<int> ans = leftNextgreatest(a,n);
   for(auto it:ans){
    cout<<it<<" ";
   }
}