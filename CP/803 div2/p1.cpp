#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,a,b) for(int i=a;i<b;++i)

void solve(){
    int n;cin>>n;
    vector<int>a(n);
    rep(i,0,n) cin>>a[i];
    rep(i,0,n){
        int x=0;
        rep(j,0,n){
            if(j==i) continue;
            x^=a[j];
        }
        if(x==a[i]){
            cout<<x<<'\n';return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--) solve();
}