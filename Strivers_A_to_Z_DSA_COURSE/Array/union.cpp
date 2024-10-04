#include<iostream>
#include<vector>
#include<set>
using namespace std;
// vector<int> movedZeroLast(vector<int>& a,vector<int>& b, int n){
//   set<int> st;
//   vector<int> res;
//   for(int i=0;i<n;i++){
//     st.insert(a[i]);
//   }
//   for(int i=0;i<n;i++){
//     st.insert(b[i]);
//   }
//   for(auto it:st){
//     res.push_back(it);
//   }
//   return res;
  
// }
vector<int> unionUnique(vector<int> &a, vector<int> &b, int n, int m){
  vector<int> v;
  int i=0,j=0;
  while(i<n && j<m){
    if(a[i]<b[j]){
      if(v.size()==0 || v.back()!=a[i]){
        v.push_back(a[i]);
        
      }
      i++;
    }else{
      if(v.size()==0 || v.back()!=b[j]){
        v.push_back(b[j]);
        
      }
      j++;
    }
  }
  while(i<n){
    if(v.back()!=a[i]){
       v.push_back(a[i]);
       
    }
     i++;
  }
  while(j<m){
     if(v.back()!=b[j]){
       v.push_back(b[j]);
       
    }
     j++;
  }
  return v;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    vector<int> arr = unionUnique(a,b,n,m);
    for(auto it:arr){
        cout<<it<<" ";
    }
}