#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child = 0;
        int cookie = 0;

        while (child < g.size() && cookie < s.size()) {
            if (s[cookie] >= g[child]) {
                child++;
            }
            cookie++;
        }

        return child;
    }
};


// ================= MAIN FUNCTION =================

int main() {

    Solution obj;

    // Hardcoded test case
    vector<int> g = {1, 2, 3};      // Greed factors of children
    vector<int> s = {1, 1};         // Cookie sizes

    cout << "Children greed factors: ";
    for (int x : g) cout << x << " ";

    cout << "\nCookie sizes: ";
    for (int x : s) cout << x << " ";

    cout << "\n\nMaximum content children: "
         << obj.findContentChildren(g, s) << endl;

    return 0;
}