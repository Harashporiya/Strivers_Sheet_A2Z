#include<bits/stdc++.h>
using namespace std;

vector<int> leftNextSmollest(vector<int> &a, int n) {
    vector<int> left;
    int psudoIndex = -1;
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        if (s.size() == 0) {
            left.push_back(psudoIndex);
        } else if (s.size() > 0 && s.top().first < a[i]) {
            left.push_back(s.top().second);
        } else if (s.size() > 0 && s.top().first >= a[i]) {
            while (s.size() > 0 && s.top().first >= a[i]) {
                s.pop();
            }
            if (s.size() == 0) {
                left.push_back(psudoIndex);
            } else {
                left.push_back(s.top().second);
            }
        }
        s.push({a[i], i});
    }
    return left;
}

vector<int> rightNextSmollest(vector<int> &a, int n) {
    vector<int> right;
    int psudoIndex = n;
    stack<pair<int, int>> s;
    for (int i = n - 1; i >= 0; i--) {
        if (s.size() == 0) {
            right.push_back(psudoIndex);
        } else if (s.size() > 0 && s.top().first < a[i]) {
            right.push_back(s.top().second);
        } else if (s.size() > 0 && s.top().first >= a[i]) {
            while (s.size() > 0 && s.top().first >= a[i]) {
                s.pop();
            }
            if (s.size() == 0) {
                right.push_back(psudoIndex);
            } else {
                right.push_back(s.top().second);
            }
        }
        s.push({a[i], i});
    }
    reverse(right.begin(), right.end());
    return right;
}

int maxHistogrem(vector<int> &a, int n) {
    vector<int> left = leftNextSmollest(a, n);
    vector<int> right = rightNextSmollest(a, n);
    vector<int> width;
    vector<int> area;
    for (int i = 0; i < n; i++) {
        width.push_back(right[i] - left[i] - 1);
    }
    for (int i = 0; i < n; i++) {
        area.push_back(a[i] * width[i]);
    }
    return *max_element(area.begin(), area.end());
}

int maxAreaReactangle(vector<vector<int>> &a, int n) {
    vector<int> v;
    for (int j = 0; j < n; j++) {
        v.push_back(a[0][j]);
    }
    int maxi = maxHistogrem(v, n);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v[j] = (a[i][j] == 0) ? 0 : v[j] + a[i][j];
        }
        maxi = max(maxi, maxHistogrem(v, n));
    }
    return maxi;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = maxAreaReactangle(a, n);
    cout << ans;
    return 0;
}
