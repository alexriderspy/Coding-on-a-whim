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

signed main(){
    //there might be repeated edges, add their speeds
    int a,b,m;cin>>a>>b>>m;
    n=a+b+2;
    edges=vector<vector<int>>(n,vector<int>(n,0));
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        --u,--v;
        v+=a;
        edges[u][v]=1;
    }
    
    for(int i=0;i<a;++i) edges[a+b][i]=1;
    for(int i=a;i<a+b;++i) edges[i][a+b+1]=1;
    
    source=a+b;
    sink=a+b+1;
    residualG=edges;
    
    int max_flow=0;
    while(bfs()){
        c.assign(n,0);
        while(int flow = send_flow(source,(long long)1e60)){
            max_flow+=flow;
        }
    }

    vector<pair<int,int>>ans;
    for(int i=a;i<a+b;++i){
        for(int j=0;j<a;++j){
            if(residualG[i][j]==1){
                ans.push_back({j,i-a});
            }
        }
    }
    cout<<max_flow<<'\n';
    for(int i=0;i<ans.size();++i){
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<'\n';
    }
}