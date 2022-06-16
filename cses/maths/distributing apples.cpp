#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;

int binexp(int a,int b){
    int res=1;
    while(b>0){
        if(b&1){
            res = (res*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;

    }
    return res%mod;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;

    vector<int>facts(2*1e6+1,1);
    for(int i=2;i<=facts.size();++i){
        facts[i]=(facts[i-1]*i)%mod;
    }
    
    int ans=facts[n+m-1]%mod;
    ans = (ans * binexp(facts[n-1],mod-2)%mod)%mod;
    ans = (ans * binexp(facts[m],mod-2)%mod)%mod;
    cout<<ans<<'\n';
}