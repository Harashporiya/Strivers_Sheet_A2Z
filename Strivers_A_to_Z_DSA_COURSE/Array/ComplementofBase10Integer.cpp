#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> res;
    while(n>0){
      int binFrom=n;
      if(binFrom%2==1){
         res.push_back(1);
      }else{
        res.push_back(0);
      }
      n/=2;
    }
     for(auto it = res.rbegin();it!=res.rend();it++){
        cout<<*it;
    }
    cout<<endl;
     for(auto it = res.rbegin();it!=res.rend();it++){
        cout<<(*it ==1 ? 0:1);
    }
    cout<<endl;
    int count=0;
    for(auto it = res.rbegin();it!=res.rend();it++){
       if(*it ==1 ? 0:1){
        count++;
       }
    } 
    cout<<count;
    
    return 0;
}