#include<iostream>
#include <queue>
#include <vector>
#include<algorithm>
#include <climits>
#include <map>
#include <numeric>

using namespace std;

#define pii pair<int,int>

const int N  = 1e5;

vector<int>edges[N];

vector<int>ans;
vector<int>vis(N);

signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        --u,--v;
        edges[u].push_back(v);
    }    

    vector<int>indeg(n);
    for(int i=0;i<n;++i){
        for(int j:edges[i]){
            indeg[j]++;
        }
    }
    vector<int>top_sort;
    priority_queue<pii>pq;
    for(int i=0;i<n;++i){
        if(indeg[i]==0)
        pq.push({indeg[i],i});
    }
    int x=0;
    while(!pq.empty()){
        pii curr = pq.top();
        pq.pop();
        x++;
        top_sort.push_back(curr.second);
        for(int i:edges[curr.second]){
            indeg[i]--;
            if(indeg[i]==0)
            pq.push({indeg[i],i});
        }
    }
    if(x<n){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    for(int i=0;i<top_sort.size();++i) cout<<top_sort[i]+1<<' ';
    cout<<'\n';   
}