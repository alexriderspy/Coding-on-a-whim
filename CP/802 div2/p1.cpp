#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n,m;cin>>n>>m;
    int sum=0;
    sum += (m*(m+1))/2;
    sum += m*((n*(n+1))/2);
    sum -= m;
    cout<<sum<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}