#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int l = 0;
        int r = 0;
        int n = s.size();
        vector<int> sC(26, 0);
        vector<int> pC(26, 0);

        for (int i = 0; i < p.size(); i++) {
            pC[p[i] - 'a']++;
        }

        while (r < n) {
            sC[s[r] - 'a']++;

            if (r - l + 1 > p.size()) {
                sC[s[l] - 'a']--;
                l++;
            }

            if (r - l + 1 == p.size()) {
                if (sC == pC) {
                    ans.push_back(l);
                }
            }
            r++;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string s = "cbaebabacd";
    string p = "abc";
    
    vector<int> result = solution.findAnagrams(s, p);

    cout << "Anagrams of '" << p << "' in '" << s << "' are found at indices: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}