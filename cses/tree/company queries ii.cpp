#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
const int LOG = 18;

int up[LOG][N];
int depth[N];
vector<int>edges[N];

void dfs(int u,int p){
    for(auto v:edges[u]){
        if(v!=p) depth[v]=depth[u]+1,dfs(v,u);
    }
}
int main(){
    int a,n,q;cin>>n>>q;
    
    for(int i=2;i<=n;++i){
        cin>>a;
        up[0][i]=(a);
        edges[a].push_back(i);
    }
    dfs(1,-1);
    for(int i=1;i<LOG;++i){
        for(int j=1;j<=n;++j){
            up[i][j]=up[i-1][up[i-1][j]];
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        if(depth[a]>depth[b]){
            swap(a,b);
        }
        int diff= depth[b]-depth[a];
        for(int i=0;i<LOG;++i){
            if(diff&(1<<i)) b=up[i][b];
        }
        if(a==b){
            cout<<a<<'\n';continue;
        }
        for(int i=LOG-1;i>=0;--i){
            if(up[i][a]!=up[i][b]){
                a=up[i][a];
                b=up[i][b];
            }
        }
        cout<<up[0][a]<<'\n';
    }
}