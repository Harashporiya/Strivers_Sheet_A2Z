#include<bits/stdc++.h>
using namespace std;
bool isPlanidromic(int st,int et,string s){

    while(st<=et){
        if(s[st]!=s[et]){
            return false;
        }
        st++;
        et--;
    }
    return true;
}
void f(int i,string s,vector<string>&v,vector<vector<string>>&ans){
    if(i==s.size()){
        ans.push_back(v);
        return;
    }


    for(int ind=i;ind<s.size();ind++){
        if(isPlanidromic(i,ind,s)){
            v.push_back(s.substr(i,ind-i+1));
            f(ind+1,s,v,ans);
            v.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
      vector<vector<string>> ans;
      vector<string> v;
      f(0,s,v,ans);
      return ans;  
}
int main(){
    string s;
    cin>>s;

    vector<vector<string>>ans= partition(s);
    for(int i=0;i<ans.size();i++){
        cout<<"[";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]";
    }
}