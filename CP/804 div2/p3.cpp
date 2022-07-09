#include<bits/stdc++.h>
using namespace std;

#define int long long

int mod = 1e9+7;

void solve(){
    int n,x;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>x,a[x]=i;
    int l=min(a[0],a[1]);
    int r=max(a[0],a[1]);
    int ans=1;
    for(int i=2;i<n;++i){
        if(a[i]>=l && a[i]<=r){
            ans = (ans * (r-l+1-i))%mod;
        }else{
            if(a[i]<l){
                l=a[i];
            }else{
                r=a[i];
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