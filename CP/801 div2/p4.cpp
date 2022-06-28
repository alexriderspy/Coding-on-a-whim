#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2005;
vector<int>edges[N];

void solve(){
    int n;cin>>n;
    for(int i=0;i<n-1;++i){
        int u,v;cin>>u>>v;
        --u,--v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
        
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}