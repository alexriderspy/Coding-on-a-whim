#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n,m;cin>>n>>m;
    int x,bi=0,bj=0,ms=-1e9-100,ans;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>x;
            if(x>ms){
                ms=x;
                bi=i,bj=j;
                ans=max(abs(-bi+n),abs(bi+1))*max(abs(-bj+m),abs(bj+1));
            }
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}