#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];
    vector<int>an[n+1];
    vector<int>bn[n+1];
    for(int i=0;i<n;++i){
        an[a[i]].push_back(i);
        bn[b[i]].push_back(i);
    }
    

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}