//Dijkstra twice then O(n) traversak to find which coupon to halve

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

const int oo = LLONG_MAX;

signed main(){
    int n,m;cin>>n>>m;
    vector<pii>adj[n],rev[n];
    for(int i=0;i<m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        --u,--v;
        adj[u].push_back({v,w});
        rev[v].push_back({u,w});
    }    

    priority_queue<pii>pq;
    pq.push({0,0});
    vector<int>dist(n,oo),distR(n,oo);
    dist[0]=0,distR[n-1]=0;
    while(!pq.empty()){
        pii curr = pq.top();
        pq.pop();
        if(dist[curr.second]!=-curr.first) continue;
        for(pii v:adj[curr.second]){
            if(dist[v.first] > dist[curr.second] + v.second){
                dist[v.first] = dist[curr.second] + v.second;
                pq.push({-dist[v.first],v.first});
            }
        }
    }
    pq.push({0,n-1});
    while(!pq.empty()){
        pii curr = pq.top();
        pq.pop();
        if(distR[curr.second]!=-curr.first) continue;
        for(pii v:rev[curr.second]){
            if(distR[v.first] > distR[curr.second] + v.second){
                distR[v.first] = distR[curr.second] + v.second;
                pq.push({-distR[v.first],v.first});
            }
        }
    }
    int total_min = LLONG_MAX;
    for(int i=0;i<n;++i){
        for(auto v:adj[i]){
            if(dist[i] >= oo || distR[v.first] >= oo) continue; //important line - overflow reasons for unreachable vertices don't try
            total_min = min(total_min,dist[i] + v.second/2 + distR[v.first]);
        }
    }
    cout<<total_min<<'\n';
}