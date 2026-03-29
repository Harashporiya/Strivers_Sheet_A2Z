#include<bits/stdc++.h>
using namespace std;
int firstMatchingIndex(string s) {

        for(int i=0;i<s.size();i++){
            if(s[i]==s[s.size()-i-1]){
                return i;
            }
        }
        return -1;
}
int main(){
   string s;
   cin>>s;

   cout<<firstMatchingIndex(s);
}