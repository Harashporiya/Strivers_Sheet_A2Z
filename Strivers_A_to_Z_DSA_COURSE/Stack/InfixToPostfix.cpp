#include<bits/stdc++.h>
using namespace std;
int precdence(char ch){
    if(ch=='^'){
        return 3;
    }
    else if(ch=='*' || ch=='/'){
        return 2;
    }else if(ch=='-'||ch=='+'){
        return 1;
    }
    return -1;
}

string infixToPostfix(string str){
    stack<char> st;
    string postfix;
    for(char ch : str){
      if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
        postfix+=ch;
      }else if(ch=='('){
       st.push('(');
      }else if(ch==')'){
        while(st.top()!='('){
            postfix+=st.top();
            st.pop();
        }
        st.pop();
      }else{
        while(!st.empty() && precdence(ch)<=precdence(st.top())){
         postfix+=st.top();
         st.pop();
        }
        st.push(ch);
      }
    }
    while(!st.empty()){
        postfix+=st.top();
        st.pop();
    }
    return postfix;
}
int main(){
    string str;
    cin>>str;

    cout<<infixToPostfix(str);
}