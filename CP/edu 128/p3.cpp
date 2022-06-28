#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    string s;cin>>s;
    int n=s.size();
    vector<int>pref(n+1);
    for(int i=0;i<n;++i){
        pref[i+1]=pref[i]+(s[i]=='1');
    }
    int z=0;
    for(int i=0;i<pref[n];++i){
        z+=(s[i]=='0');
    }
    int cost=n+10,i=0;
    for(int j=pref[n]-1;j<n;++j){
        cost = min(cost, max(z,pref[n]-pref[j+1]+pref[i]));
        
        z -= (s[i]=='0');
        ++i;
    }
    cout<<cost<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}