#include<bits/stdc++.h>
using namespace std;

int numOfCircle(vector<vector<int>>& adj){
    int n=adj.size();
    vector<int> vis(n,0);

    int p=0;
    for(int i=0;i<n;i++){

        if(!vis[i]){
            queue<int> q;
            q.push(i);

            while(!q.empty()){
                int node=q.front();
                q.pop();

                vis[i]=1;

                for(int j=0;j<n;j++){
                    if(adj[node][j]==1 && !vis[j]){
                        q.push(j);
                        vis[j]=1;
                    }
                }
            }
            p++;
        }
    }
    return p;
}

int main(){ 
    int n;
    cin>>n;
     vector<vector<int>> adj(n, vector<int>(n));
   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }

   cout<<numOfCircle(adj);

    return 0;
}
