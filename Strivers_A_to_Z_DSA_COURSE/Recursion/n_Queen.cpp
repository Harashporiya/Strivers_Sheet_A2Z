#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValid(int r, int c, vector<string>& v, int n) {
        int dr = r;
        int dc = c;

        while (r >= 0 && c >= 0) {
            if (v[r][c] == 'Q') return false;
            r--;
            c--;
        }
        r = dr;
        c = dc;

        while (c >= 0) {
            if (v[r][c] == 'Q') return false;
            c--;
        }

        r = dr;
        c = dc;

        while (r < n && c >= 0) {
            if (v[r][c] == 'Q') return false;
            r++;
            c--;
        }

        return true;
    }

    void f(int col, int n, vector<vector<string>>& ans, vector<string>& v) {
        if (col == n) {
            ans.push_back(v);
            return;
        }

        for (int r = 0; r < n; r++) {
            if (checkValid(r, col, v, n)) {
                v[r][col] = 'Q';
                f(col + 1, n, ans, v);
                v[r][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> v(n, s);

        f(0, n, ans, v);
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    Solution obj;
    vector<vector<string>> solutions = obj.solveNQueens(n);

    for (auto& solution : solutions) {
        for (auto& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
