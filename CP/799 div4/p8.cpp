#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Ans{
    int num,l,r,a;
};
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    map<int,vector<int>>mp;
    for(int i=0;i<n;++i) cin>>a[i],mp[a[i]].push_back(i);
    Ans b;b.num=0;
    for(auto x:mp){
        vector<int>p=x.second;
        int l=0,r=0;
        while(r<p.size()){
            int num1 = r-l+1;
            int tot = p[r]-p[l]+1;
            int num2 = tot-num1;
            if(num1 - num2 > b.num){
                b.num=num1-num2;
                b.l = p[l];
                b.r = p[r];
                b.a = x.first;
            }
            if(num1 <= num2){
                ++l;
            }else{
                ++r;
            }

        }
    }
    cout<<b.a<<' '<<b.l+1<<' '<<b.r+1<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}
