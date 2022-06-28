#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n,m;cin>>n>>m;
    vector<string>a(n);
    
    for(int i=0;i<n;++i) cin>>a[i];
    int l=10,u=10;
    for (int i=0;i<n;i++){
        for(int j=0;j<m;++j){
            if(a[i][j]=='R'){
                l=min(l,j+1);
                u=min(u,i+1);
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(a[i][j]=='R' && l==j+1 && u == i+1){
                cout<<"YES\n";return;
            }
        }
    }
    cout<<"NO\n";
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}