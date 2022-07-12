#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int> 
#define rep(i,a,b) for (int i=a;i<b;++i)

void solve(){
    int n;cin>>n;
    vi a(n);
    vi b;
    vector<pair<int,int>> c;
    rep(i,0,n) {
        cin>>a[i];
        if(a[i]<i+1)
        b.push_back(a[i]),c.push_back({a[i],i+1});
    }
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    int ans=0;
    rep(i,0,b.size()){
        int index = lower_bound(b.begin(),b.end(),c[i].second+1)-b.begin();
        if(index<b.size()){
            ans+=(b.size()-1-index+1);
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--) solve();
}