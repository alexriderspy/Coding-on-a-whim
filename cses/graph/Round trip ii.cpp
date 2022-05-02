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

bool isCycle(int u,vector<int> &recStack,vector<bool>&isPresent){
    vis[u]=1;
    isPresent[u]=true;
    recStack.push_back(u);
    for(int v:edges[u]){
        if(!vis[v] && isCycle(v,recStack,isPresent)){
            return true;
        }else if(isPresent[v] == true){
            int x = (int)recStack.size();
            for(int i=0;i<x;++i){
                if(recStack[i]==v){
                    cout<<x-i+1<<'\n';
                    for(int j=i;j<x;++j){
                        cout<<recStack[j]+1<<' ';
                    }
                    cout<<v+1<<'\n';
                }
            }
            return true;
        }
    }
    isPresent[u]=false;
    recStack.pop_back();
    return false;
}

signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        --u,--v;
        edges[u].push_back(v);
    }    
    vector<int>recStack;
    vector<bool>isPresent(n,false);
    for(int i=0;i<n;++i){
        if(!vis[i] && isCycle(i,recStack,isPresent)){
            return 0;
        }
    }
    cout<<"IMPOSSIBLE\n";
}