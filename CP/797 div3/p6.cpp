#include<bits/stdc++.h>
using namespace std;

#define int long long

int lcm(int a,int b){
    int lcmf = (a*b)/__gcd(a,b);
    return lcmf;
}
void solve(){
    int x,n;cin>>n;
    string s;cin>>s;
    vector<int>a(n),vis(n);
    for(int i=0;i<n;++i) {
        cin>>a[i];
        --a[i];
    }
    vector<int>len;
    for(int i=0;i<n;++i){
        if(vis[i]) continue;
        int nex=a[i],c=1;
        while(a[nex]!=a[i]){
            ++c;
            nex=a[nex];
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}