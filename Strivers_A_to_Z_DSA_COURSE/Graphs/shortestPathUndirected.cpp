#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(vector<vector<int>> &adj, int src){
    int n=adj.size();
    vector<int> dist(n,1e9);
    dist[src]=0;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int node=q.front();
        q.pop();

        for(auto it : adj[node]){
            if(dist[node]+1<dist[it]){
                dist[it]=1+dist[node];
                q.push(it);
            }
        }
    }

    for(int i=0;i<n;i++){
        if(dist[i]==1e9){
            dist[i]=-1;
        }
    }
    return dist;

}
int main(){
    vector<vector<int>> adj={
        {1, 3}, {0, 2}, {1, 6}, {0, 4}, {3, 5}, {4, 6}, {2, 5, 7, 8}, {6, 8}, {7, 6}
    };
    int src=0;
    vector<int> ans = shortestPath(adj,src);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}