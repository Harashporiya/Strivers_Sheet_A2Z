#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int r, int c, vector<string>& v, int n) {
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

    void f(int c, vector<string>& v, int n, int& count) {
        if (c == n) {
            count++;
            return;
        }

        for (int r = 0; r < n; r++) {
            if (isSafe(r, c, v, n)) {
                v[r][c] = 'Q';
                f(c + 1, v, n, count);
                v[r][c] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> v(n, string(n, '.'));
        int count = 0;
        f(0, v, n, count);
        return count;
    }
};

int main() {
    int n;
    cin >> n;

    Solution obj;
    cout << obj.totalNQueens(n) << endl;

    return 0;
}
