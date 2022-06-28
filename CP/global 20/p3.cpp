#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    int ans=0,st=-1,en=-1,f=0;
    for(int i=0;i<n-1;++i){
        if(a[i]==a[i+1] && f==0){
            st=i+1;f=1;
            continue;
        }
        if(a[i]==a[i+1] && f==1){
            en=i-1;
        }
    }
    if(en==-1){
        cout<<0<<'\n';
    }else{
        if(en<st){
            cout<<1<<'\n';
        }else
            cout<<en-st+1<<'\n';
    }    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}