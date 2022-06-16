#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>derange(n+1);
    derange[1]=0,derange[2]=1;
    for(int i=3;i<=n;++i){
        derange[i]=((derange[i-1]+derange[i-2])%mod*(i-1))%mod;
    }
    cout<<derange[n]%mod<<'\n';
}