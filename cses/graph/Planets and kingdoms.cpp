//the fact that one planet can reach all others and all other planets can
//reach the planet implies any city can reach another city

#include<bits/stdc++.h>

using namespace std;

vector<int>vis;

vector<vector<int>>edges,rev_edges;

vector<int>order;

void dfs1(int u){
    vis[u]=1;
    for(int v:edges[u]){
        if(!vis[v])
        dfs1(v);
    }
    order.push_back(u);
}

vector<int>ans;
void dfs2(int u,int c){
    vis[u]=1;
    ans[u]=c;
    for(int v:rev_edges[u]){
        if(!vis[v])
        dfs2(v,c);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    edges = vector<vector<int>>(n);
    rev_edges=vector<vector<int>>(n);;
    
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        --u,--v;
        edges[u].push_back(v);
        rev_edges[v].push_back(u);
    }
    vis=vector<int>(n);
    for(int i=0;i<n;++i){
        if(vis[i]==1) continue;
        dfs1(i);
    }
    vis=vector<int>(n);
    int c=1;
    ans=vector<int>(n);

    for(int i=n-1;i>=0;--i){
        if(vis[order[i]]==1) continue;
        dfs2(order[i],c);
        ++c;
    }
    cout<<c-1<<'\n';
    for(int i=0;i<n;++i){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}