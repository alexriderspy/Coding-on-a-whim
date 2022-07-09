#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n,m;cin>>n>>m;
    vector<int>a(m);
    vector<int>mp(n);
    for(int i=0;i<m;++i) cin>>a[i],mp[a[i]-1]++;
    int l=1, r=2*m,mid;
    while(l<r){
        mid = (l+r)/2;
        int need=0,get=0;
        for(int i=0;i<n;++i){
            if(mp[i]<mid){
                get += (mid - mp[i])/2;
                
            }else{
                need += (mp[i] - mid);
                
            }
        }
        if(need>get){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    cout<<r<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;cin>>t;
    while(t--){
        solve();
   }
}