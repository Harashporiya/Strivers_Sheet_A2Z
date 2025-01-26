#include <bits/stdc++.h>
using namespace std;

int precedence(char ch) {
    if (ch == '^') {
        return 3;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    }
    return -1;
}
string infixToPrefix(string s) {
    string prefix;
    stack<char> st;

    for (char ch : s) {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            prefix += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                prefix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); 
        }
        else {
            while (!st.empty() && precedence(ch) <= precedence(st.top())) {
                prefix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

 
    while (!st.empty()) {
        prefix += st.top();
        st.pop();
    }

    return prefix;
}
string reverseString(string s) {
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            s[i] = ')';
        } else if (s[i] == ')') {
            s[i] = '(';
        }
    }

  
    string prefix = infixToPrefix(s);

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    string str;
    cout << "Enter infix expression: ";
    cin >> str;

    cout << "Prefix expression: " << reverseString(str) << endl;
    return 0;
}
