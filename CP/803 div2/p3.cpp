#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,a,b) for(int i=a;i<b;++i)

void solve(){
    int n,f=0;cin>>n;
    vector<int>a(n);
    rep(i,0,n) cin>>a[i];
    int c=0,d=0;
    vector<int>p;
    rep(i,0,n){
        if(a[i]>0) c++,p.push_back(a[i]);
        if(a[i]<0) d++,p.push_back(a[i]);        
    }
    if(c>=3 || d>=3){
        cout<<"NO\n";return;
    }
    int l=n-p.size(),cc=0;
    while(l){
        ++cc;
        p.push_back(0);
        if(cc>=2) break;
        --l;
    }
    for(int i=0;i<p.size();++i){
        for(int j=i+1;j<p.size();++j){
            for(int k=j+1;k<p.size();++k){
                int sum = p[i]+p[j]+p[k];
                int f=0;
                for(int l=0;l<p.size();++l){
                    if(sum==p[l]){
                        f=1;break;
                    }
                }
                if(f==0){
                    cout<<"NO\n";return;
                }
            }
        }
    }
    cout<<"YES\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--) solve();
}