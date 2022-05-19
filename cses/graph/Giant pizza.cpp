//2sat problem
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

vector<int>comp;
void dfs2(int u,int c){
    vis[u]=1;
    comp[u]=c;
    for(int v:rev_edges[u]){
        if(!vis[v])
        dfs2(v,c);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    swap(n,m);
    n*=2;
    edges = vector<vector<int>>(n);
    rev_edges=vector<vector<int>>(n);;
    
    for(int i=0;i<m;++i){
        int a, b; 
        char u,v;
        cin>>u>>a>>v>>b;
        --a,--b;
        bool na = (u=='-');
        bool nb = (v=='-');
        a = 2*a ^ na;
        b = 2*b ^ nb;
        int neg_a = a ^ 1;
        int neg_b = b ^ 1;
        edges[neg_a].push_back(b);
        edges[neg_b].push_back(a);
        rev_edges[b].push_back(neg_a);
        rev_edges[a].push_back(neg_b);
    }

    vis.assign(n,0);
    for(int i=0;i<n;++i){
        if(vis[i]==1) continue;
        dfs1(i);
    }
    vis.assign(n,0);
    int c=1;
    comp.assign(n,-1);

    for(int i=n-1;i>=0;--i){
        if(vis[order[i]]==1) continue;
        dfs2(order[i],c);
        ++c;
    }

    vector<char>ans(n/2);
    for(int i=0;i<n;i+=2){
        if(comp[i] == comp[i+1]){
            cout<<"IMPOSSIBLE\n";return 0;
        }
        ans[i/2] = (comp[i] > comp[i+1])?'+':'-';
    }
    for(int i=0;i<n/2;++i){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}