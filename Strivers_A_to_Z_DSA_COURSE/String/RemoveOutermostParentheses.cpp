#include<bits/stdc++.h>
using namespace std;
string removeOuterMost(string str){
  int count=0;
  string ans="";
  for(int i=0;i<str.size();i++){
    if(str[i]=='('){
        if(count>0){
        ans+="(";
    }
        count++;
    }else if(str[i]==')'){
         if(count>1){
        ans+=")";
    }
        count--;
    }
     
   
  }
  
    return ans;
}
int main(){
    string str;
    cin>>str;
   cout<<removeOuterMost(str);
}