#include<bits/stdc++.h>
using namespace std;
void insert(stack<int> &s, int value){
    if(s.size()==0 ){
       s.push(value);
       return;
    }

    int t=s.top();
    s.pop();
    insert(s,value);
    s.push(t);
}
void reverse(stack<int>& s){
  if(s.size()==1){
    return;
  }
  int value = s.top();
  s.pop();
  reverse(s);
  insert(s,value);
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(auto it:a){
        st.push(it);
    }
    reverse(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}