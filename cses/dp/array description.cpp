#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define endl '\n'
#define sz(x) (int)(x.size())
#define all(x) x.begin(),x.end()
#define rall(x) (x).rbegin(),(x).rend()
#define setbits(x) __builtin_popcountll(x)
#define leastsigbit(x) __builtin_ffs(x)
 
#define hmap unordered_map
#define hset unordered_set
#define vvi vector<vector<int>>
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
 
#define pb push_back
#define fi first
#define se second
#define fio ios_base::sync_with_stdio(false);cin.tie(0); 
#define tt int tt;cin>>tt;while(tt--) 
#define FOR(i,start,end) for(int i=start;i<=end;i++)
#define FORR(i,end,start) for(int i=end;i>=start;i--)
#define yess cout<<"YES\n";
#define noo cout<<"NO\n";
 
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
    while (y > 0){
        if (y & 1)
            res = (res*x) % mod;
        y = y>>1; 
        x = (x*x) % mod;
    }
    return res;
}
 
void solve(){
    int n,m;cin>>n>>m;
    vi a(n);
    FOR(i,0,n-1) cin>>a[i];
    vvi dp(n+1, vi (m+2));
    //sum dp[n][j] j=0 to m
    if(a[0]==0){
        FOR(i,1,m) dp[0][i]=1; 
    }else{
        dp[0][a[0]]=1;
    }
    FOR(i,1,n-1){
        
        if(a[i]==0){    
            FOR(j,1,m){
                dp[i][j]=add(dp[i][j], add ( add(dp[i-1][j-1] , dp[i-1][j]), dp[i-1][j+1]));
            }
        }else{
            
            dp[i][a[i]]=add(dp[i][a[i]], add ( add(dp[i-1][a[i]-1] , dp[i-1][a[i]]),dp[i-1][a[i]+1]));
        }
    }
    int s=0;
    FOR(j,1,m){
        s=add(s,dp[n-1][j]);
    }
    cout<<s%mod<<'\n';
}
 
signed main(){
    //fio
    //tt
    solve();
    
}