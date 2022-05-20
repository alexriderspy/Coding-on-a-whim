#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int>a(n);
    map<int,int>mp;
    for(auto &x:a) cin>>x,mp[x]++;
    int ans=0;
    int maxi=0;
    for(auto x:mp){
        maxi=max(maxi,x.second);
    }
    cout<<(n-maxi)/maxi + (n-maxi)<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

}