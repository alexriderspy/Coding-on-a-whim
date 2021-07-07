#include<bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(auto &y:coins) cin>>y;
    sort(coins.begin(),coins.end());
    vector<long long>ways(x+1,0);
    ways[0]=1;
    for(int j=1;j<=x;j++){
        for(auto coin:coins){
            if(j<coin) break;
            ways[j]=ways[j]%MOD+ways[j-coin]%MOD;
            ways[j]=ways[j]%MOD;
        }
    }
    cout<<ways[x]%MOD<<'\n';
}