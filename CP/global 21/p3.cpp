#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,a,b) for (auto i=(a);i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

void solve(){
    int n,k,m;cin>>n>>m;
    vector<int>a(n);
    rep(i,0,n) cin>>a[i];
    cin>>k;
    vector<int>b(k);
    rep(i,0,k) cin>>b[i];
    vector<pair<int,int>>cnt1,cnt2;
    rep(i,0,n){
        int c=1;
        while(a[i]%m==0){
            a[i]/=m;
            c*=m;
        }
        if(cnt1.size() && cnt1.back().first==a[i]){
            c+=cnt1.back().second;
            cnt1.pop_back();
        }
        cnt1.push_back({a[i],c});
    }
    rep(i,0,k){
        int c=1;
        while(b[i]%m==0){
            b[i]/=m;
            c*=m;
        }
        if(cnt2.size() && cnt2.back().first==b[i]){
            c+=cnt2.back().second;
            cnt2.pop_back();
        }
        cnt2.push_back({b[i],c});
    }
    if(sz(cnt1)!=sz(cnt2)){
        cout<<"NO\n";
    }else{
        for(int i=0;i<sz(cnt1);++i){
            //cout<<cnt1[i].first<<' '<<cnt1[i].second<<' '<<cnt2[i].first<<' '<<cnt2[i].second<<'\n';
            if(cnt1[i]!=cnt2[i]){
                cout<<"NO\n"; return;
            }
        }
        cout<<"YES\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}