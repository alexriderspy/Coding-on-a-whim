#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    int ans=0,p=1;
    for(int i=1;i<n;++i){
        if(a[i]<a[i-1]){
            ++p;
        }else{
            ans+=(p/2);
            p=1;
        }
    }
    if(p!=1){ans+=(p/2);}
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}