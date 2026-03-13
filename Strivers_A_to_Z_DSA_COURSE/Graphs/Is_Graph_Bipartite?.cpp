#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    // DFS helper function
    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& graph) {
        color[node] = col;

        for (auto it : graph[node]) {
            if (color[it] == -1) {
                if (!dfs(it, !col, color, graph)) {
                    return false;
                }
            }
            else if (color[it] == col) {
                return false;
            }
        }
        return true;
    }

    // DFS Bipartite check
    bool isBipartiteDFS(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, color, graph)) {
                    return false;
                }
            }
        }
        return true;
    }

    // BFS Bipartite check
    bool isBipartiteBFS(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto it : graph[node]) {
                        if (color[it] == -1) {
                            color[it] = !color[node];
                            q.push(it);
                        }
                        else if (color[it] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main() {

    // Hardcoded graph
    // Example Bipartite Graph
    // 0 -- 1
    // |    |
    // 3 -- 2

    vector<vector<int>> graph = {
        {1,3},   // neighbors of node 0
        {0,2},   // neighbors of node 1
        {1,3},   // neighbors of node 2
        {0,2}    // neighbors of node 3
    };

    Solution obj;

    if (obj.isBipartiteDFS(graph))
        cout << "Graph is Bipartite using DFS\n";
    else
        cout << "Graph is NOT Bipartite using DFS\n";

    if (obj.isBipartiteBFS(graph))
        cout << "Graph is Bipartite using BFS\n";
    else
        cout << "Graph is NOT Bipartite using BFS\n";

    return 0;
}