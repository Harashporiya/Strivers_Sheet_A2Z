#include<bits/stdc++.h>
using namespace std;
string largestOddNumber(string str){
    string ans="";
     int right=str.length()-1;
     while(right>=0){
        char ch = str[right];
        if(ch%2!=0){
            for(int i=0;i<=right;i++){
              ans+=str[i];
            }
            return ans;
        }
        right--;
     }
     return ans;
}
int main(){
    string str;
    cin>>str;
    cout<<largestOddNumber(str);
}