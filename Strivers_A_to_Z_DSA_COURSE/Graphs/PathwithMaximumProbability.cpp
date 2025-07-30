#include<bits/stdc++.h>
using namespace std;
double maximumProbablitiy(vector<vector<int>>&edges,vector<double>&succProb,int start_node, int end_node){

    int n=edges.size();
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<n;i++){
        int u = edges[i][0];
        int v=  edges[i][1];
        int wt = succProb[i];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    queue<int> q;
    q.push(start_node);

    vector<double> prob(n,0.0);
    prob[start_node]=1.0;

    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(auto it:adj[node]){
            int adjNode=it.first;
            double adjWt = it.second;

            double newProb = prob[node]*adjWt;

            if(newProb > prob[adjNode]){
                prob[adjNode]=newProb;
                q.push(adjNode);
            }
        }
    }

    return prob[end_node];


}
int main(){
    vector<vector<int>> edges={{0,1},{1,2},{0,2}};
    vector<double> succProb={0.5,0.5,0.2};
    int start_node=0;
    int end_node=2;

    cout<<maximumProbablitiy(edges,succProb,start_node,end_node);
}