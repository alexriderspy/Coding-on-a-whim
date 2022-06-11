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
    int n;cin>>n;
    while(n--){
        int a,b;cin>>a>>b;
        if(b==0) {
            cout<<1<<'\n';continue;
        }
        cout<<binexp(a,b)<<'\n';
   }
}