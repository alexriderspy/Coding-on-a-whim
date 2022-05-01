//k dijkstra

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

struct node{
    int u,v,w;
};

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
    
    for(int i=0;i<k;++i){
        vector<int>dist(n,oo);
        dist[0]=0;
        vector<int>par(n,0);
        pq.push({0,0});
        while(!pq.empty()){
            pii curr = pq.top();
            pq.pop();
            if(dist[curr.second]!=-curr.first) continue;
            for(auto v:edges[curr.second]){
                if(dist[curr.second]+v.second < dist[v.first]){
                    dist[v.first] = dist[curr.second] + v.second;
                    pq.push({-dist[v.first],v.first});
                    par[v.first] = curr.second;
                }
            }
        }
        cout<<dist[n-1]<<' ';
    }
    cout<<'\n';
}