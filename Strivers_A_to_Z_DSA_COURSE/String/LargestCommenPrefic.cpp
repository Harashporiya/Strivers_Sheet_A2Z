#include<bits/stdc++.h>
using namespace std;
 string longestCommonPrefix(vector<string>& strs) {
         int n=strs.size();
       string ans="";

       if(strs.empty()){
        return "";
       }

       int minLength=strs[0].length();
       for(const string& str:strs){
        if(str.length()<minLength){
            minLength=str.length();
        }
       }

       for(int i=0;i<minLength;i++){
        char currentChar = strs[0][i];

        for(int j=1;j<n;j++){
            if(strs[j][i]!=currentChar){
                return ans;
            }
        }
        ans+=currentChar;
       }
       return ans;
    }
int main(){
    int n;
    cin>>n;
    vector<string> str(n);
    for(int i=0;i<n;i++){
        cin>>str[i];
    }

   cout<<longestCommonPrefix(str);
    
}