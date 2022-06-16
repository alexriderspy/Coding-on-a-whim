#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;

int binexp(int a,int b){
    if(b==0) return 1;
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
    string s;cin>>s;
    int up=0,down=0;
    for(int i=0;i<s.size();++i) {
        s[i]=='('?up++:down++;
        if(down>up){
            cout<<0<<'\n';return 0;
        }
    }
    if(n%2 || up>n/2){
        cout<<0<<'\n';return 0;
    }
    if(up==n/2){
        cout<<1<<'\n';return 0;
    }
    vector<int>facts(1e6+1,1);
    for(int i=2;i<=facts.size();++i){
        facts[i]=(facts[i-1]*i)%mod;
    }
    int tot,extra,sz=n-(int)s.size();

    int num1=facts[sz],num2=facts[(abs(up-down)+sz)/2],num3=facts[sz-(abs(up-down)+sz)/2];
    tot = (num1%mod *(binexp((num2*num3)%mod,mod-2)%mod))%mod;
    
    num2=facts[(abs(up-down)+2+sz)/2],num3=facts[sz-((abs(up-down)+2+sz)/2)];
    extra = (num1%mod *(binexp((num2*num3)%mod,mod-2)%mod))%mod;
    cout<<(tot-extra+mod)%mod<<'\n';
}