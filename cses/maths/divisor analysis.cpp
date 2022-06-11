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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    int x=1,sum=1,num=1,num2=1,prod=1;
    vector<pair<int,int>>p(n);
    for(int i=0;i<n;++i){
        cin>>p[i].first>>p[i].second;
        x*=(pow(p[i].first,p[i].second));
        num=(num * (p[i].second+1))%mod;
        int numerator = (p[i].second * (p[i].second+1))/2 ;
        
        sum=(sum*(binexp(p[i].first,p[i].second+1)-1)%mod*binexp(p[i].first-1,mod-2)%mod)%mod;
        
        prod = (binexp(prod,p[i].second+1)%mod * binexp(binexp(p[i].first,numerator)%mod,num2)%mod)%mod;
        num2=(num2 * (p[i].second+1))%(mod-1);
    }

    cout<<num<<' '<<sum<<' '<<prod<<'\n';

}