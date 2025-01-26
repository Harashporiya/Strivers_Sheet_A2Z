#include<bits/stdc++.h>
using namespace std;
string prefixToInfix(string s){
    stack<string> st;
    for(int i=s.size()-1;i>=0;i--){
        if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
            st.push(string(1,s[i]));
        }else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string result = '(' + t1 +s[i]+t2+')';
            st.push(result);
        }
    }
    return st.top();
}
int main(){
    string str;
    cin>>str;
    cout<<prefixToInfix(str);
}