#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;cin>>n;
    vector<int>a(n);
    
    for(int i=0;i<n;++i) cin>>a[i];
    if(n==1){
        cout<<-1<<'\n';return;
    }
    vector<int>p(n);
    for(int i=0;i<n;++i) p[i]=i+1;
    
    for(int i=0;i<n-1;++i){
        if(a[i]==p[i]){
            
            swap(p[i],p[i+1]);
            
        }
    }
    if(p[n-1] == a[n-1]) swap(p[n-1],p[n-2]);
    for(int i=0;i<n;++i) cout<<p[i]<<' ';
    cout<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}