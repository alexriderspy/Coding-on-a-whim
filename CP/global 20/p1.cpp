#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n,s=0;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i],s+=(a[i]-1);
    if(s%2){
        cout<<"errorgorn\n";
    }else{
        cout<<"maomao90\n";
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}