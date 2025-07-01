#include<bits/stdc++.h>
using namespace std;

void dfs_graph(int node, vector<vector<int>> adj,int vis[], vector<int>&ls ){
    vis[node]=1;
    ls.push_back(node);

    // traverse all the neighbours
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs_graph(it,adj,vis,ls);
        }
    }
}

vector<int> dfs(vector<vector<int>> &adj){
    int n = adj.size();
    int vis[n] = {0};
    int start=0;
    vector<int> ls;
    dfs_graph(start, adj, vis, ls);
    return ls;
}

int main(){
    vector<vector<int>> adj;
    adj.push_back({2, 3, 1}); 
    adj.push_back({0});      
    adj.push_back({0, 4});   
    adj.push_back({0});      
    adj.push_back({2});   
    
   vector<int> ans = dfs(adj);
   for(auto it:ans){
    cout<<it<<" ";
   }
    return 0;
}
