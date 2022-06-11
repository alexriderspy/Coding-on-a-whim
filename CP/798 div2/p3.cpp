#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>>edges;
vector<int>child;

void dfs(int u,int p=-1){
    for(int v:edges[u]){
        if(v==p) continue;
        dfs(v,u);
        child[u]+=(child[v]+1);
    }
    
}
vector<int>dp;

void dfs2(int u,int p=-1){

    if(edges[u].size()==2){
        int a=edges[u][0];
        int b=edges[u][1];

        if(a==p)
            dfs2(b,u),
            dp[u]=max(dp[b],child[b]);
        else
            dfs2(a,u),
            dp[u]=max(dp[a],child[a]);

    }else if (edges[u].size()==3){
        int a=edges[u][0];
        int b=edges[u][1];
        int c=edges[u][2];

        if(a==p)
            dfs2(b,u),dfs2(c,u),
            dp[u]=max(dp[c]+child[b],dp[b]+child[c]);
        else if(b==p)
            dfs2(a,u),dfs2(c,u),
            dp[u]=max(dp[c]+child[a],dp[a]+child[c]);
        else
            dfs2(b,u),dfs2(a,u),
            dp[u]=max(dp[a]+child[b],dp[b]+child[a]);

    }
}

void solve(){
    int n;cin>>n;
    edges = vector<vector<int>>(n);

    for(int i=0;i<n-1;++i){
        int u,v;cin>>u>>v;
        --u,--v;
        edges[u].push_back(v);
        edges[v].push_back(u); 
    }
    edges[0].push_back(-1);
    
    child=vector<int>(n);
    dp = vector<int>(n);
 
    dfs(0);
    dfs2(0);    
 
    cout<<dp[0]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}