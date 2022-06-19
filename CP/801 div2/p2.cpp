#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;cin>>n;
    vector<int>a(n);
    
    for(int i=0;i<n;++i) cin>>a[i];
    if(n%2){
        cout<<"Mike\n";return;
    }
    int m=1e9+2;
    for(int i=0;i<n;i++){
        if(a[i]<m){
            m=a[i];
        }
    }
    
    for(int i=0;i<n;++i){
        if(a[i]==m){
            if(i%2==0){
                cout<<"Joe\n";
            }else{
                cout<<"Mike\n";
            }
            return;
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