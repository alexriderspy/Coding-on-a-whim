#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    vector<pair<int,int>> a(4);
    for(int i=0;i<4;++i) cin>>a[i].first,a[i].second=i;
    sort(a.begin(),a.end());
    for(int i=0;i<4;++i){
        if(a[i].second==0){
            cout<<4-i-1<<'\n';return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}