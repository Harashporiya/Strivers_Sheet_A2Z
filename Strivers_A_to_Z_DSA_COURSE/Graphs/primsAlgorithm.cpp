#include<bits/stdc++.h>
using namespace std;
 vector<pair<pair<int,int>,int>> primsAlgorithm(int V,vector<vector<int>> &edges){
    // vector<vector<pair<int,int>>> adj(V);

    // for(int i=0;i<edges.size();i++){
    //     adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    //     adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    // }

    // vector<int> key(V,1e9);
    // vector<int> parent(V,-1);   
    // vector<bool> mst(V,false);

    // key[0]=0;

    // for(int i=0;i<V;i++){
    //     int mini=INT_MAX;
    //     int u;
    //     for(int j=0;j<V;j++){
    //         if(mst[j]==false && key[j]<mini){
    //             mini=key[j];
    //             u=j;
    //         }
    //     }
    //     mst[u]=true;
    //     for(auto it:adj[u]){
    //         if(mst[it.first]==false && it.second<key[it.first]){
    //             key[it.first]=it.second;
    //             parent[it.first]=u;
    //         }
    //     }
    // }
    // vector<pair<pair<int,int>,int>> res;
    // for(int i=1;i<V;i++){
    //     res.push_back({{parent[i],i},key[i]});
    // }
    // return res;

            // code here
        vector<vector<pair<int,int>>> adj(V);
        int sum=0;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        //vector<int> key(V,1e9);
        vector<int> mst(V,false);
        //vector<int> parent(V,-1);
        
       // key[0]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});

        
        while(!pq.empty()){
            int node=pq.top().second;
            int w=pq.top().first;
            pq.pop();
            
            if(mst[node])continue;
            mst[node]=true;
            sum+=w;
            
            for(auto it:adj[node]){
                if(!mst[it.first]){
                    pq.push({it.second,it.first});
                }
            }
        }
        return sum;
}
int main(){
    int V = 5;
	vector<vector<int>> edges = {{0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {4, 2, 7}};

    vector<pair<pair<int,int>,int>> ans=primsAlgorithm(V,edges);

    for(auto it:ans){
        cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<endl;
    }
}