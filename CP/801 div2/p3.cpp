#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>a[i][j];
        }
    }
    if((n+m-1)%2){
        cout<<"NO\n";return;
    }
    vector<vector<int>>dpMAX(n,vector<int>(m,-1e9-100));
    vector<vector<int>>dpMIN(n,vector<int>(m,+1e9+100));
    dpMAX[0][0]=0,dpMIN[0][0]=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(i>=1){
                dpMAX[i][j] = max(dpMAX[i-1][j],dpMAX[i][j]);
                dpMIN[i][j] = min(dpMIN[i-1][j],dpMIN[i][j]);

            }
            if(j>=1){
                dpMAX[i][j] = max(dpMAX[i][j-1],dpMAX[i][j]);
                dpMIN[i][j] = min(dpMIN[i][j-1],dpMIN[i][j]);
            }
            dpMAX[i][j] += (a[i][j]);
            dpMIN[i][j] += (a[i][j]);
        }
    }
    if(dpMAX[n-1][m-1]>=0 && dpMIN[n-1][m-1]<=0){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}