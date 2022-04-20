#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define endl '\n'
#define sz(x) (int)(x.size())
#define all(x) x.begin(),x.end()
#define rall(x) (x).rbegin(),(x).rend()
#define setbits(x) __builtin_popcountll(x)
#define ld long double
 
#define hmap unordered_map
#define hset unordered_set
#define vvi vector<vector<int>>
#define vi vector<int>
#define vs vector<string>
#define pii pair<int,int>
#define vpii vector<pii>
 
#define pb push_back
#define fi first
#define se second
#define fio ios_base::sync_with_stdio(false);cin.tie(0); 
#define tt int tt;cin>>tt;while(tt--) 
#define FOR(i,start,end) for(int i=start;i<=end;i++)
#define FORR(i,end,start) for(int i=end;i>=start;i--)
#define yess cout<<"yes\n";
#define noo cout<<"no\n";
 
const int inf=1e18;
const int ninf=-1e18;
const int mod=1e9+7;
 
int add(int a,int b){
    return (a%mod+b%mod)%mod;
}
int mul(int a,int b){
    return ((a%mod)*(b%mod))%mod;
}
int sub(int a,int b){
    return (a%mod-b%mod)>0?(a%mod-b%mod)%mod : mod-(b%mod-a%mod)%mod;
}
int fact(int x){
    if(x<0) return 0;
    if(x==0) return 1;
    int p=x%mod;
    while(--x){
        p=((p%mod)*(x%mod));
    }
    return p%mod;
}
int query(int l,int r){
    int ans;
    cout<<"? "<<l<<" "<<r<<endl;
    cin>>ans;return ans;
}
void print(int a){
    cout<<"! "<<a<<endl;
}
 
void debug(){
    cout<<"kill\n";
}
void debug(int x){cout<<x<<'\n';}
int bin_exp(int x, unsigned int y)
{
    int res = 1;     
 
    x = x % mod;
    if (x == 0) return 0; 
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % mod;
 
        y = y>>1; 
        x = (x*x) % mod;
    }
    return res;
}
void solve(){
    int n,m,k;cin>>n>>m>>k;
    vi a(n);
    FOR(i,0,n-1) cin>>a[i];
    vi d(m);
    FOR(i,0,m-1) cin>>d[i];
    sort(all(a));sort(all(d));
    int i=0,j=0,cnt1=0,ans=0,cnt2=0;
    while(i<n  && j<m){
        if(a[i]>=(d[j]-k) && a[i]<=(d[j]+k)){
            cnt1++; i++,j++;
        }else if(a[i]<d[j]-k){
            i++;
        }else {
            j++;
        }
    }
    i=n-1,j=m-1;
    while(i>=0  && j>=0){
        if(a[i]>=(d[j]-k) && a[i]<=(d[j]+k)){
            cnt2++; i--,j--;
        }else if(a[i]>d[j]+k){
            i--;
        }else {
            j--;
        }
    }
    cout<<max(cnt1,cnt2)<<'\n';
    
}   
 
signed main(){
   // fio
   // tt 
    solve();
    
}