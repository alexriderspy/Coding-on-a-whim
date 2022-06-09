#include<bits/stdc++.h>
using namespace std;

#define int long long

const int inf=(int)1e30;

map<int,int>mp;
map<int,int>vis;

int n;

int find_op(int x){
    if(vis[x]) return mp[x];
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
    int ans=inf;
    if(digs.size()>n) {
        mp[x]=-1;
        vis[x]=1;
        return -1;
    }
    sort(digs.begin(),digs.end());
    reverse(digs.begin(),digs.end());

    for(int i=0;i<(int)digs.size();++i){
        if(digs[i]==1 || digs[i]==0) continue;
        find_op(x*digs[i]);
        if(mp[x*digs[i]]==-1) continue;
        ans=min(ans,mp[x*digs[i]]+1);
    }
    mp[x]=(ans==inf?-1:ans);
    vis[x]=1;
    return mp[x];
}
void solve(){
    int x;cin>>n>>x;
    find_op(x);
    
    cout<<((vis[x]==0)?-1:mp[x])<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}