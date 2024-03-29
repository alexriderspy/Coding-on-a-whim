//flattening a tree into an array!!

#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<int>values;
vector<vector<int>>edges;
vector<int>timer;

map<int,int>st,en;

void dfs(int u,int p){
    timer.push_back(u);
    st[u]=timer.size()-1;
    for(int v:edges[u]){
        if(v!=p){
            dfs(v,u);
        }
    }
    timer.push_back(u);
    en[u]=timer.size()-1;
}

vector<int>segtree;

int f(int node,int node_left,int node_right,int query_low,int query_high){
    if(query_low <= node_left && node_right<=query_high){
        return segtree[node];
    }
    if(query_low > node_right || query_high<node_left){
        return 0;
    }
    int last_in_left = (node_left+node_right)/2;
    return f(2*node,node_left,last_in_left,query_low,query_high)+f(2*node+1,last_in_left+1,node_right,query_low,query_high);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;cin>>n>>q;
    values.assign(n,0);
    for(int i=0;i<n;++i) cin>>values[i];
    edges=vector<vector<int>>(n);
    for(int i=0;i<n-1;++i){
        int u,v;cin>>u>>v;
        --u,--v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(0,-1);
    n*=2;
    while(__builtin_popcount(n)!=1){
        n++;
        timer.push_back(0);
    }
    segtree=vector<int>(2*n);
    for(int i=n;i<2*n;++i){
        segtree[i]=values[timer[i-n]];
    }
    for(int i=n-1;i>=1;--i){
        segtree[i]=segtree[2*i]+segtree[2*i+1];
    }
    segtree[0]=-1;
    while(q--){
        int t;cin>>t;
        if(t==1){
            int node,x;cin>>node>>x;
            node--;
            segtree[st[node]+n]=x;
            segtree[en[node]+n]=x;
            for(int i=(st[node]+n)/2;i>=1;i/=2){
                segtree[i]=segtree[2*i]+segtree[2*i+1];
            }
            for(int i=(en[node]+n)/2;i>=1;i/=2){
                segtree[i]=segtree[2*i]+segtree[2*i+1];
            }
        }else{
            int node;cin>>node;
            node--;
            cout<<f(1,0,n-1,st[node],en[node])/2<<'\n';
        }
    }
}


