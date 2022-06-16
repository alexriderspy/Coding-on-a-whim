#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int s=0,n,m;cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;++i) {
        cin>>a[i];
        if(a[i]>m){
            s+=a[i]-m;
            m=0;
        }else{
            m-=a[i];
        }
    }
    cout<<s<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}