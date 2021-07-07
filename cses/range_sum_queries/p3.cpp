#include<bits/stdc++.h>

using namespace std;
//segtree implementation is via a big array
//recursive version can handle everything

long long int sum(vector<long long int> &segtree,int node, int node_left, int node_right,int query_low, int query_high){
    //if interval is contained inside query_low, query_high
    if(query_low<=node_left && node_right<=query_high){
        return segtree[node]; //tree is one big array
    }
    //if intervals are disjoint
    if(query_low>node_right || query_high<node_left){
        return 0;
    }
    int last_in_left=(node_left+node_right)/2;
    return sum(segtree,2*node,node_left,last_in_left,query_low,query_high)+
    sum(segtree,2*node+1,last_in_left+1,node_right,query_low,query_high);
}

void update(vector<long long int> &segtree,int n,int pos,int v){
    
    int j=pos+n;
    segtree[j]=v;
    for(j=j/2;j>=1;j/=2)
    segtree[j]=segtree[2*j]+segtree[2*j+1];

}

//recursive update 

void update2(vector<long long int> &segtree,int node, int node_left, int node_right,int query_low, int query_high,int v){
    //if interval is contained inside query_low, query_high
    if(query_low<=node_left && node_right<=query_high){
        segtree[node]=v;
        return; //tree is one big array
    }
    //if intervals are disjoint
    if(query_low>node_right || query_high<node_left){
        return;
    }
    int last_in_left=(node_left+node_right)/2;
    update2(segtree,2*node,node_left,last_in_left,query_low,query_high,v);
    update2(segtree,2*node+1,last_in_left+1,node_right,query_low,query_high,v);
    segtree[node]=segtree[2*node]+segtree[2*node+1];
}


int main(){

    int n,q;
    cin>>n>>q;
    vector<long long int>arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];
    
    while(__builtin_popcount(n) !=1){
        n++;
        arr.push_back(0);
    }
    vector<long long int>segtree(2*n,0);
    for(int i=n;i<2*n;i++){
        segtree[i]=arr[i-n];
    }
    for(int i=n-1;i>=1;i--){
        segtree[i]=segtree[2*i]+segtree[2*i+1];
    }
    segtree[0]=-1;
    while(q--){
        int ch;
        cin>>ch;
        if(ch==2){
            int a,b;
            cin>>a>>b;
            a--,b--;
            cout<<sum(segtree,1,0,n-1,a,b)<<'\n';
        }else{
            int pos;
            int val;
            cin>>pos>>val;
            pos--;
            update2(segtree,1,0,n-1,pos,pos,val);
        }
    }
}