#include<bits/stdc++.h>

using namespace std;

vector<int>vis;

vector<vector<int>>edges;

vector<int>inStack,disc,low,stack;
void dfs(int u){
    vis[u]=1;
    for(int v:edges[u]){
        if(!vis[v])
        dfs(v);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    edges = vector<vector<int>>(n);
    
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        --u,--v;
        edges[u].push_back(v);
    }

    inStack.assign(n,0);
    
}