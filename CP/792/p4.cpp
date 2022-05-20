#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solve(){
    int n,k;cin>>n>>k;
    vector<pair<int,int>>a(n);
    int sum=0;
    for(int i=0;i<n;++i){
        cin>>a[i].first;
        a[i].first-=(n-i-1);
        a[i].second=i;
    }    
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for(int i=0;i<k;++i){
        sum+=(n-a[i].second-1);
    }
    
    for(int i=k;i<n;++i){
        sum+=(a[i].first+(n-a[i].second-1));
    }
    
    sum-=(k*(k-1))/2;
    cout<<sum<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}