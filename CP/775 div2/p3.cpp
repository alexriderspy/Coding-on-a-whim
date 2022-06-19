#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<int>col[(int)1e5+5],row[(int)1e5+5];

void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>a[i][j];
        }
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            col[a[i][j]].push_back(j);
            row[a[i][j]].push_back(i);
        }
    }
    for(int i=0;i<1e5+2;++i){
        if(col[i].size()>=2) sort(col[i].begin(),col[i].end());
        if(row[i].size()>=2) sort(row[i].begin(),row[i].end());
    }
    int sum=0,pref=0;
    for(int i=1;i<=1e5;++i){
        if(col[i].size()>=2){
            pref = col[i][0];
            for(int j=1;j<col[i].size();++j){
                sum += (j)*col[i][j] - pref;
                pref+= col[i][j];
            }
        }
        if(row[i].size()>=2){
            pref = row[i][0];
            for(int j=1;j<row[i].size();++j){
                sum += (j)*row[i][j] - pref;
                pref+= row[i][j];
            }
        }

    }
    cout<<sum<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}