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
const int mod = 1e9+7;
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
    vector<int>dist(n,oo),num(n),maxf(n),minf(n,oo);
    dist[0]=0;
    minf[0]=0;
    num[0]=1;
    pq.push({0,0});
 
    while(!pq.empty()){
        pii curr = pq.top();
        int u = curr.second;
        pq.pop();
        if(dist[u]!=-curr.first) continue;
        for(pii vk:edges[u]){
            int v = vk.first;
            int wt = vk.second;
            if(dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
                maxf[v] = maxf[u] + 1;
                minf[v] = minf[u] + 1;
                num[v] = num[u];
                pq.push({-dist[v],v});
            }else if(dist[u] + wt == dist[v]){
                maxf[v] = max(maxf[v],maxf[u]+1);
                minf[v] = min(minf[v],minf[u]+1);
                num[v] = (num[u] + num[v])%mod;
            }
 
        }
    }
    cout<<dist[n-1] << ' '<<num[n-1]<<' '<<minf[n-1] <<' '<<maxf[n-1]<<'\n';
 
}