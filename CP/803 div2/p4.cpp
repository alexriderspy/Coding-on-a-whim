#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,a,b) for(int i=a;i<b;++i)

void solve(){
    int n;cin>>n;
    vector<int>a(n);
    rep(i,0,n) cin>>a[i];
    int mid,l=0,r=n-1;
    while(l<r){
        mid = (l+r)/2;
        cout<<'? '<<l+1<<' '<<mid+1<<endl;
        for(int i=l;i<=mid;++i){
            cin>>a[i];
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