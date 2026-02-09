#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(isWater[i][j] == 1){
                    isWater[i][j] = 0;
                    q.push({i, j});
                } else {
                    isWater[i][j] = -1;
                }
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m
                   && isWater[nr][nc] == -1){

                    isWater[nr][nc] = isWater[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return isWater;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> isWater = {
        {0, 0, 1},
        {1, 0, 0},
        {0, 0, 0}
    };

    vector<vector<int>> result = sol.highestPeak(isWater);

    for(auto &row : result){
        for(int val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
