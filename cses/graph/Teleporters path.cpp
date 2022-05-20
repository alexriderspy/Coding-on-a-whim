//assign id to an edge and pop from back so that edges get removed when we 
//are done traversing it
#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>>edges;
vector<int>order;
vector<int>in;
vector<int>out;
vector<int>vis;

void dfs(int u){
    while(!edges[u].empty()){
        auto v = edges[u].back();
        edges[u].pop_back();
        if(!vis[v.second]){
            vis[v.second]=1;
            dfs(v.first);
        }

    }
    order.push_back(u);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    edges=vector<vector<pair<int,int>>>(n);
    in.assign(n,0);
    out.assign(n,0);
    vis.assign(m,0);

    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        --u,--v;
        edges[u].push_back({v,i});
        in[v]++;
        out[u]++;
    }
    for(int i=1;i<n-1;++i){
        if(in[i]!=out[i]){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }
    if(out[0]-in[0]!=1 || in[n-1]-out[n-1]!=1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    dfs(0);
    reverse(order.begin(),order.end());
    if(order.size()!=m+1 || order.back()!=n-1 || order.front()!=0){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    for(int i=0;i<order.size();++i){
        cout<<order[i]+1<<' ';
    }
    cout<<'\n';
}