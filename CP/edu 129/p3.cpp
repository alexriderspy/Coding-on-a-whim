#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];
    vector<pair<int,int>>ans;
    for(int i=0;i<n;++i){
        int m=a[i],pos=i;
        for(int j=i+1;j<n;++j){
            if(a[j]<m){
                m=a[j];
                pos=j;
            }
        }
        if(pos==i) continue;
        if(b[i]<b[pos]){
            cout<<"-1\n";return;
        }else{
            ans.push_back({i,pos});
        }
        swap(a[i],a[pos]);
        swap(b[i],b[pos]);
    }

    for(int i=0;i<n;++i){
        int m=b[i],pos=i;
        for(int j=i+1;j<n;++j){
            if(b[j]<m){
                m=b[j];
                pos=j;
            }
        }
        if(pos==i) continue;
        if(a[i]<a[pos]){
            cout<<"-1\n";return;
        }else{
            ans.push_back({i,pos});
        }
        swap(a[i],a[pos]);
        swap(b[i],b[pos]);
    }
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();++i){
        cout<<ans[i].first+1<<' '<<ans[i].second+1<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}