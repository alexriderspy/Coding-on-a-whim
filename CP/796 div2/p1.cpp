#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int x;cin>>x;
    int y=0,f=0,g=0;
    int cnt=__builtin_popcount(x);
    if(cnt>=2) ++g;
    for(int i=0;i<31;++i){
        if(f>=1 && g>=1) break;
        if(x&(1<<i)){
            if(f) continue;
            y^=(1<<i);
            ++f;
        }else{
            if(g) continue;
            y^=(1<<i);
            ++g;
        }
    }
    cout<<y<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}