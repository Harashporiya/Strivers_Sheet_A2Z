#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCommas(int n) {
        int total = 0;

        for (int i = 1; i <= n; i++) {
            int d = 0;
            int num = i;
            while (num > 0) {
                num /= 10;
                d++;
            }

            if (d >= 4) {
                total += (d - 1) / 3;  // Number of commas for this number
            }
        }

        return total;
    }
};

int main() {
    Solution sol;

    // Example: count commas from 1 to 1000
    int n = 1000;
    cout << "Total commas from 1 to " << n << ": " << sol.countCommas(n) << endl;

    // Another example
    n = 12345;
    cout << "Total commas from 1 to " << n << ": " << sol.countCommas(n) << endl;

    return 0;
}