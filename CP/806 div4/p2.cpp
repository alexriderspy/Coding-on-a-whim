#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int> 
#define rep(i,a,b) for (int i=a;i<b;++i)

void solve(){
    int n;cin>>n;
     string s;cin>>s;
     vi a(26,0);
     int ans=n;
     rep(i,0,n) {
        a[s[i]-'A']++;
        if(a[s[i]-'A']==1){
            ans++;
        }

     }
     cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    int t;cin>>t;
    while(t--) solve();
}