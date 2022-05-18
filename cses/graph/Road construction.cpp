#include<bits/stdc++.h>

using namespace std;

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

    parent=vector<int>(n),size=vector<int>(n);

    for(int i=0;i<n;++i){
        make_set(i);
    }

    int num=n,sz=1;
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        --u,--v;
        if(find_set(u)!=find_set(v)){
            union_sets(u,v);
            sz=max({sz,size[find_set(u)],size[find_set(v)]});
            num--;
            cout<<num<<' '<<sz<<'\n';
        }else{
            cout<<num<<' '<<sz<<'\n';
        }
    }
}