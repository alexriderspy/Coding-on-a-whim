#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

void dfs(int u,int &f,vector<vector<int>>&edges,vector<int>&vis,vector<int>&ans){
    vis[u]=1;
    if(f==1) return;
    for(int v:edges[u]){
        if(!vis[v]) ans.push_back(v),dfs(v,f,edges,vis,ans);
        else{
            if(ans[(int)ans.size()-2] == v) continue;
            if(f==1) return;
            for(int i=0;i<ans.size();++i){
                if(ans[i]==v) {
                    cout<<(int)ans.size()-i+1<<'\n';
                    for(int j=i;j<ans.size();++j) cout<<ans[j]+1<<' ';
                    cout<<v+1<<'\n';
                    f=1;
                    return;
                }                
            }               
        }
    }
    if(f==1) return;
}

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

    vector<int>vis(n,0);
    vector<int>ans;
    int f=0;
    for(int i=0;i<n;++i){
        if(vis[i]) continue;
        ans.clear();
        ans.push_back(i);
        dfs(i,f,edges,vis,ans);
        if(f==1) return 0;
    }   
    cout<<"IMPOSSIBLE\n";
}