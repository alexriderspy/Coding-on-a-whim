//edge disjoint paths

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
    if(u==sink) {
        return flow;
    }
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

map<pair<int,int>,int>mp;
vector<vector<int>>ans;

void dfs(int u,vector<int>path,int &f){
    path.push_back(u);

    if(u==sink){
        f=1;
        ans.push_back(path);
        return;
    }
    for(int v=0;v<n;++v){
        if(edges[u][v]>0 && residualG[v][u]>0){
            if(mp[{u,v}]==0){
                mp[{u,v}]++;
                dfs(v,path,f);
                if(f==1) {
                    if(u!=source){
                        path.clear();
                        return;
                    }
                    else f=0;
                }
            }
        }
    }
    path.pop_back();
}

signed main(){
    
    int m;cin>>n>>m;
    
    edges=vector<vector<int>>(n,vector<int>(n,0));
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        --u,--v;
        edges[u][v]=1;
    }
    
    source=0;
    sink=n-1;
    residualG=edges;
    
    int max_flow=0;
    

    while(bfs()){
        c.assign(n,0);
        while(int flow = send_flow(source,(long long)1e60)){
            max_flow+=flow;
        }
    }
    vector<int>path;
    int f=0;
    dfs(source,path,f);
    cout<<max_flow<<'\n';

    for(int i=0;i<(int)ans.size();++i){
        cout<<ans[i].size()<<'\n';
        for(int j=0;j<ans[i].size();++j){
            cout<<ans[i][j]+1<<' ';
        }
        cout<<'\n';
    }
}