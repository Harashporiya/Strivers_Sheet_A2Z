#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> original = mat;

        while (k > 0) { 
            for (int i = 0; i < n; i++) {

                if (i % 2 == 0) {
                    int v = mat[i][0];
                    for (int j = 1; j < m; j++) {
                        mat[i][j - 1] = mat[i][j];
                    }
                    mat[i][m - 1] = v;
                } else {
                    int v1 = mat[i][m - 1];
                    for (int j = m - 1; j > 0; j--) {
                        mat[i][j] = mat[i][j - 1];
                    }
                    mat[i][0] = v1;
                }
            }    
            k--;
        }

        return original == mat;
    }
};

int main() {
    Solution sol;

    // Hardcoded matrix
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int k = 2; // number of operations

    bool result = sol.areSimilar(mat, k);

    if (result) {
        cout << "Matrices are similar after " << k << " operations." << endl;
    } else {
        cout << "Matrices are NOT similar after " << k << " operations." << endl;
    }

    return 0;
}