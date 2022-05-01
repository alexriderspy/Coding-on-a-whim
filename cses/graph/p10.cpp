//bellman ford looking at the constraints - O(VE) and negative edges so
//max length of SSSP is n-1 edges always where n is number of vertices

#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>

using namespace std;

#define int long long

struct node{
    int u,v,w;
};
const int N=2500;

vector<int>adj[N];
vector<int>vis(N,0);

void dfs(int u){
    vis[u]=1;
    for(int v:adj[u]){
        if(vis[v]) continue;
        dfs(v);
    }
}

const int oo = LLONG_MAX;

signed main(){
    int n,m;
    cin>>n>>m;
    vector<node>edges(m);
    for(int i=0;i<m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        --u,--v;
        adj[u].push_back(v);
        edges[i] = {u,v,-w};
    }

    vector<long long>dist(n,oo);
    dist[0]=0;
    dfs(0);
    for(int i=0;i<n-1;++i){
        for(auto e:edges){
            if(dist[e.u] == oo) continue;
            dist[e.v] = min(dist[e.v],dist[e.u] + e.w);
        }
    }
    for(auto e:edges){
        if(dist[e.u] != oo && dist[e.u] + e.w < dist[e.v]){
            for(int i=0;i<n;++i) vis[i]=0;
            dfs(e.u);
            if(vis[n-1]==1){
                cout<<-1<<'\n';
                return 0;
            }
        }
    }
    cout<<-dist[n-1]<<'\n';
 
}