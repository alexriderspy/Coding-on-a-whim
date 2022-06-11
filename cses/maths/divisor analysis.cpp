#include<bits/stdc++.h>
using namespace std;

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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    int x=1,sum=1,num=1,prod=1;
    vector<pair<int,int>>p(n);
    for(int i=0;i<n;++i){
        cin>>p[i].first>>p[i].second;
        x*=(pow(p[i].first,p[i].second));
        num=(num * (p[i].second+1))%mod;
        sum=(sum*(binexp(p[i].first,p[i].second+1)-1)/(p[i].first-1))%mod;
        int numerator = ((p[i].second * ( p[i].second+1))/2 * (num-1));
        prod = ((binexp(prod,p[i].second+1) * (binexp(p[i].first,numerator))))%mod;
    }

    cout<<num<<' '<<sum<<' '<<prod<<'\n';

}