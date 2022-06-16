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
    int n;
    cin>>n;

    if(n%2){
        cout<<0<<'\n';return 0;
    }else{
        n/=2;
    }
    vector<int>facts(1e6+1,1);
    for(int i=2;i<=facts.size();++i){
        facts[i]=(facts[i-1]*i)%mod;
    }
    
    int ans =(((facts[2*n]%mod * binexp(facts[n]%mod,mod-2)%mod)%mod * binexp(facts[n]%mod,mod-2)%mod)%mod * binexp(n+1,mod-2)%mod)%mod; 
    cout<<ans%mod<<'\n';
}