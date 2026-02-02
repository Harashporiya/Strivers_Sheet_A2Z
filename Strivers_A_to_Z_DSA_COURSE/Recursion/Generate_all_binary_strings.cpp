#include <bits/stdc++.h>
using namespace std;

void f(string s, vector<string>& ans, int n) {
    if (s.size() == n) {
        ans.push_back(s);
        return;
    }

    f(s + '0', ans, n);
    f(s + '1', ans, n);
}

vector<string> generateString(int n) {
    vector<string> ans;
    f("", ans, n);
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<string> ans = generateString(n);

    for (auto &x : ans) {
        cout << x << " ";
    }
}
