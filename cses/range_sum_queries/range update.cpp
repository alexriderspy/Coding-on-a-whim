#include<bits/stdc++.h>

using namespace std;

vector<long long> segtree;

void update(int node, int node_left, int node_right,int query_low, int query_high,int u){
    
    if(query_low<=node_left && node_right<=query_high){
        segtree[node]+=u;
        return;
    }
    
    if(query_low>node_right || query_high<node_left){
        return;
    }
    int last_in_left=(node_left+node_right)/2;
    update(2*node,node_left,last_in_left,query_low,query_high,u);
    update(2*node+1,last_in_left+1,node_right,query_low,query_high,u);
}

int main(){
    
    int n,q;
    cin>>n>>q;
    vector<int>arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];
    
    while(__builtin_popcount(n) !=1){
        n++;
        arr.push_back(0);
    }
    segtree.resize(2*n);
    for(int i=n;i<2*n;i++){
        segtree[i]=arr[i-n];
    }
    
    while(q--){
        int ch;
        cin>>ch;
        if(ch==1){
            int a,b,u;
            cin>>a>>b>>u;
            a--,b--;
            update(1,0,n-1,a,b,u);
        }else{
            int k;
            cin>>k;
            k--;
            long long int val=0;
            for(int j=k+n;j>=1;j/=2){
                val+=segtree[j];
            }
            cout<<val<<'\n';
        }
    }
}