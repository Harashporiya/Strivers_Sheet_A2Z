#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(mat[i][j] == 1) {

                    bool check = true;

                    // Check row
                    for(int col = 0; col < m; col++) {
                        if(col != j && mat[i][col] == 1) {
                            check = false;
                            break;
                        }
                    }

                    // Check column
                    for(int row = 0; row < n; row++) {
                        if(row != i && mat[row][j] == 1) {
                            check = false;
                            break;
                        }
                    }

                    if(check) ans++;
                }
            }
        }

        return ans;
    }
};

int main() {

    vector<vector<int>> mat = {
        {1,0,0},
        {0,0,1},
        {1,0,0}
    };

    Solution obj;
    cout << "Special Positions: " << obj.numSpecial(mat);

    return 0;
}