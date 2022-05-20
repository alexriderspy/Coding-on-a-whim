#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>edges(n);
    
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        --u,--v;
        edges[u].push_back({v,i});
        edges[v].push_back({u,i});
    }
    for(int i=0;i<n;++i){
        if(edges[i].size()%2){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }
    stack<int>st;
    st.push(0);
    vector<int>order;
    vector<int>vis(m);
    while(!st.empty()){
        int u=st.top();
        int f=0;
        while(!edges[u].empty()){
            pair<int,int> v=edges[u].back();
            edges[u].pop_back();
            if(!vis[v.second]){
                f=1;
                vis[v.second]=1;
                st.push(v.first);
                break;
            }
        }
        if(!f){
            order.push_back(u);
            st.pop();
        }
    }
    if(order.size()!=m+1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    for(int i=0;i<order.size();++i) cout<<order[i]+1<<' ';
    cout<<'\n';
}