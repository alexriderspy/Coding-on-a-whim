//difference array technique

#include<bits/stdc++.h>
using namespace std;

const int LOG = 20;
const int N = 2e5+2;

vector<int>edges[N];
int up[LOG][N];
vector<int>depth;

void dfs(int u,int p){
    for(int v:edges[u]){
        if(v!=p){
            up[0][v]=u;
            depth[v]=depth[u]+1;
            dfs(v,u);
        }
    }
}

//depth[a]<depth[b]
int findLCA(int a,int b){
    if(depth[a]>depth[b]){
        swap(a,b);
    }
    int diff = depth[b]-depth[a];
    for(int i=LOG-1;i>=0;--i){
        if(diff&(1<<i)){
            b=up[i][b];
        }
    }
    if(b==a){
        return a;
    }
    for(int i=LOG-1;i>=0;--i){
        if(up[i][a]!=up[i][b]){
            a=up[i][a];
            b=up[i][b];
        }
    }
    return up[0][a];
}
vector<int>prefix;

void dfs2(int u,int p){
    for(int v:edges[u]){
        if(v!=p){
            
            dfs2(v,u);
            prefix[u]+=prefix[v];
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;

    map<pair<int,int>,int>mp;

    for(int i=0;i<n-1;++i){
        int u,v;
        cin>>u>>v;
        if(mp[{u,v}] || mp[{v,u}]) continue;
        mp[{u,v}]++;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    depth.assign(n+1,0);
    dfs(1,0);
    for(int i=1;i<LOG;++i){
        for(int j=1;j<=n;++j){
            up[i][j]=up[i-1][up[i-1][j]];
        }
    }
    prefix=vector<int>(n+1);
    for(int i=0;i<m;++i){
        int a,b;cin>>a>>b;
        prefix[a]++;
        prefix[b]++;
        int lca=findLCA(a,b);
        
        prefix[lca]--;
        prefix[up[0][lca]]--;
    }
    dfs2(1,0);
    for(int i=1;i<=n;++i) cout<<prefix[i]<<' ';
    cout<<'\n';
}