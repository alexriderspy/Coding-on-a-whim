#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n,m;cin>>n>>m;
    int max_wt[2][2];
    int dir[2]={-1,1};
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            max_wt[i][j]=-1e9;
        }
    }
    string s;
    for(int i=0;i<n;++i){
        cin>>s;
        for(int j=0;j<m;++j){
            if(s[j]=='B'){
                for(int x=0;x<2;++x){
                    for(int y=0;y<2;++y){
                        max_wt[x][y]=max(max_wt[x][y],-(i+1)*dir[x]-(j+1)*dir[y]);
                    }
                }
            }

        }
    }
    int best=1e9;
    int bi,bj;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            int cost=0;
            for(int x=0;x<2;++x){
                for(int y=0;y<2;++y){
                    cost=max(cost,max_wt[x][y]+(i+1)*dir[x]+(j+1)*dir[y]);
                }
            }
            if(cost<best){
                best=cost;
                bi=i,bj=j;
            }
        }
    }
    cout<<bi+1<<' '<<bj+1<<'\n';

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}