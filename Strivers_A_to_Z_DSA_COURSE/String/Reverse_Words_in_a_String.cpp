#include<bits/stdc++.h>
using namespace std;
string reverseWord(string str){

   int left=0;
   int right=str.length()-1;

   string temp="";
   string ans="";
   while(left<=right){
       char ch = str[left];
       if( ch != ' '){
        temp+=ch;
       }else if(ch == ' '){
         if(ans!=""){
          ans = temp + " " + ans;
         }else{
            ans=temp;
         }
         temp="";
       }
       left++;
   }
   if(temp!=""){
    if(ans!=""){
        ans=temp + " "+ans;

    }else{
        ans=temp;
    }
   }
   return ans;
}
int main(){
    string str;
    cin.ignore();
    getline(cin, str);
    cout<<reverseWord(str);
}