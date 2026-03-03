#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    // ------------------ 1. RECURSION ------------------
    int lcsRecursive(string &text1, string &text2, int i, int j) {
        if (i == 0 || j == 0)
            return 0;

        if (text1[i - 1] == text2[j - 1])
            return 1 + lcsRecursive(text1, text2, i - 1, j - 1);

        return max(
            lcsRecursive(text1, text2, i - 1, j),
            lcsRecursive(text1, text2, i, j - 1)
        );
    }

    int longestCommonSubsequenceRecursive(string text1, string text2) {
        return lcsRecursive(text1, text2, text1.size(), text2.size());
    }

    // ------------------ 2. MEMOIZATION ------------------
    int lcsMemo(string &text1, string &text2, int i, int j, vector<vector<int>> &dp) {
        if (i == 0 || j == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (text1[i - 1] == text2[j - 1])
            dp[i][j] = 1 + lcsMemo(text1, text2, i - 1, j - 1, dp);
        else
            dp[i][j] = max(
                lcsMemo(text1, text2, i - 1, j, dp),
                lcsMemo(text1, text2, i, j - 1, dp)
            );

        return dp[i][j];
    }

    int longestCommonSubsequenceMemo(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1,
                               vector<int>(text2.size() + 1, -1));

        return lcsMemo(text1, text2, text1.size(), text2.size(), dp);
    }

    // ------------------ 3. TABULATION ------------------
    int longestCommonSubsequenceTab(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1,
                               vector<int>(text2.size() + 1, 0));

        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[text1.size()][text2.size()];
    }
};

// ------------------ MAIN FUNCTION ------------------

int main() {
    Solution sol;

    string text1, text2;

    cout << "Enter first string: ";
    cin >> text1;

    cout << "Enter second string: ";
    cin >> text2;

    cout << "\nUsing Recursion: "
         << sol.longestCommonSubsequenceRecursive(text1, text2);

    cout << "\nUsing Memoization: "
         << sol.longestCommonSubsequenceMemo(text1, text2);

    cout << "\nUsing Tabulation: "
         << sol.longestCommonSubsequenceTab(text1, text2);

    return 0;
}