#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate90(vector<vector<int>>& mat) {
        int n = mat.size();

        // Transpose
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // Reverse each row
        for(int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0; i < 4; i++) {
            if(mat == target) return true;
            rotate90(mat);
        }
        return false;
    }
};

int main() {
    Solution obj;

    // 🔹 Hardcoded test case (Example 3)
    vector<vector<int>> mat = {
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };

    vector<vector<int>> target = {
        {1,1,1},
        {0,1,0},
        {0,0,0}
    };

    bool result = obj.findRotation(mat, target);

    if(result)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}