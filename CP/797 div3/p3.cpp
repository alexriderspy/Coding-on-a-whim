#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int>s(n),f(n);
    vector<int>d(n);
    for(int i=0;i<n;++i) cin>>s[i];
    for(int i=0;i<n;++i) cin>>f[i];
    d[0]=f[0]-s[0];
    cout<<d[0]<<' ';
    for(int i=1;i<n;++i){
        d[i]=f[i]-(max(s[i],f[i-1]));
        cout<<d[i]<<' ';
    }
    cout<<'\n';
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}