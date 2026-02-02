#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        if (n <= 3) return true;
        if (n % 4 == 0) return false;
        return true;
    }
};

int main() {
    Solution obj;
    
    int n;
    cin >> n;
    
    cout << (obj.canWinNim(n) ? "true" : "false") << endl;
    return 0;
}
