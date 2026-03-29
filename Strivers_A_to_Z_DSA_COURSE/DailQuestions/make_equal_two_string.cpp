#include<bits/stdc++.h>
using namespace std;
bool canBeEqual(string s1, string s2) {
        
        if(s1.size()!=s2.size()){
            return false;
        }

        for(int i=2;i<s1.size();i++){
            if(s1[i]!=s2[i]){
               swap(s1[i-2],s1[i]);
            }
        }

        return s1==s2;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;

    if(canBeEqual(s1,s2)){
        cout<<"True";
    }else{
        cout<<"False";
    }
}