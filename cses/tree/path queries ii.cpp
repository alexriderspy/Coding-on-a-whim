#include<bits/stdc++.h>
using namespace std;

vector<int>values;
vector<vector<int>>edges;
vector<int>timer;

vector<int>st,en;

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

vector<long long int>segtree;

long long int f(int node,int node_left,int node_right,int query_low,int query_high){
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
    cout.tie(0);
    int n,q;cin>>n>>q;
    values.assign(n,0);
    st.assign(n,0);
    en.assign(n,0);
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
    segtree.assign(n*2,0);
    for(int i=n;i<2*n;++i){
        if(st[timer[i-n]]==i-n)
            segtree[i]=values[timer[i-n]];
        else
            segtree[i]=-values[timer[i-n]];
        
    }
    for(int i=n-1;i>=1;--i){
        segtree[i]=segtree[2*i]+segtree[2*i+1];
    }
    segtree[0]=-1;
    while(q--){
        int t;cin>>t;
        if(t==1){
            int node;
            long long x;cin>>node>>x;
            node--;
            segtree[st[node]+n]=x;
            segtree[en[node]+n]=-x;
            for(int i=(st[node]+n)/2;i>=1;i/=2){
                segtree[i]=max(segtree[2*i],segtree[2*i+1]);
            }
            for(int i=(en[node]+n)/2;i>=1;i/=2){
                segtree[i]=segtree[2*i]+segtree[2*i+1];
            }
        }else{
            int a,b;cin>>a>>b;
            --a,--b;
            cout<<f(1,0,n-1,st[a],st[b])<<'\n';
        }
    }
}


