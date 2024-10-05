#include<bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);
    int maxLen=0;
    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            st.push(i);
        }else if(s[i] == ')'){
            st.pop();
            if(st.size()==0){
                st.push(i);
            }else{
                maxLen = max(maxLen, i-st.top());
            }
        }
    }
    return maxLen;

}

int main() {
    string s;
    cin >> s;
    int ans = longestValidParentheses(s);
    cout << ans << endl;
    return 0;
}
