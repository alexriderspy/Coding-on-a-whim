#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int>a(n);
    int sum=0,avg;
    for(int i=0;i<n;++i) cin>>a[i],sum+=a[i];
    bool p=false;
    for(int i=0;i<n;++i){
        sum-=a[i];
        if(sum%(n-1)==0){
            avg=sum/(n-1);
            if(avg==a[i]) {
                p=true;
                break;
            }
        }
        sum+=a[i];
    }
    cout<<(p?"YES\n":"NO\n");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}