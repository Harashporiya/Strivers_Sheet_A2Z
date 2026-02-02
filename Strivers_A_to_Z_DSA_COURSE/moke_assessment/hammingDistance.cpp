#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        string oneBit = "";
        string twoBit = "";
        
        while (x > 0) {
            oneBit += to_string(x % 2);
            x /= 2;
        }
        
        while (y > 0) {
            twoBit += to_string(y % 2);
            y /= 2;
        }
        
        int n = max(oneBit.size(), twoBit.size());
        while (oneBit.size() < n) oneBit += '0';
        while (twoBit.size() < n) twoBit += '0';
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (oneBit[i] != twoBit[i])
                count++;
        }
        
        return count;
    }
};

int main() {
    Solution obj;
    
    int x, y;
    cin >> x >> y;
    
    cout << obj.hammingDistance(x, y) << endl;
    return 0;
}
