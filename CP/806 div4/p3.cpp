#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int> 
#define rep(i,a,b) for (int i=a;i<b;++i)

void solve(){
    int n,x;cin>>n;
    string s;
    vi a(n);
    rep(i,0,n) cin>>a[i];
    rep(i,0,n){
        cin>>x;
        cin>>s;
        rep(j,0,x){
            if(s[j]=='D'){
                a[i]=(a[i]+1)%10;
            }else{
                a[i]=(a[i]-1+10)%10;
            }
        }
    }
    rep(i,0,n){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--) solve();
}