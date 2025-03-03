#include<bits/stdc++.h>
using namespace std;
void slove(stack<int> &s, int k){
    if(k==1){
        s.pop();
        return;
    }
    int temp=s.top();
    s.pop();
    slove(s,k-1);
    s.push(temp);
}
stack<int> middleDel(stack<int> &s, int size){
    if(s.size()==0){
     return s;
    }
    int k = (size/2) + 1;
   slove(s,k);
   return s;
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
    middleDel(st,n);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}