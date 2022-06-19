#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>>edges;
vector<pair<int,int>>boun;

int ans=0;
int dfs(int u,int p=-1){
    int ch = 0;
    for(int v:edges[u]){
        ch += dfs(v,u);
        
    }
    if(ch < boun[u].first){
        ans++;return boun[u].second;
    }else{
        return min(boun[u].second,ch);
    }
}
void solve(){
    int n;cin>>n;
    ans=0;
    edges = vector<vector<int>>(n);
    for(int i=1;i<n;++i){
        int x;cin>>x;
        --x;
        edges[x].push_back(i);
    }
    boun = vector<pair<int,int>>(n);    
    for(int i=0;i<n;++i){
        cin>>boun[i].first>>boun[i].second;
    }
    dfs(0);
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}

