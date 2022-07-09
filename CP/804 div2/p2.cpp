#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n,m,f=0,g=0;cin>>n>>m;
    vector<vector<int>>ans(4,vector<int>(4));
    ans[0] = {1,0,0,1};
    ans[1] = {0,1,1,0};
    ans[2]=ans[1];
    ans[3]=ans[0];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cout<<ans[i%4][j%4]<<' ';
        }
        cout<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}