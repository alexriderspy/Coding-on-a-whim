#include<bits/stdc++.h>
using namespace std;

vector<int>values;
vector<vector<int>>edges;
vector<int>timer;

void dfs(int u,int p){
    timer.push_back(u);
    for(int v:edges[u]){
        if(v!=p){
            dfs(v,u);
        }
    }
    timer.push_back(u);
    
}

vector<int>segtree;
int main(){
    int n,q;cin>>n>>q;
    for(int i=0;i<n;++i) cin>>values[i];
    edges=vector<vector<int>>(n);
    for(int i=0;i<n-1;++i){
        int u,v;cin>>u>>v;
        --u,--v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(0,-1);
    segtree=vector<int>(4*n);
    for(int i=2*n;i<4*n;++i){
        segtree[i]=timer[i-2*n];
    }

    while(q--){
        int t;cin>>t;
        if(t==1){
            int node,x;cin>>node>>x;
            node--;

        }else{
            int node;cin>>node;
            node--;
        }
    }
}


