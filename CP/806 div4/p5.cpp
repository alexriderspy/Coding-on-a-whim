#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int> 
#define rep(i,a,b) for (int i=a;i<b;++i)

void solve(){
    int n;cin>>n;
    vector<string>a(n);
    rep(i,0,n) cin>>a[i];
    int ans=0,c1=0,c0=0;
    if(n==1){
        cout<<0<<'\n';return;
    }
    int j=0;
    for(int k=n;k>=2;k-=2){
        
        rep(i,j,k){
            c1=0;
            c1 += (a[k-1-j][i]=='1');
            c1 += (a[i][j]=='1');
            c1 += (a[k-1-i][k-1-j]=='1');
            c1 += (a[j][k-1-i]=='1');
            ans+=min(c1,4-c1);
        }
        ++j;
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--) solve();
}