//bellman ford negative cycle detection

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
    int n,m;cin>>n>>m;
    vector<node>edges(m);
    for(int i=0;i<m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        --u,--v;
        edges[i]={u,v,w};
    }
    //relax each edge n-1 times
    
    vector<int>dist(n,oo);
    vector<int>par(n,0);
    dist[0]=0;
    int x = -1;
    
    for(int i=0;i<n;++i){
        x=-1;
        for(auto e:edges){
            if(dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                x=e.v;
                par[e.v] = e.u;
            }
        }
    }
    if(x==-1){
        cout<<"NO\n";
    }else{
        int y=x;
        //to get back to the earliest vertex closest to the source
        for(int i=0;i<n;++i) y=par[y];
        x=y;
        vector<int>ans;
        while(true){
            ans.push_back(y);
            if(y==x && ans.size()>1) break;
            y=par[y];
        }
        reverse(ans.begin(),ans.end());
        cout<<"YES\n";
        for(auto x:ans) cout<<x+1<<' ';
        cout<<'\n';

    }
}