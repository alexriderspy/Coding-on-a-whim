#include<bits/stdc++.h>

using namespace std;

#define int long long

vector<int>vis;
vector<vector<int>>edges,rev_edges;
vector<int>order;

void dfs1(int u,vector<vector<int>>&edges){
    vis[u]=1;
    for(int v:edges[u]){
        if(!vis[v])
        dfs1(v,edges);
    }
    order.push_back(u);
}

vector<int>roots,root_nodes,coins_t,coins;
vector<vector<int>>adj_scc;

void dfs2(int u,int &x){
    vis[u]=1;
    roots[u]=x;
    coins_t[x]+=coins[u];
    for(int v:rev_edges[u]){
        if(!vis[v])
        dfs2(v,x);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    edges = vector<vector<int>>(n);
    rev_edges=vector<vector<int>>(n);;
    coins.assign(n,0);
    coins_t.assign(n,0);

    for(int i=0;i<n;++i) cin>>coins[i];

    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        --u,--v;
        edges[u].push_back(v);
        rev_edges[v].push_back(u);
    }

    vis.assign(n,0);
    for(int i=0;i<n;++i){
        if(vis[i]==1) continue;
        dfs1(i,edges);
    }
    
    vis.assign(n,0);

    roots.assign(n,0);

    for(int i=n-1;i>=0;--i){
        if(vis[order[i]]==1) continue;
        dfs2(order[i],order[i]);
        root_nodes.push_back(order[i]);
    }
    adj_scc=vector<vector<int>>(n);
    vis.assign(n,0);
    for(int i=0;i<n;++i){
        for(int v:edges[i]){
            int root_i=roots[i];
            int root_v=roots[v];
            if(root_i!=root_v)
            adj_scc[root_i].push_back(root_v);
        }
    }
    order.clear();
    vis.assign(n,0);

    for(int i=0;i<root_nodes.size();++i){
        if(vis[root_nodes[i]]==1) continue;
        dfs1(root_nodes[i],adj_scc);
    }

    vector<int>dp(n);
    reverse(order.begin(),order.end());
    for(int i=0;i<root_nodes.size();++i){
        int u=order[i];
        dp[u]=max(dp[u],coins_t[u]);
        for(int v:adj_scc[u]){
            dp[v]=max(dp[v],dp[u]+coins_t[v]);
        }
    }
    for(int i=0;i<n;++i) dp[n-1]=max(dp[i],dp[n-1]);
    cout<<dp[n-1]<<'\n';
}