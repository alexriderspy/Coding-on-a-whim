#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        vector<int>pref(n);
        pref[0]=a[0];
        for(int i=1;i<n;++i){
            pref[i]=pref[i-1]+a[i];
        }
        if(k<=n){
            int ans=0;
            for(int i=k-1;i<n;++i){
                ans = max(ans, k-1+pref[i]-(i>=k?pref[i-k]:0));
            }
            cout<<ans<<'\n';
        }else{
            
        }
    }
}