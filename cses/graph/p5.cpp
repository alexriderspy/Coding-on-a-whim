#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    vector<vector<int>>edges(n);
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        --u,--v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    
    vector<int>depth(n,-1);
    queue<int>q;
    for(int i=0;i<n;++i){
        if(depth[i]!=-1) continue;
        depth[i]=0;
        q.push(i);
        while(!q.empty()){
            m=q.front();
            q.pop();
            for(int v:edges[m]){
                if(depth[v]==-1){
                    depth[v]=1-depth[m];
                    q.push(v);
                }else if(depth[v]==depth[m]){
                    cout<<"IMPOSSIBLE\n";return 0;
                }
            }
        }
    }
    
    for(int i=0;i<n;++i){
        cout<<depth[i]+1<<' ';
    }
    cout<<'\n';
}