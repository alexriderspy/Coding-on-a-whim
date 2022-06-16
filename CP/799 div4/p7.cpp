#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    vector<int>ano;
    for(int i=1;i<n;++i){
        if(a[i-1]>=2*a[i]){
            ano.push_back(i-1);
        }
    }
    int v,ans=0;
    if(ano.size()==0){
        ans+=(n-k);
        cout<<ans<<'\n';return;
    }else if(ano.size()==1){
        v=ano[0]+1-(k);
        ans+=v>=0?v:0;
        v=(n-ano.back()-1)-(k);
        ans+=v>=0?v:0;
        cout<<ans<<'\n';return;
    }
    for(int i=0;i<ano.size();++i){
        if(i==0){
            v=ano[0]+1-k;
            ans+=v>=0?v:0;
        }else if(i==((int)ano.size()-1)){
            v=(n-ano.back()-1)-k;
            ans+=v>=0?v:0;
            continue;
        }
        v=(ano[i+1]-ano[i])-k;
        ans+=v>=0?v:0;
        
    }
    cout<<ans<<'\n';
}   

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}