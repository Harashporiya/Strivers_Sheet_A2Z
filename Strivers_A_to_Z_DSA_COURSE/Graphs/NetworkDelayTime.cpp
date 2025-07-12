#include<bits/stdc++.h>
using namespace std;
int networkDelayTime(int n, vector<vector<int>>&times,int k){
    vector<vector<pair<int,int>>> adj(n+1);
    for(auto it:times){
        adj[it[0]].push_back({it[1],it[2]});
    }

    queue<pair<int,int>> q;
    vector<int> dist(n+1,1e9);

    dist[k]=0;
    q.push({0,k});
   
    while(!q.empty()){
        int dis = q.front().first;
        int node = q.front().second;
        q.pop();

        for(auto it:adj[node]){
            int adjNode = it.first;
            int adjW = it.second;
            if(dis+adjW<dist[adjNode]){
                dist[adjNode]=dis+adjW;
                q.push({dist[adjNode],adjNode});
            }
        }
    }

    int maxNum=0;
    for(int i=1;i<=n;i++){
        if(dist[i]==1e9)return -1;
        maxNum=max(maxNum,dist[i]);
    }
    return maxNum;

}
int main(){
    vector<vector<int>> times={
        {2,1,1},{2,3,1},{3,4,1}
    };
    int N=4,k=2;
    cout<<networkDelayTime(N,times,k);
    cout<<endl;
}