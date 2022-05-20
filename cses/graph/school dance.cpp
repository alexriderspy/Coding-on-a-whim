//dinic's algorithm - O(V^2 x E)
#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>>edges;
vector<vector<int>>residualG;
vector<int>level,c;
int source;
int sink;
int n;

bool bfs(){
    level.assign(n,-1);
    queue<int>q;
    q.push(source);
    level[source]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v=0;v<n;++v){
            if(residualG[u][v]>0 && level[v]<0){
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }
    if(level[sink]<0) return false;
    else return true;
}

int send_flow(int u,int flow){
    if(u==sink) return flow;
    if(c[u]==n){
        return 0;
    }
    for(int v=0;v<n;++v){
        if(residualG[u][v]>0){
            c[u]++;
            if(level[v]==level[u]+1){
                int curr_flow = min(flow,residualG[u][v]);
                int bottleneck = send_flow(v,curr_flow);
                if(bottleneck>0){
                    residualG[u][v] -= bottleneck;
                    residualG[v][u] += bottleneck;
                    return bottleneck;
                }
            }
        }
    }
    return 0;
}

vector<int>vis;
map<int,int>mp;

void dfs(int u){
    vis[u]=1;
    for(int v=0;v<n;++v){
        if(!vis[v]){
            if(residualG[u][v]>0){
                mp[v]++;
                dfs(v);
            }
            
        }
    }
}

signed main(){
    //there might be repeated edges, add their speeds
    int m;cin>>n>>m;
    edges=vector<vector<int>>(n,vector<int>(n,0));
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        --u,--v;
        edges[u][v]=1;
        edges[v][u]=1;
    }
    
    source=0;
    sink=n-1;
    residualG=edges;
    
    int max_flow=0;
    while(bfs()){
        c.assign(n,0);
        while(int flow = send_flow(0,(long long)1e60)){
            max_flow+=flow;
        }
    }

    vis.assign(n,0);
    mp[0]++;
    dfs(0);

    vector<pair<int,int>>ans;
    for(auto x:mp){
        for(int v=0;v<n;++v){
            if(edges[x.first][v]>0 && mp[v]==0){
                ans.push_back({x.first,v});
            }
        }
    }
    cout<<max_flow<<'\n';
    for(int i=0;i<ans.size();++i){
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<'\n';
    }
}