#include <bits/stdc++.h>
using namespace std;

void f(int open,int close,string s, vector<string>& ans, int n) {
    if (s.size() == 2*n) {
        ans.push_back(s);
        return;
    }

    if(open<n){
        f(open+1,close,s+'(',ans,n);
    }

    if(open>close){
        f(open,close+1,s+')',ans,n);
    }
}

vector<string> paranthesis(int n) {
    vector<string> ans;
    f(0,0,"", ans, n);
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<string> ans = paranthesis(n);

    for (auto &x : ans) {
        cout << x << " ";
    }
}
