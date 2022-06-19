#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=n-1;i>=0;--i){
        if(a[i]!=0) break;
        a.pop_back();
    }
    n=a.size();
    int x=0;
    for(int i=0;i<n;++i){
        x+=a[i];
        if(i==n-1) break;
        if(x<=0){
            cout<<"No\n";return;
        }
    }
    if(x!=0){
        cout<<"No\n";return;
    }
    cout<<"Yes\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}
