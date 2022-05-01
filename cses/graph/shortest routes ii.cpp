//floyd warshall - multi source shortest path

#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>

using namespace std;

int n,m;
const int N = 500;
const long long oo = LLONG_MAX;

long long adj[N][N];
int main(){
    int q;
    cin>>n>>m>>q;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            adj[i][j]=oo;
        }
        adj[i][i]=0;
    }
    
    for(int i=0;i<m;++i){
        long long u,v,w;cin>>u>>v>>w;
        --u,--v;
        adj[u][v]=min(adj[u][v],w); //number of edges was <= n^2, so it is not a simple graph hence we need to ensure this
        adj[v][u]=min(adj[u][v],w);
    }

    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(adj[i][k]==oo || adj[k][j] == oo) continue;
                adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
            
            }
        }
    }

    while(q--){
        int u,v;cin>>u>>v;
        --u,--v;
        if(adj[u][v]==oo) cout<<-1<<'\n';
        else
        cout<<adj[u][v]<<'\n';
    }
}