#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vs vector<string> 
#define rep(i,a,b) for (int i=a;i<b;++i)

void solve(){
    int n;cin>>n;
    vs a(n);
    vector<pair<string,int>> b(n);
    vector<char>ans(n);
    rep(i,0,n){
        cin>>a[i];
        b[i].first=a[i];
        b[i].second=i;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    rep(i,0,n){
        int f=0;
        rep(j,0,a[i].size()-1){
            string s1=a[i].substr(0,j+1);
            string s2=a[i].substr(j+1,(int)a[i].size()-(j+1));

            //cout<<s1<<' '<<s2<<'\n';
            int index1=lower_bound(a.begin(),a.end(),s1)-a.begin();
            int index2=lower_bound(a.begin(),a.end(),s2)-a.begin();
            if(index1<n && a[index1]==s1 && index2<n && a[index2] == s2){
                ans[b[i].second]='1';f=1;break;
            }
        }
        if(f==0){ans[b[i].second]='0';}
    }
    rep(i,0,n) cout<<ans[i];
    cout<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--) solve();
}