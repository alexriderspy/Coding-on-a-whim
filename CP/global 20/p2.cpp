#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    string s;cin>>s;
    int n=s.size();
    int c=0;
    if(n<=1){
        cout<<"NO\n";return;
    }
    for(int i=0;i<n;++i){
        if(s[i]=='A') ++c;
        else --c;
        if(c<0 || c==n || s[n-1]=='A'){
            cout<<"NO\n";return;
        }
    }
    cout<<"YES\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}