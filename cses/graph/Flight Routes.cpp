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
    int n,m,k;cin>>n>>m>>k;
    vector<pii>edges[n];
    for(int i=0;i<m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        --u,--v;
        edges[u].push_back({v,w});
    }
    
    priority_queue<pii>pq;

    pq.push({0,0});
    vector<vector<int>>dist(n,vector<int>(k,oo));
    dist[0][0]=0;
    
    //we keep worst shortest path at the end and update it nd then sort it

    while(!pq.empty()){
        pii curr = pq.top();
        pq.pop();
        int v = curr.second;
        int d = -curr.first;
        if(dist[v][k-1] < d) continue;
        for(pii e:edges[v]){
            int vertex = e.first;
            int dis = e.second;
            if(d + dis < dist[vertex][k-1]){
                dist[vertex][k-1] = d+dis;
                pq.push({-d-dis,vertex});
                sort(dist[vertex].begin(),dist[vertex].end());
            }
            
        }
    }
    for(int i=0;i<k;++i) cout<<dist[n-1][i]<<' ';
    cout<<'\n';
}