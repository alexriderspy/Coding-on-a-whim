#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<vector<int>>edges;
vector<int>vis;
vector<int>ans;
int f;

vector<int>par;

void dfs(int u,int p){
    vis[u]=1;
    for(int v:edges[u]){
        if(vis[v]){
            if(v==p) continue;
            else{
                
                if(f==1) return;
                f=1;
                int m=par[u];
                ans.push_back(v);
                ans.push_back(u);
                ans.push_back(m);
                while(m!=v){
                    m=par[m];
                    ans.push_back(m);
                }
                
                cout<<ans.size()<<'\n';
                for(int i=0;i<(int)ans.size();++i) cout<<ans[i]+1<<' ';
                cout<<'\n';
                return;
            }
        }else{
            par[v]=u;
            dfs(v,u);
        }
    }   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    edges = vector<vector<int>>(n);
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        --u,--v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vis = vector<int>(n);
    ans = vector<int>(n);
    par= vector<int>(n,-1);

    f=0;
    for(int i=0;i<n;++i){
        if(vis[i]) continue;
        ans.clear();
        dfs(i,-1);
        if(f==1) return 0;
    }   
    cout<<"IMPOSSIBLE\n";
}