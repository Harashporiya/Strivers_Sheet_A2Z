#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // ================= 1️⃣ RECURSION =================
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

    int minInsertionsRecursive(string s) {
        int n = s.length();
        int lps = lpsRecursive(s, 0, n - 1);
        return n - lps;
    }


    // ================= 2️⃣ MEMOIZATION =================
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

    int minInsertionsMemo(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int lps = lpsMemo(s, 0, n - 1, dp);
        return n - lps;
    }


    // ================= 3️⃣ TABULATION (Gap Strategy) =================
    int minInsertionsTab(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                if (s[i] == s[j]) {
                    if (len == 2)
                        dp[i][j] = 2;
                    else
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = max(
                        dp[i + 1][j],
                        dp[i][j - 1]
                    );
                }
            }
        }

        return n - dp[0][n - 1];
    }


    // ================= 4️⃣ LCS METHOD (Your Method) =================
    int minInsertionsLCS(string s) {
        int n = s.length();

        string rev = s;
        reverse(rev.begin(), rev.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == rev[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return n - dp[n][n];
    }


    // ================= 5️⃣ SPACE OPTIMIZED =================
    int minInsertionsSpaceOpt(string s) {
        int n = s.length();

        string rev = s;
        reverse(rev.begin(), rev.end());

        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == rev[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(curr[j - 1], prev[j]);
            }
            prev = curr;
        }

        return n - prev[n];
    }
};


// ================= MAIN FUNCTION =================

int main() {
    Solution sol;

    string s = "mbadm";

    cout << "Recursion: "
         << sol.minInsertionsRecursive(s) << endl;

    cout << "Memoization: "
         << sol.minInsertionsMemo(s) << endl;

    cout << "Tabulation (Gap DP): "
         << sol.minInsertionsTab(s) << endl;

    cout << "LCS Method: "
         << sol.minInsertionsLCS(s) << endl;

    cout << "Space Optimized: "
         << sol.minInsertionsSpaceOpt(s) << endl;

    return 0;
}