#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 1️⃣ Recursive Approach (Brute Force)
    bool f(int i, int j, string s, string p) {
        // Base Cases
        if(i == 0 && j == 0) return true;         // both empty
        if(i > 0 && j == 0) return false;         // pattern empty, string not
        if(i == 0 && j > 0){                      // string empty, pattern may have *
            for(int jj = 0; jj < j; jj++){
                if(p[jj] != '*') return false;
            }
            return true;
        }

        if(s[i-1] == p[j-1] || p[j-1] == '?')
            return f(i-1, j-1, s, p);
        if(p[j-1] == '*')
            return f(i-1, j, s, p) || f(i, j-1, s, p); // * matches 1 char or empty

        return false;
    }

    bool isMatchRecursive(string s, string p) {
        int n = s.size(), m = p.size();
        return f(n, m, s, p);
    }

    // 2️⃣ Memoization (Top-Down DP)
    bool fMemo(int i, int j, string s, string p, vector<vector<int>>& dp) {
        if(i == 0 && j == 0) return true;
        if(i > 0 && j == 0) return false;
        if(i == 0 && j > 0){
            for(int jj = 0; jj < j; jj++){
                if(p[jj] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == p[j-1] || p[j-1] == '?')
            return dp[i][j] = fMemo(i-1, j-1, s, p, dp);
        if(p[j-1] == '*')
            return dp[i][j] = fMemo(i-1, j, s, p, dp) || fMemo(i, j-1, s, p, dp);

        return dp[i][j] = false;
    }

    bool isMatchMemo(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return fMemo(n, m, s, p, dp);
    }

    // 3️⃣ Tabulation (Bottom-Up DP with 2D array)
    bool isMatchDP(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;

        // Initialize first row (string empty)
        for(int j = 1; j <= m; j++){
            dp[0][j] = dp[0][j-1] && (p[j-1] == '*');
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }

        return dp[n][m];
    }

    // 4️⃣ Space Optimized DP (1D array)
    bool isMatchSpaceOptimized(string s, string p) {
        int n = s.size(), m = p.size();
        vector<bool> prev(m+1, false), cur(m+1, false);
        prev[0] = true;

        // Initialize first row (string empty)
        for(int j = 1; j <= m; j++){
            prev[j] = prev[j-1] && (p[j-1] == '*');
        }

        for(int i = 1; i <= n; i++){
            cur[0] = false; // pattern empty, string not
            for(int j = 1; j <= m; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    cur[j] = prev[j-1];
                else if(p[j-1] == '*')
                    cur[j] = prev[j] || cur[j-1];
                else
                    cur[j] = false;
            }
            prev = cur;
        }

        return prev[m];
    }

    // Unified function to choose approach
    bool isMatch(string s, string p, string approach) {
        if(approach == "recursive") return isMatchRecursive(s, p);
        if(approach == "memo") return isMatchMemo(s, p);
        if(approach == "dp") return isMatchDP(s, p);
        if(approach == "spaceOptimized") return isMatchSpaceOptimized(s, p);
        return false;
    }
};

int main() {
    Solution sol;
    string s = "adceb";
    string p = "*a*b";

    cout << boolalpha; // print true/false instead of 1/0
    cout << "Recursive Approach: " << sol.isMatch(s, p, "recursive") << endl;
    cout << "Memoization Approach: " << sol.isMatch(s, p, "memo") << endl;
    cout << "DP Approach (2D): " << sol.isMatch(s, p, "dp") << endl;
    cout << "Space Optimized DP (1D): " << sol.isMatch(s, p, "spaceOptimized") << endl;

    return 0;
}