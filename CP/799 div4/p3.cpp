#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    char x;
    string s;
    pair<int,int>p,ans;
    map<pair<int,int>,int>mp;
    for(int i=0;i<8;++i){
        cin>>s;
        for(int j=0;j<8;++j){
            x=s[j];
            if(x=='#')
                mp[{i,j}]++;
        }        
    }
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j){
            if(mp[{i-1,j-1}] && mp[{i+1,j-1}] && mp[{i+1,j+1}] && mp[{i-1,j+1}]){
                ans={i,j};break;
            }
        }
        
    }
    cout<<ans.first+1<<' '<<ans.second+1<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}