#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;cin>>n;
    int odd=0,eve=0;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i],a[i]%2==0?eve++:odd++;
    vector<int>even(n);
    for(int i=0;i<n;++i){
        for(int j=0;j<=31;++j){
            if(a[i]&(1<<j)){
                even[i]=j;break;
            }
        }
    }
    sort(even.begin(),even.end());
    if(odd){
        cout<<eve<<'\n';
    }else{
        cout<<eve-1 + even[0]<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}