#include<bits/stdc++.h>
using namespace std;
string postfixToInfix(string s){
    stack<string> st;
    for(char ch:s){
        if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||(ch>='0'&&ch<='9')){
            st.push(string(1,ch));
        }else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string result = '(' + t2 +ch+t1+')';
            st.push(result);
        }
    }
    return st.top();
}
int main(){
    string str;
    cin>>str;
    cout<<postfixToInfix(str);
}