#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int m=0,z=0,o=0;cin>>z>>o;
    string a="";
    for(int i=z+o-1;i>=0;){
        if(z)
            a+='0',--z,--i;
        if(o)
            a+='1',--o,--i;
    }
    cout<<a<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}
