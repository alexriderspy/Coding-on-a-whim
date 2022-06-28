#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,a,b) for (auto i=(a);i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    int ans=0;
    for(int i=1;i<n;++i){
        if(a[i]==0 && a[i-1]) ans++;
    }
    if(a[n-1]) ans++;
    cout<<(min(ans,(int)2))<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}