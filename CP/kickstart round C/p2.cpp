#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n,x,y;cin>>n>>x>>y;
    int sum=(n*(n+1))/2;
    int a=x*sum/(x+y);
    if((x*sum)%(x+y)){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    for(int i=0;i<(1<<n);++i){
        int s=0;
        vector<int>ans;
        for(int j=0;j<n;++j){
            if(i&(1<<j)){
                s+=j+1;
                ans.push_back(j+1);
            }
        }
        if(s==a){
            cout<<"POSSIBLE\n";
            cout<<ans.size()<<'\n';
            for(int x:ans) cout<<x<<' ';
            cout<<'\n';
            return;
        }
    }
    cout<<"IMPOSSIBLE\n";
    
}

signed main(){
    int t;cin>>t;
    for(int tt=1;tt<=t;++tt){
        cout<<"Case #"<<tt<<":"<<' ';solve();
    }
}