#include<bits/stdc++.h>
using namespace std;
int postfixEvalute(string exp){
    stack<int> st;
    for(char ch:exp){
        if(isdigit(ch)){
            st.push(ch - '0');
        }else{
            int op1 = st.top();st.pop();
            int op2 = st.top();st.pop();
            if(ch == '+'){
                st.push(op2+op1);
            }else if(ch == '-'){
                st.push(op2-op1);
            }else if(ch == '*'){
                st.push(op2*op1);
            }else if(ch == '/'){
                st.push(op2/op1);
            }else if(ch == '^'){
                st.push(pow(op2,op1));
            }
        }
    }
    return st.top();
}
int main(){
    string postfix;
    cin>>postfix;

    cout<<postfixEvalute(postfix);
}
