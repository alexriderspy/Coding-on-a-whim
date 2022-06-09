#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int x,n,k,y,sum=0;cin>>n>>k;

    vector<int>p[k];
    for(int i=0;i<n;++i){
        cin>>x;
        p[x%k].push_back(x);
    }
    for(int i=0;i<k;++i){
        int j=k-i;

        while(p[i].size()){
            x=p[i].back();
            j%=k;
            if((p[j].size()>=2 && j==i) || (p[j].size()&&j!=i)){
                p[i].pop_back();
                y=p[j].back();
                p[j].pop_back();
                
                sum+=(x+y)/k;
            }else{
                ++j;
            }
        }
    }
    cout<<sum<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}