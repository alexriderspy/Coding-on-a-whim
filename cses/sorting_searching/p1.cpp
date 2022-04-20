#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define vi vector<int>
#define FOR(i,start,end) for(int i=start;i<=end;i++)
#define FORR(i,end,start) for(int i=end;i>=start;i--)
 
const int mod=1e9+7;
 
int fact(int n){
    if(n<0) return 0;
    if(n==0) return 1;
    int p=n;
    while(--n){
        p*=n;
    }
    return p;
}
signed main(){
    int n,c;cin>>n;c=n;
    vi a(n);
    FOR(i,0,n-1) cin>>a[i];
    map<int,int>mp;
    FOR(i,0,n-1){
        if(mp[a[i]]>=1){
            c--;
        }else mp[a[i]]++;
    }
    cout<<c<<'\n';
}