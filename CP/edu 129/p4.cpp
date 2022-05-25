#include<bits/stdc++.h>
using namespace std;

#define int long long

unordered_map<int,int>mp;
unordered_map<int,int>vis;
int n;
int find_op(int x){
    vector<int>digs;
    int m=x;
    while(m){
        digs.push_back(m%10);
        m/=10;
    }
    if(digs.size()==n) {
        mp[x]=0;
        vis[x]=1;
        return 0;
    }
    int ans=(int)1e21;
    if(digs.size()>n) {
        return ans;
    }
    sort(digs.begin(),digs.end());
    reverse(digs.begin(),digs.end());

    for(int i=0;i<(int)digs.size();++i){
        if(digs[i]==1 || digs[i]==0) continue;
        find_op(x*digs[i]);
        if(vis[x*digs[i]]==0) continue;
        ans=mp[x*digs[i]]+1;
        break;
    }
    mp[x]=ans;
    vis[x]=1;
    return ans;
}
void solve(){
    int x;cin>>n>>x;
    find_op(x);
    cout<<(mp[x]==(int)1e21?-1:mp[x])<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
}