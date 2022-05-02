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
    for(int i:edges[u]){
        if(!vis[i]) dfs(i);
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
    vector<bool>recStack(n);
    if(isCycle(0,recStack)){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }    
    for(int &i:vis) i=0;
    dfs(0);
    if(vis[n-1]==0){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    
    vector<int>dp(n);
    dp[0]=1;
    vector<int>par(n,-1);
    reverse(ans.begin(),ans.end());
    for(int i=0;i<(int)ans.size();++i){
        for(int j:edges[ans[i]]){
            if(dp[j] < dp[ans[i]]+1){
                dp[j] = dp[ans[i]]+1;
                par[j] = ans[i];
            }
        }
    }
    int k=n-1;
    ans.clear();
    while(k!=-1){
        ans.push_back(k);
        k=par[k];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(int i:ans) cout<<i+1<<' ';
    cout<<'\n';
}