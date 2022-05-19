#include<cmath>
#include<iostream>

using namespace std;

const int mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    long long sum=0;
    for(int i=1;i<=n;++i){
        sum=(sum+i*(n/i))%mod;
    }
    cout<<sum<<'\n';
}