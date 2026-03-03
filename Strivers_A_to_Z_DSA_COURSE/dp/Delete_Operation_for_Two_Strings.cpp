#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // ================= 1️⃣ RECURSION =================
    int lcsRecursive(string &s1, string &s2, int i, int j) {
        if (i == 0 || j == 0)
            return 0;

        if (s1[i - 1] == s2[j - 1])
            return 1 + lcsRecursive(s1, s2, i - 1, j - 1);

        return max(
            lcsRecursive(s1, s2, i - 1, j),
            lcsRecursive(s1, s2, i, j - 1)
        );
    }

    int minDistanceRecursive(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        int lcs = lcsRecursive(s1, s2, n, m);
        return n + m - 2 * lcs;
    }


    // ================= 2️⃣ MEMOIZATION =================
    int lcsMemo(string &s1, string &s2, int i, int j,
                vector<vector<int>> &dp) {

        if (i == 0 || j == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i - 1] == s2[j - 1])
            dp[i][j] = 1 + lcsMemo(s1, s2, i - 1, j - 1, dp);
        else
            dp[i][j] = max(
                lcsMemo(s1, s2, i - 1, j, dp),
                lcsMemo(s1, s2, i, j - 1, dp)
            );

        return dp[i][j];
    }

    int minDistanceMemo(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int lcs = lcsMemo(s1, s2, n, m, dp);

        return n + m - 2 * lcs;
    }


    // ================= 3️⃣ TABULATION (Your Approach) =================
    int minDistanceTab(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return n + m - 2 * dp[n][m];
    }


    // ================= 4️⃣ SPACE OPTIMIZED =================
    int minDistanceSpaceOpt(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }

        return n + m - 2 * prev[m];
    }
};


// ================= MAIN FUNCTION =================

int main() {
    Solution sol;

    string s1 = "sea";
    string s2 = "eat";

    cout << "Recursion: "
         << sol.minDistanceRecursive(s1, s2) << endl;

    cout << "Memoization: "
         << sol.minDistanceMemo(s1, s2) << endl;

    cout << "Tabulation: "
         << sol.minDistanceTab(s1, s2) << endl;

    cout << "Space Optimized: "
         << sol.minDistanceSpaceOpt(s1, s2) << endl;

    return 0;
}