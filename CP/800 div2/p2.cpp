#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int ans=n;
    int z=0,o=0;
    s[0]=='0'?z++:o++;
    for(int i=1;i<n;++i){
        if(s[i]=='0'){
            ++z,o=0;
        }else{
            ++o,z=0;
        }
        if(z<2 && o<2){
            ans+=i;
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
