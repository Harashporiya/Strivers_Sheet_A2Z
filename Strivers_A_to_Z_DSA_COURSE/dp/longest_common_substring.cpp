#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    // ------------------ 1. RECURSION ------------------
    int lcsRecursive(string &s1, string &s2, int i, int j, int count) {
        if (i == 0 || j == 0)
            return count;

        int count1 = count;

        if (s1[i - 1] == s2[j - 1])
            count1 = lcsRecursive(s1, s2, i - 1, j - 1, count + 1);

        int count2 = lcsRecursive(s1, s2, i - 1, j, 0);
        int count3 = lcsRecursive(s1, s2, i, j - 1, 0);

        return max(count1, max(count2, count3));
    }

    int longestCommonSubstrRecursive(string s1, string s2) {
        return lcsRecursive(s1, s2, s1.size(), s2.size(), 0);
    }

    // ------------------ 2. MEMOIZATION ------------------
    int lcsMemo(string &s1, string &s2, int i, int j, int count,
                vector<vector<vector<int>>> &dp) {

        if (i == 0 || j == 0)
            return count;

        if (dp[i][j][count] != -1)
            return dp[i][j][count];

        int count1 = count;

        if (s1[i - 1] == s2[j - 1])
            count1 = lcsMemo(s1, s2, i - 1, j - 1, count + 1, dp);

        int count2 = lcsMemo(s1, s2, i - 1, j, 0, dp);
        int count3 = lcsMemo(s1, s2, i, j - 1, 0, dp);

        return dp[i][j][count] = max(count1, max(count2, count3));
    }

    int longestCommonSubstrMemo(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(m + 1, vector<int>(min(n, m) + 1, -1)));

        return lcsMemo(s1, s2, n, m, 0, dp);
    }

    // ------------------ 3. TABULATION ------------------
    int longestCommonSubstrTab(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int maxi = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    maxi = max(maxi, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return maxi;
    }
};

// ------------------ MAIN FUNCTION ------------------

int main() {
    Solution sol;

    string s1 = "abcde";
    string s2 = "abfce";

    cout << "\nUsing Recursion: "
         << sol.longestCommonSubstrRecursive(s1, s2);

    cout << "\nUsing Memoization: "
         << sol.longestCommonSubstrMemo(s1, s2);

    cout << "\nUsing Tabulation: "
         << sol.longestCommonSubstrTab(s1, s2);

    return 0;
}