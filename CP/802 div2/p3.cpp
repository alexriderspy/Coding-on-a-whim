#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    int ans=0,p=a[0],s=0;
    for(int i=1;i<n;++i){
        if(a[i]+s<=p){
            ans+=(p-(a[i]+s));
            p=(a[i]+s);
        }else{
            ans += (a[i]+s-p);
            s -= (a[i]+s-p);
        }
    }
    ans+=(abs(p));
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}