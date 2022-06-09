#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];
    int x=0;
    for(int i=0;i<n;++i){
        x=max(x,a[i]-b[i]);
    }
    for(int i=0;i<n;++i){
        if((a[i]-b[i])<x){
            if(b[i]!=0){
                cout<<"NO\n";return;
            }
        }
    }
    cout<<"YES\n";
}

int main(){
    int t=1;
    cin>>t;
    while(t--) solve();
}