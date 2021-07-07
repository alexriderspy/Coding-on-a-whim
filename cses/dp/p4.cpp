#include<bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(auto &y:coins) cin>>y;
    vector<long long>ordered_ways(x+1,0);
    ordered_ways[0]=1;
    for(auto coin:coins){
        for(int j=1;j<=x;j++){
            if(j>=coin){
                ordered_ways[j]=ordered_ways[j-coin]%MOD+ordered_ways[j]%MOD;
                ordered_ways[j]=ordered_ways[j]%MOD;
            }

        }
    }
    cout<<ordered_ways[x]%MOD<<'\n';
}