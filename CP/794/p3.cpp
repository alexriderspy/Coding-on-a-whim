#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a.begin(),a.end());
    vector<int>ans(n);
    int j=0;
    for(int i=0;i<n;i+=2){
        ans[i]=a[j++];
    }
    for(int i=1;i<n;i+=2){
        ans[i]=a[j++];
    }

    for(int i=0;i<n;++i){
        if((ans[i%n]<ans[(i+1)%n] && ans[i%n]<ans[(i-1+n)%n]) || (ans[i%n]>ans[(i+1)%n] && ans[i%n]>ans[(i-1+n)%n])){
            continue;
        }else{
            cout<<"NO\n";return;
        }
    }
    cout<<"YES\n";
    for(auto x:ans) cout<<x<<' ';
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}