#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;cin>>n;
    vector<int>a(n);
    vector<int>dig(10);
    for(int i=0;i<n;++i) cin>>a[i],a[i]%=10,dig[a[i]]++;
    for(int i=0;i<10;++i){
        if(dig[i])
        for(int j=i;j<10;++j){
            if((j!=i && dig[j])||(j==i && dig[j]>=2))
            for(int k=j;k<10;++k){
                if((k!=j && dig[k])||(k==j && j!=i && dig[k]>=2) ||(k==j && j==i && dig[k]>=3) ){
                    if((i+j+k)%10 == 3){
                        cout<<"YES\n";return;
                    }
                }
            }
        }
    }
    cout<<"NO\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}