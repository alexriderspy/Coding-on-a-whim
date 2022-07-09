#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;cin>>n;
    if(n%2){
        cout<<-1<<'\n';
    }else{
        cout<<0<<' '<<0<<' '<<n/2<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}