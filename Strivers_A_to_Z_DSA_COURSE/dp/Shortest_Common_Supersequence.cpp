#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // ================= 1️⃣ RECURSION =================
    string scsRecursive(string s1, string s2, int i, int j) {
        if (i == 0) return s2.substr(0, j);
        if (j == 0) return s1.substr(0, i);

        if (s1[i - 1] == s2[j - 1])
            return scsRecursive(s1, s2, i - 1, j - 1) + s1[i - 1];

        string op1 = scsRecursive(s1, s2, i - 1, j) + s1[i - 1];
        string op2 = scsRecursive(s1, s2, i, j - 1) + s2[j - 1];

        return (op1.length() < op2.length()) ? op1 : op2;
    }

    string shortestCommonSupersequenceRecursive(string s1, string s2) {
        return scsRecursive(s1, s2, s1.length(), s2.length());
    }


    // ================= 2️⃣ TABULATION (Your Approach) =================
    string shortestCommonSupersequence(string s1, string s2) {

        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Build LCS table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Backtrack to build SCS
        string ans = "";
        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                ans += s1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] < dp[i][j - 1]) {
                ans += s2[j - 1];
                j--;
            }
            else {
                ans += s1[i - 1];
                i--;
            }
        }

        while (i > 0) ans += s1[--i];
        while (j > 0) ans += s2[--j];

        reverse(ans.begin(), ans.end());
        return ans;
    }
};


// ================= MAIN FUNCTION =================

int main() {
    Solution sol;

    string s1 = "abac";
    string s2 = "cab";

    cout << "Recursive SCS: "
         << sol.shortestCommonSupersequenceRecursive(s1, s2) << endl;

    cout << "DP SCS: "
         << sol.shortestCommonSupersequence(s1, s2) << endl;

    return 0;
}