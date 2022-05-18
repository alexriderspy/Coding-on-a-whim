#include<bits/stdc++.h>

using namespace std;

struct Edge{
    int u,v,w;
};

bool cmp(const Edge&e1,const Edge&e2){
    return e1.w<e2.w;
}
vector<int>parent,size;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main(){
    int n,m;cin>>n>>m;
    vector<Edge>edges(m);
    parent=vector<int>(n),size=vector<int>(n);
    for(int i=0;i<m;++i) cin>>edges[i].u>>edges[i].v>>edges[i].w;
    for(int i=0;i<n;++i){
        make_set(i);
    }
    sort(edges.begin(),edges.end(),cmp);
    long long int ans=0;
    int cnt=0;
    for(auto e:edges){
        e.u--;e.v--;
        if(find_set(e.u)!=find_set(e.v)){
            ans+=e.w;
            cnt++;
            union_sets(e.u,e.v);
        }
        if(cnt==n-1) break;
    }
    if(cnt==n-1)
    cout<<ans<<'\n';
    else
    cout<<"IMPOSSIBLE\n";
}