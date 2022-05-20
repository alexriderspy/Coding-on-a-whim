#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    vector<int>from[n];
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        --u,--v;
        from[v].push_back(u);
    }
    vector<vector<long long>>dp((1<<n),vector<long long>(n,0));
    dp[1][0]=1;

    for(int i=1;i<(1<<n);++i){
        if((i&(1<<0))==0) continue;
        for(int k=0;k<n;++k){
            if((i&(1<<k))==0) continue;
            for(int v:from[k]){
                if(i&(1<<v)){
                    dp[i][k] = (dp[(i^(1<<k))][v] + dp[i][k])%mod;
                }
            }
        }
    }

    cout<<dp[(1<<n)-1][n-1]<<'\n';
}