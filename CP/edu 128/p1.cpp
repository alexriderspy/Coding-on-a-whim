#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int l1,r1,l2,r2;cin>>l1>>r1>>l2>>r2;
    if(r1<l2 || r2<l1){
        cout<<l1+l2<<'\n';
    }else{
        cout<<max(l1,l2)<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}