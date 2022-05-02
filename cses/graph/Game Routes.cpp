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
const int mod = 1e9+7;

vector<int>edges[N];

vector<int>ans;
vector<int>vis(N);

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
    dfs(0);    
    vector<int>dp(n);
    dp[0]=1;
    reverse(ans.begin(),ans.end());
    for(int i=0;i<(int)ans.size();++i){
        for(int j:edges[ans[i]]){
            dp[j] = (dp[ans[i]] + dp[j])%mod;
        }
    }
    cout<<dp[n-1]<<'\n';
}