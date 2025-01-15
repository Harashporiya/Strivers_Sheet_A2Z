#include <bits/stdc++.h>
using namespace std;

vector<int> productOfArraySelf(vector<int>& a, int n) {
    int zeroCount = 0;
    int product = 1;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            zeroCount++;
        } else {
            product *= a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (zeroCount > 1) {
            ans[i] = 0; 
        } else if (zeroCount == 1) {
            ans[i] = (a[i] == 0) ? product : 0;
        } else {
            ans[i] = product / a[i];
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans = productOfArraySelf(a, n);
    for (auto it : ans) {
        cout << it << " ";
    }
    return 0;
}
