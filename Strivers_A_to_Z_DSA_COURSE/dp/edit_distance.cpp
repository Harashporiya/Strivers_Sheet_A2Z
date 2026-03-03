#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // ================= 1️⃣ RECURSION =================
    int editRecursive(int i, int j, string &s1, string &s2) {
        if (i == 0) return j;
        if (j == 0) return i;

        if (s1[i - 1] == s2[j - 1])
            return editRecursive(i - 1, j - 1, s1, s2);

        return 1 + min({
            editRecursive(i - 1, j, s1, s2),     // Delete
            editRecursive(i, j - 1, s1, s2),     // Insert
            editRecursive(i - 1, j - 1, s1, s2)  // Replace
        });
    }

    int minDistanceRecursive(string s1, string s2) {
        return editRecursive(s1.size(), s2.size(), s1, s2);
    }


    // ================= 2️⃣ MEMOIZATION =================
    int editMemo(int i, int j, string &s1, string &s2,
                 vector<vector<int>> &dp) {

        if (i == 0) return j;
        if (j == 0) return i;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i - 1] == s2[j - 1])
            return dp[i][j] =
                editMemo(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = 1 + min({
            editMemo(i - 1, j, s1, s2, dp),     // Delete
            editMemo(i, j - 1, s1, s2, dp),     // Insert
            editMemo(i - 1, j - 1, s1, s2, dp)  // Replace
        });
    }

    int minDistanceMemo(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return editMemo(n, m, s1, s2, dp);
    }


    // ================= 3️⃣ TABULATION =================
    int minDistanceTab(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = i;

        for (int j = 0; j <= m; j++)
            dp[0][j] = j;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min({
                        dp[i - 1][j],     // Delete
                        dp[i][j - 1],     // Insert
                        dp[i - 1][j - 1]  // Replace
                    });
            }
        }

        return dp[n][m];
    }


    // ================= 4️⃣ SPACE OPTIMIZED =================
    int minDistanceSpaceOpt(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int j = 0; j <= m; j++)
            prev[j] = j;

        for (int i = 1; i <= n; i++) {
            curr[0] = i;

            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    curr[j] = prev[j - 1];
                else
                    curr[j] = 1 + min({
                        prev[j],     // Delete
                        curr[j - 1], // Insert
                        prev[j - 1]  // Replace
                    });
            }

            prev = curr;
        }

        return prev[m];
    }
};


// ================= MAIN FUNCTION =================

int main() {
    Solution sol;

    string s1 = "horse";
    string s2 = "ros";

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