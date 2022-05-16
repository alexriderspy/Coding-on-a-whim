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
    
    vector<int>vis(n);
    vector<int>par(n,-1);
    vector<int>depth(n,n+5);
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        m=q.front();
        q.pop();
        vis[m]=1;
        if(m==n-1){
            m=n-1;
            vector<int>ans;
            while(m!=0){
                ans.push_back(m);
                m=par[m];
            }
            cout<<ans.size()+1<<'\n';
            reverse(ans.begin(),ans.end());
            cout<<1<<' ';
            for(int x:ans) cout<<x+1<<' ';
            cout<<'\n';
            return 0;
        }
        for(int v:edges[m]){
            if(!vis[v]){
                vis[v]=1;
                if(depth[v]==n+5) par[v]=m,depth[v]=depth[m]+1;
                q.push(v);
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
}