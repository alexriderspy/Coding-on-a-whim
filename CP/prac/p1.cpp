#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n,m;cin>>n>>m;
    vector<int>a(m);
    map<int,int>mp;
    for(int i=0;i<m;++i) cin>>a[i],mp[a[i]]++;
    multiset<int>mt;
    if(n==1){
        cout<<m<<'\n';return;
    }
    for(auto i:mp){
        mt.insert(i.second);
    }
    for(int i=0;i<(n-(int)mp.size());++i){
        mt.insert(0);
    }
    int ans=*mt.rbegin();
    while(1){
        int x=*mt.begin(),y=*mt.rbegin();
        mt.erase(mt.find(x));
        mt.erase(mt.find(y));
        if(max(x+2,y-1) >= ans){
            break;
        }
        ans=max(x+2,y-1);
        mt.insert(x+2);
        mt.insert(y-1);

    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;cin>>t;
    while(t--){
        solve();
   }
}