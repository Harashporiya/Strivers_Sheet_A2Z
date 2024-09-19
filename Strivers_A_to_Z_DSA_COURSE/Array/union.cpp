#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int> movedZeroLast(vector<int>& a,vector<int>& b, int n){
  set<int> st;
  vector<int> res;
  for(int i=0;i<n;i++){
    st.insert(a[i]);
  }
  for(int i=0;i<n;i++){
    st.insert(b[i]);
  }
  for(auto it:st){
    res.push_back(it);
  }
  return res;
  
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<int> arr = movedZeroLast(a,b,n);
    for(auto it:arr){
        cout<<it<<" ";
    }
}