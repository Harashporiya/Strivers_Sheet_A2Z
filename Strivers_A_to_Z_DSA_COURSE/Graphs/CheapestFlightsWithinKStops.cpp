#include<bits/stdc++.h>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);
        q.push({0,{src,0}});
        dist[src]=0;

        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
           if(k<stops)continue;
            for(auto it:adj[node]){
                int adjNode=it.first;
                int adjW=it.second;

                if(cost+adjW<dist[adjNode] && stops<=k){
                    dist[adjNode]=cost+adjW;
                    q.push({stops+1,{adjNode,cost+adjW}});
                }
            }
        }

        if(dist[dst]==1e9)return -1;
        return dist[dst];
}
int main(){
    vector<vector<int>> flights={
        {0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}
    };
      int src=0,dst=3,k=1,n=4;
    cout<<findCheapestPrice(n,flights,src,dst,k);
    cout<<endl;
}