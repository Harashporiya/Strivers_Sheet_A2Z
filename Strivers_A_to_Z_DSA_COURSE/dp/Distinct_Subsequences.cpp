#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Brute Force Approach (Recursion with Memoization)
    int f(int i, int j, string s, string t, vector<vector<double>>& dp) {
        // Base case: if t is empty, there's 1 way (empty subsequence in s)
        if (j == 0) {
            return 1;
        }
        // Base case: if s is empty but t is not, no way to form t
        if (i == 0) {
            return 0;
        }

        // If already computed, return the stored result
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // If characters match, consider both cases: include or exclude s[i-1]
        if (s[i-1] == t[j-1]) {
            return dp[i][j] = f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp);
        } else {
            return dp[i][j] = f(i-1, j, s, t, dp);
        }
    }

    // Brute Force Approach (with DP Memoization)
    int numDistinctBruteForce(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<double>> dp(n + 1, vector<double>(m + 1, -1)); // Initialize dp with -1
        return f(n, m, s, t, dp);
    }

    // Optimized DP Approach (Using 2D DP array)
    int numDistinctDP(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

        // Base case: if t is empty, there is 1 way to form it
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // If characters match, we have two options: include or exclude
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][m];
    }

    // Space Optimized DP Approach (Using 1D DP array)
    int numDistinctSpaceOptimized(string s, string t) {
        int n = s.size(), m = t.size();
        vector<double> dp(m + 1, 0);
        dp[0] = 1;  // Base case: 1 way to form an empty t

        for (int i = 1; i <= n; i++) {
            vector<double> prev = dp;  // Store previous row
            for (int j = 1; j <= m; j++) {
                if (s[i-1] == t[j-1]) {
                    dp[j] = prev[j-1] + prev[j];  // Include or exclude s[i-1]
                } else {
                    dp[j] = prev[j];  // Exclude s[i-1]
                }
            }
        }

        return dp[m];
    }

    // Function to call the correct approach
    int numDistinct(string s, string t, string approach) {
        if (approach == "bruteForce") {
            return numDistinctBruteForce(s, t);
        } else if (approach == "dp") {
            return numDistinctDP(s, t);
        } else if (approach == "spaceOptimized") {
            return numDistinctSpaceOptimized(s, t);
        }
        return 0;
    }
};

int main() {
    Solution sol;
    string s = "rabbbit";
    string t = "rabbit";

    cout << "Brute Force Approach (with DP): " << sol.numDistinct(s, t, "bruteForce") << endl;
    cout << "DP Approach (2D array): " << sol.numDistinct(s, t, "dp") << endl;
    cout << "Space Optimized DP Approach (1D array): " << sol.numDistinct(s, t, "spaceOptimized") << endl;

    return 0;
}