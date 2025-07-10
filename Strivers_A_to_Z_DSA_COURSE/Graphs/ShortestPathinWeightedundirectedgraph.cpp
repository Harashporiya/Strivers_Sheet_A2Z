#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPathWeighted(int n, vector<vector<int>>&edges){
    vector<vector<pair<int,int>>> adj(n+1);

    for(auto it:edges){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n+1,1e9);
    vector<int> parent(n+1);

    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    dist[1]=0;
    pq.push({0,1});

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
                parent[adjNode] = node;
            }
        }
    }

    if(dist[n]==1e9)return {-1};
    vector<int> path;
    int node = n;
    while(parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());

    return path;

}
int main(){
    vector<vector<int>> edges={
        {1,2,2},{2,5,5},{2,3,4},{1,4,1},{4,3,3},{3,5,1}
    };

    int n=5;

    vector<int> ans = shortestPathWeighted(n,edges);

    for(auto it:ans){
        cout<<it<<"->";
    }
}