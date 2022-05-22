#include<bits/stdc++.h>

using namespace std;

vector<int>segtree;

const int inf=1e9+2;
int return_min(int node,int node_left,int node_right,int query_low,int query_high){
    if(node_left>=query_low && node_right<=query_high){
        return segtree[node]; 
    }
    if(node_left>query_high || node_right<query_low){
        return inf;
    }
    int last_to_left=(node_left+node_right)/2;
    return min(return_min(2*node,node_left,last_to_left,query_low,query_high),
    return_min(2*node+1,last_to_left+1,node_right,query_low,query_high));
}
int main(){
    int n,q;
    cin>>n>>q;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    while(__builtin_popcount(n)!=1){
        n++;
        arr.push_back(0);
    }
    segtree.resize(2*n);

    for(int i=n;i<2*n;i++) segtree[i]=arr[i-n];
    for(int i=n-1;i>=1;i--) segtree[i]=min(segtree[2*i],segtree[2*i+1]);
    //segtree[0]=-1;
   // for(int i=0;i<2*n;i++) cout<<segtree[i]<<" ";
    cout<<'\n';

    while(q--){
        int a,b;
        cin>>a>>b;
        a--,b--;
        cout<<return_min(1,0,n-1,a,b)<<'\n';

   }
}