#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n,t;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    int q;cin>>q;
    while(q--){
        cin>>t;
        int over=0,ans=0;
        for(int i=0;i<n;++i){
            if(t<(a[i]-over)){
                cout<<-1<<'\n';break;
            }
            over = t-a[i]-over;            
        }        
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
}