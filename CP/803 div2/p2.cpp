#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,a,b) for(int i=a;i<b;++i)

void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n);
    rep(i,0,n) cin>>a[i];
    if(k==1){
        cout<<((n%2==0)?(n/2)-1:n/2)<<'\n';return;
    }
    int ans=0;
    rep(i,1,n){
        if(i+1<n){
            ans +=(a[i]>(a[i-1]+a[i+1]));
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--) solve();
}