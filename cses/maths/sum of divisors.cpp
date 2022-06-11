#include<cmath>
#include<iostream>

using namespace std;

#define int long long

const int mod = 1e9+7;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    int sum=0;
    int i=1,j;
    while(i<=n){
        j=(n/(n/i))+1;
        int x=(j-i);
        int y=(i+j-1);
        if(x%2==0) x/=2;
        else y/=2;
        x%=mod;
        y%=mod;
        sum = sum + ((((n/i)%mod)*x)%mod*y)%mod;
        sum%=mod;
        i=j;
    }
    cout<<sum<<'\n';
}