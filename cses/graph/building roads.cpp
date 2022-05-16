#include<iostream>
#include<vector>
using namespace std;

void dfs(int u,vector<vector<int>>&edges,vector<int>&vis){
    vis[u]=1;
    for(int v:edges[u]){
        if(!vis[v]) dfs(v,edges,vis);
    }
}

int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>>edges(n);
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        --u,--v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<int>vis(n);
    int k=0,prev=-1;
    vector<pair<int,int>>v;
    for(int i=0;i<n;++i){
        if(vis[i]) continue;
        dfs(i,edges,vis);
        ++k;
        if(prev!=-1)
        v.push_back({prev,i});
        prev=i;
    }
    cout<<k-1<<'\n';
    for(auto x:v){
        cout<<x.first+1<<' '<<x.second+1<<'\n';
    }
}