//k dijkstra - compare 

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

const int oo = 1LL<<62;

signed main(){
    int n,m;cin>>n>>m;
    vector<pii>edges[n];
    for(int i=0;i<m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        --u,--v;
        edges[u].push_back({v,w});
    }
    
    priority_queue<pii>pq;

    pq.push({0,0});

}