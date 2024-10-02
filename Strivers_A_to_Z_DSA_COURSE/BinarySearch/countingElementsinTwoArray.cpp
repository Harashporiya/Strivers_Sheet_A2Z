

// Brute solution
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int a1[m],a2[n];
    for(int i=0;i<m;i++){
        cin>>a1[i];
    }
    for(int i=0;i<n;i++){
        cin>>a2[i];
    }
    
    vector<int> ans;
    for(int i=0;i<m;i++){
        int count=0;
        for(int j=0;j<n;j++){
          if(a1[i]>=a2[j]){
            count++;
           
          }
          
        }
         ans.push_back(count);
    }
    
    
    for(auto it:ans){
        cout<<it<<" ";
    }
}