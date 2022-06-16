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
    string s;cin>>s;
    vector<int>cnt(26);

    vector<int>facts(1e6+1,1);
    for(int i=2;i<=facts.size();++i){
        facts[i]=(facts[i-1]*i)%mod;
    }
    
    for(int i=0;i<s.size();++i){
        cnt[s[i]-'a']++;
    }
    int ans=facts[s.size()]%mod;
    for(int i=0;i<26;++i){
        if(cnt[i]<=1) continue;
        ans = (ans * binexp(facts[cnt[i]],mod-2)%mod)%mod;
    }
    cout<<ans<<'\n';
}