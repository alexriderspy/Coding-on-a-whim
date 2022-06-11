#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n,k;cin>>n>>k;
    vector<int>a(k);
    for(int i=0;i<k;++i) cin>>a[i];
    int cnt=0;
    for(int mask=1;mask<(1<<k);++mask){
        int m=n;
        if(__builtin_popcount(mask)%2){
            
            for(int i=0;i<k;++i){
                
                if((1<<i)&mask){
                    m/=a[i];    
                }
            }
            cnt+=m;
        }else{
            for(int i=0;i<k;++i){
                if((1<<i)&mask){
                    m/=a[i];
                }
            }
            cnt-=m;

        }
    }
    cout<<cnt<<'\n';
}