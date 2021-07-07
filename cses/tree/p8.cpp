#include<bits/stdc++.h>
using namespace std;
#define max_n 200001
#define LOG 20
vector<int>edges[max_n];
int up[max_n][LOG];
vector<int>depth(max_n);
void dfs(int a,int parent){
    
    for(int b:edges[a]){
        if(b==parent) continue;
        up[b][0]=a;
        depth[b]=depth[a]+1;
        for(int j=1;j<LOG;j++){
            up[b][j]=up[up[b][j-1]][j-1];
        }
        dfs(b,a);
    }
}
int get_lca(int a,int b){
    
    if(depth[a]<depth[b]){
        swap(a,b);
    }//this part is O(n) so we can do better!
    //binary lifting
    int k=depth[a]-depth[b];
    int ans=0;
    //trying to find kth ancestor of a
    for(int i=0;i<LOG;i++){
        if(k&(1<<i)){
            ans+=depth[a]-depth[up[a][i]];
            a=up[a][i];
            
        }
    }
    if(a==b) return ans;
    //this also O(n) can do better!
    //by binary lifting, we can find the ancestor where they dont match
    //then we can move up there.
    for(int j=LOG-1;j>=0;j--){
        if(up[a][j]!=up[b][j]){
            ans+=(depth[a]-depth[up[a][j]])+(depth[b]-depth[up[b][j]]);
            a=up[a][j],b=up[b][j];
            
        }
    }
    //getting as close to the lca as possible
    
    return ans+2;
    //after they have reached the same depth
    //we go up by one together..O(n)
    
}
void solve(){
    int n,q;cin>>n>>q;

    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);

    }
    dfs(1,-1);
    
    while(q--){
        int a,b;cin>>a>>b;
        cout<<get_lca(a,b)<<'\n';
    }
}

int main(){
    solve();
}