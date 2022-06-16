#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n,q;cin>>n>>q;
    vector<int>a(n),p(n+1);
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=0;i<n;++i){
        p[i+1]=p[i]+a[i];
    }
    while(q--){
        int x,y;cin>>x>>y;
        cout<<-p[n-1-x+1]+p[n-1-x+1+y]<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
}