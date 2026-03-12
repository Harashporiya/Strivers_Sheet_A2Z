#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ---------- DFS ----------
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int &nodes, int &degSum) {
        vis[node] = 1;
        nodes++;
        degSum += adj[node].size();

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, nodes, degSum);
            }
        }
    }

    int countCompleteComponentsDFS(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        int good = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {

                int nodes = 0;
                int degSum = 0;

                dfs(i, adj, vis, nodes, degSum);

                int edgeCount = degSum / 2;

                if (edgeCount == nodes * (nodes - 1) / 2)
                    good++;
            }
        }

        return good;
    }

    // ---------- BFS ----------
    int countCompleteComponentsBFS(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        int good = 0;

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {

                queue<int> q;
                q.push(i);
                vis[i] = 1;

                int nodes = 0;
                int degSum = 0;

                while (!q.empty()) {

                    int node = q.front();
                    q.pop();

                    nodes++;
                    degSum += adj[node].size();

                    for (auto it : adj[node]) {
                        if (!vis[it]) {
                            vis[it] = 1;
                            q.push(it);
                        }
                    }
                }

                int edgeCount = degSum / 2;

                if (edgeCount == nodes * (nodes - 1) / 2)
                    good++;
            }
        }

        return good;
    }
};

int main() {

    Solution obj;

    // Example graph
    int n = 7;

    vector<vector<int>> edges = {
        {1,2},
        {7,2},
        {3,5},
        {3,4},
        {4,5}
    };

    // convert to 0-index
    for(auto &e : edges){
        e[0]--;
        e[1]--;
    }

    cout << "DFS Good Components: "
         << obj.countCompleteComponentsDFS(n, edges) << endl;

    cout << "BFS Good Components: "
         << obj.countCompleteComponentsBFS(n, edges) << endl;

    return 0;
}