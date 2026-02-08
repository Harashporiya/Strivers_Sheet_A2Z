#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool valid(int r, int c, vector<vector<char>>& board, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == ch) return false;
            if (board[i][c] == ch) return false;
            if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == ch) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (valid(i, j, board, c)) {
                            board[i][j] = c;
                            if (solve(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';  
                            }
                        }
                    }
                    return false;  
                }
            }
        }
        return true; 
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '8', '.', '.', '.', '3', '7'},
        {'4', '.', '2', '7', '.', '.', '6', '.', '9'},
        {'7', '.', '6', '.', '.', '3', '.', '.', '5'},
        {'.', '6', '4', '.', '3', '.', '.', '.', '1'},
        {'9', '7', '8', '.', '2', '.', '.', '.', '6'},
        {'2', '5', '.', '.', '1', '.', '9', '8', '.'}
    };

    Solution obj;
    obj.solveSudoku(board);

    for (auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
