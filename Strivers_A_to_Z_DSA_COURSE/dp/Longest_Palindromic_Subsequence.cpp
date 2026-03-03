#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // ------------------ 1. RECURSION ------------------
    int lpsRecursive(string &s, int i, int j) {
        if (i > j) return 0;
        if (i == j) return 1;

        if (s[i] == s[j])
            return 2 + lpsRecursive(s, i + 1, j - 1);

        return max(
            lpsRecursive(s, i + 1, j),
            lpsRecursive(s, i, j - 1)
        );
    }

    int longestPalindromeSubseqRecursive(string s) {
        return lpsRecursive(s, 0, s.size() - 1);
    }

    // ------------------ 2. MEMOIZATION ------------------
    int lpsMemo(string &s, int i, int j, vector<vector<int>> &dp) {
        if (i > j) return 0;
        if (i == j) return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            dp[i][j] = 2 + lpsMemo(s, i + 1, j - 1, dp);
        else
            dp[i][j] = max(
                lpsMemo(s, i + 1, j, dp),
                lpsMemo(s, i, j - 1, dp)
            );

        return dp[i][j];
    }

    int longestPalindromeSubseqMemo(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return lpsMemo(s, 0, n - 1, dp);
    }

    // ------------------ 3. TABULATION (LCS METHOD) ------------------
    int longestPalindromeSubseqTab(string s) {
        string t = s;
        reverse(t.begin(), t.end());

        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][n];
    }

    // ------------------ 4. SPACE OPTIMIZED ------------------
    int longestPalindromeSubseqSpaceOpt(string s) {
        string t = s;
        reverse(t.begin(), t.end());

        int n = s.size();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }

        return prev[n];
    }
};

// ------------------ MAIN FUNCTION ------------------

int main() {
    Solution sol;

    string s = "bbbab";

    cout << "Recursion: "
         << sol.longestPalindromeSubseqRecursive(s) << endl;

    cout << "Memoization: "
         << sol.longestPalindromeSubseqMemo(s) << endl;

    cout << "Tabulation (LCS method): "
         << sol.longestPalindromeSubseqTab(s) << endl;

    cout << "Space Optimized: "
         << sol.longestPalindromeSubseqSpaceOpt(s) << endl;

    return 0;
}