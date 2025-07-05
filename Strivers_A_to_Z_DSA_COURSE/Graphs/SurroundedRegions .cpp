// #include<bits/stdc++.h>
// using namespace std;
// void bfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis){
//     int n = board.size();
//     int m = board[0].size();

//     queue<pair<int,int>> q;
//     q.push({row,col});
//     vis[row][col]=1;

//     int delRow[] = {-1,0,+1,0};
//     int delCol[] = {0,+1,0,-1};
    
//     while(!q.empty()){
//         int row = q.front().first;
//         int col = q.front().second;
//         q.pop();

//         for(int i=0;i<4;i++){
//             int nrow = row+delRow[i];
//             int ncol = col+delCol[i];

//             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
//                 q.push({nrow,ncol});
//                 vis[nrow][ncol] = 1;
//             }
//         }
//     }
    
// }
// void solve(vector<vector<char>>& board) {
//     int n=board.size();
//     int m=board[0].size();

//     vector<vector<int>> vis(n,vector<int>(m,0));

//     for(int j=0;j<m;j++){
//         if(board[0][j]=='O' && !vis[0][j]){
//             bfs(0,j,board,vis);
//         }else if(board[n-1][j]=='O' && !vis[n-1][j]){
//             bfs(n-1,j,board,vis);
//         }
//     }

//     for(int i=0;i<n;i++){
//         if(board[i][0]=='O' && !vis[i][0]){
//             bfs(i,0,board,vis);
//         }else if(board[i][m-1]=='O' && !vis[i][m-1]){
//             bfs(i,m-1,board,vis);
//         }
//     }

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(board[i][j]=='O'&&!vis[i][j]){
//                 board[i][j]='X';
//             }

//         }
//     }
// }
// int main(){
//     vector<vector<char>> board = {
//         {'X','X','X','X'},
//         {'X','O','O','X'},
//         {'X','X','O','X'},
//         {'X','O','X','X'}
//     };
    
//     solve(board);

//     for(int i=0;i<board.size();i++){
//         for(int j=0;j<board[0].size();j++){
//             cout<<board[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

#include<bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis){
    int n = board.size();
    int m = board[0].size();

    vis[row][col]=1;

    int delRow[] = {-1,0,+1,0};
    int delCol[] = {0,+1,0,-1};

        for(int i=0;i<4;i++){
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
              dfs(nrow,ncol,board,vis);
                vis[nrow][ncol] = 1;
            }
        }
    
    
}
void solve(vector<vector<char>>& board) {
    int n=board.size();
    int m=board[0].size();

    vector<vector<int>> vis(n,vector<int>(m,0));

    for(int j=0;j<m;j++){
        if(board[0][j]=='O' && !vis[0][j]){
            dfs(0,j,board,vis);
        }else if(board[n-1][j]=='O' && !vis[n-1][j]){
            dfs(n-1,j,board,vis);
        }
    }

    for(int i=0;i<n;i++){
        if(board[i][0]=='O' && !vis[i][0]){
            dfs(i,0,board,vis);
        }else if(board[i][m-1]=='O' && !vis[i][m-1]){
            dfs(i,m-1,board,vis);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='O'&&!vis[i][j]){
                board[i][j]='X';
            }

        }
    }
}
int main(){
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };
    
    solve(board);

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}