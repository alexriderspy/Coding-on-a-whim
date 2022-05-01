//dijsktra shortest distance from one source to all vertices

#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;
#define int long long
#define pii pair<int,int>

int n,m;
const int N = 100005;
int oo = LLONG_MAX;

vector<vector<pii>>edges(N);

priority_queue<pii,vector<pii>,greater<pii>>q;
int ans[N];

void bfs(){
    while(!q.empty()){
        pii loc = q.top();
        q.pop();
        if(loc.first!=ans[loc.second]) continue; //for those that are wrong and are present in the list like those whose distance got updated but wasn't deleted
        for(pii v:edges[loc.second]){
            if(ans[loc.second]+v.first<ans[v.second]){
                
                ans[v.second] = ans[loc.second]+v.first;
                q.push({ans[v.second],v.second});
            }
            
        }
    }
}
signed main(){
    cin>>n>>m;

    for(int i=0;i<m;++i){
        int u,v,w;cin>>u>>v>>w;
        --u,--v;
        edges[u].push_back({w,v});
    }

    for(int i=1;i<n;++i) {
        ans[i]=oo;
        
    }
    ans[0]=0;
    q.push({0,0});
    bfs();
    for(int i=0;i<n;++i) cout<<ans[i]<<' ';
    cout<<'\n';
}