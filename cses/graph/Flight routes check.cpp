//the fact that one planet can reach all others and all other planets can
//reach the planet implies any city can reach another city

#include<bits/stdc++.h>

using namespace std;

vector<int>vis;

void dfs(int u,vector<vector<int>>&edges){
    vis[u]=1;
    for(int v:edges[u]){
        if(!vis[v])
        dfs(v,edges);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges(n),rev_edges(n);
    
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        --u,--v;
        edges[u].push_back(v);
        rev_edges[v].push_back(u);
    }
    vis=vector<int>(n);
    dfs(0,edges);
    for(int i=0;i<n;++i){
        if(vis[i]==0){
            cout<<"NO\n";
            cout<<1<<' '<<i+1<<'\n';
            return 0;
        }
    }
    vis=vector<int>(n);
    dfs(0,rev_edges);
    for(int i=0;i<n;++i){
        if(vis[i]==0){
            cout<<"NO\n";
            cout<<i+1<<' '<<1<<'\n';
            return 0;
        }
    }
    cout<<"YES\n";
}