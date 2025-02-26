#include<bits/stdc++.h>
using namespace std;
bool checkPalindrom(string str){
    stack<char> st;
    for(auto  it:str){
        if(isalnum(it)){
            st.push(tolower(it));
        }
    }

    for(int i=0;i<str.length();i++){
        if(isalnum(str[i])){
            if(tolower(str[i])!=st.top()){
                return false;
            }else{
                st.pop();
            }
        }
    }
    return true;
}
int main(){
    string str;
    getline(cin,str);
    
    if(checkPalindrom(str)){
        cout<<"yes";
    }else{
        cout<<"No";
    }
}