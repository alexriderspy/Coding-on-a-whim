#include<bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;

int main(){
    int n;
    cin>>n;
    vector<string>v;
    string s;
    s="";
    for(int i=0;i<=n;i++) {
        s+="*";
    }
    v.push_back(s);
    
    for(int i=0;i<n;i++) {
        cin>>s;
        string t="*";t+=s;
        v.push_back(t);
    }
    
    vector<vector<int>>paths(n+1,vector<int>(n+1,-1));
    if(v[1][1]=='*') cout<<0<<'\n';
    else{
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++) {
                if(v[i][j]=='*'){
                    paths[i][j]=0;
                }
            }
        }
        paths[1][1]=1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                    if(i==1 && j==1) continue;
                    if(paths[i][j]==0) continue;
                    paths[i][j]=paths[i-1][j]%MOD+paths[i][j-1]%MOD;
                    paths[i][j]=paths[i][j]%MOD;
            }
        }
        cout<<paths[n][n]%MOD<<'\n';
    }
}