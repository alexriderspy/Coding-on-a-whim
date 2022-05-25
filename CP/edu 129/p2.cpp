#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    int m;cin>>m;
    vector<int>b(m);
    int x=0;
    for(int i=0;i<m;++i) cin>>b[i],x+=b[i];
    x%=n;
    cout<<a[x]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}