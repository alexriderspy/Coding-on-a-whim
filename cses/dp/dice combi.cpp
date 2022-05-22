#include<bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;
int main(){
    int n;
    cin>>n;
    vector<long long>ways(n+1,0);
    ways[0]=1;
    ways[1]=1;
    for(int j=2;j<=n;j++){
        
        for(int k=j-1,cnt=0;k>=0 && cnt<6;k--,cnt++){
            ways[j]=ways[j]%MOD + ways[k]%MOD;
            ways[j]=ways[j]%MOD;
        }
    }
    cout<<ways[n]%MOD<<'\n';
}