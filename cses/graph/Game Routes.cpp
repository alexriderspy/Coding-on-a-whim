#include<iostream>
#include <queue>
#include <vector>
#include<algorithm>
#include <climits>
#include <map>
#include <numeric>

#define pii pair<int,int>

using namespace std;

#define int long long

const int N = 1e5;
const int mod = 1e9+7;
vector<int>edges[N];

signed main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        --u,--v;
        edges[u].push_back(v);
    }
    queue<int>q;
    q.push(0);
    vector<int>ways(n);
    ways[0]=1;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int v:edges[curr]){
            ways[v]=(ways[v] + ways[curr])%mod;
            q.push(v);
        }
    }
    cout<<ways[n-1]<<'\n';
}