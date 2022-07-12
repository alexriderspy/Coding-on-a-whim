#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int> 
#define rep(i,a,b) for (int i=a;i<b;++i)

void solve(){
    string s;cin>>s;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    if(s=="YES"){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    int t;cin>>t;
    while(t--) solve();
}