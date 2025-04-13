#include<bits/stdc++.h>
using namespace std;
int prefixEvalute(string exp){
    stack<int> st;
    for(int i=exp.length()-1;i>=0;i--){
        if(isdigit(exp[i])){
            st.push(exp[i] - '0');
        }else{
            int op1 = st.top();st.pop();
            int op2 = st.top();st.pop();
            if(exp[i] == '+'){
                st.push(op1+op2);
            }else if(exp[i] == '-'){
                st.push(op1-op2);
            }else if(exp[i] == '*'){
                st.push(op1*op2);
            }else if(exp[i] == '/'){
                st.push(op1/op2);
            }else if(exp[i] == '^'){
                st.push(pow(op1,op2));
            }
        }
    }
    return st.top();
}
int main(){
    string prefix;
    cin>>prefix;

    cout<<prefixEvalute(prefix);
}
