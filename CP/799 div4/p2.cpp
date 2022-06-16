#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;cin>>n;
    vector<int>a(1e4+2);
    for(int i=0;i<n;++i){
        int x;cin>>x;
        a[x]++;
    }
    int ans=0;
    int c=0;
    for(int i=0;i<1e4+1;i++){
        ans+=a[i]%2;
        if(a[i]>=2 && a[i]%2==0){
            ++c;
        }
        if(c==2){
            ans+=2;
            c=0;
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}