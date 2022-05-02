#include<iostream>
#include <queue>
#include <vector>
#include<algorithm>
#include <climits>
#include <map>
#include <numeric>

using namespace std;

#define pii pair<int,int>

signed main(){
    int n,m;cin>>n>>m;
    vector<pii>edges[n];
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        --u,--v;
        edges[u].push_back({v,-1});
    }
    
}