#include<iostream>
#include <queue>
#include <vector>
#include<algorithm>
#include <climits>
#include <map>
#include <numeric>

using namespace std;

#define pii pair<int,int>

const int N  = 1e5;

vector<int>edges[N];

vector<int>ans;
vector<int>vis(N);

bool possible = true;

bool isCycle(int u,vector<bool> &recStack){
    vis[u]=1;
    recStack[u]=true;
    for(int v:edges[u]){
        if(!vis[v] && isCycle(v,recStack)){
            return true;
        }else if(recStack[v] == true){
            return true;
        }
    }
    recStack[u]=false;
    return false;
}

void dfs(int u){
    vis[u]=1;
    for(auto v:edges[u]){
        if(!vis[v]){
            dfs(v);

        }
    }
    ans.push_back(u);
}
signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        --u,--v;
        edges[u].push_back(v);
    }    
    vector<bool>recStack(n,false);
    for(int i=0;i<n;++i){
        if(!vis[i] && isCycle(i,recStack)){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }
    for(int i=0;i<n;++i) vis[i]=0;
    for(int i=0;i<n;++i){
        if(vis[i]) continue;
        dfs(i);
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<n;++i){
        cout<<ans[i]+1<<' ';
    }
    cout<<'\n';
}