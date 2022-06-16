#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n,x,s=0;cin>>n>>x;
    vector<int>nums(n);
    for(int i=0;i<n;++i) cin>>nums[i],s+=nums[i];
    x=s-x;
    vector<int>pref(n),suff(n);
    pref[0]=nums[0];
    for(int i=1;i<n;++i) pref[i]=pref[i-1]+nums[i];
    suff[n-1]=nums[n-1];
    for(int i=n-2;i>=0;--i) suff[i]=suff[i+1]+nums[i];
    unordered_map<int,pair<int,int>>mp;
    for(int i=0;i<n;++i){
        if(mp[pref[i]].first) continue;
        mp[pref[i]].first++;
        mp[pref[i]].second=i;
    }
    mp[0].first++;
    mp[0].second=-1;
    int m=1e9;
    pair<int,int>p;
    for(int i=n-1;i>=0;--i){
        p=mp[x-suff[i]];
        if(p.first>=1){
            if(i>p.second){
                m=min(m,p.second+1+n-1-i+1);  
            }
        }
    }
    p=mp[x];
    if(p.first>=1){
        
        m=min(m,p.second+1);  
        
    }
    
    if(m==1e9){
        cout<<-1<<'\n';
    }else{
        cout<<m<<'\n';
    }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}