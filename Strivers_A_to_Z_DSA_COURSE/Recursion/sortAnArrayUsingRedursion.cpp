#include<bits/stdc++.h>
using namespace std;
void insert(vector<int> &a, int value){
    if(a.size()==0 || a[a.size()-1]<=value){
        a.push_back(value);
        return;
    }

    int temp = a[a.size()-1];
    a.pop_back();
    insert(a,value);
    a.push_back(temp);

}
void sort(vector<int>&a){
    int n = a.size();
  if(n==1){
    return;
  }
  int value = a[n-1];
  a.pop_back();
  sort(a);
  insert(a,value);
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}