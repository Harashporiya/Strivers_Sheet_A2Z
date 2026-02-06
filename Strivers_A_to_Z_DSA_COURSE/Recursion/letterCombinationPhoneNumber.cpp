#include<bits/stdc++.h>
using namespace std;
void f(int ind,string s,vector<string>&ans,vector<string>&com,string digits){
     if(ind==digits.size()){
        ans.push_back(s);
        return;
     }

     int d=digits[ind]-'0';

     for(int i=0;i<com[d].size();i++){
        f(ind+1,s+com[d][i],ans,com,digits);
     }
}
vector<string> letterCombinations(string digits) {
        vector<string> com={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string s;
        f(0,s,ans,com,digits);
        return ans;
}
int main(){
    string str;
    cin>>str;

    vector<string>ans = letterCombinations(str);
    // cout<<ans.size();
        for(int i=0;i<ans.size();i++){
       cout<<ans[i]<<" ";
    }
}