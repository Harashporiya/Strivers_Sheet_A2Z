#include<bits/stdc++.h>
using namespace std;
vector<int> dijkstraAlgorithm(int V, vector<vector<int>> &edges, int src){
    vector<vector<pair<int,int>>> adj(V);
    for(auto it:edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> dist(V,1e9);
    dist[src]=0;
    pq.push({0,src});

    while(!pq.empty()){
    int dis = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    for(auto it:adj[node]){
        int adjNode = it.first;
        int adjW = it.second;
        if(dis+adjW<dist[adjNode]){
            dist[adjNode] = dis+adjW;
            pq.push({dist[adjNode],adjNode});
        }
    }
    }
    return dist;
}
int main(){
    int V=5;
    vector<vector<int>> edges={
        {0,1,4},{0,2,8},{1,4,6},{2,3,2},{3,4,10}
    };
    int src=0;
    vector<int> ans=dijkstraAlgorithm(V,edges,src);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}