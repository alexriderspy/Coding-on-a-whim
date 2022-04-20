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
#define vs vector<string>
 
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
bool cmp(const pair<pii,int> &a, const pair<pii,int> &b){
    
    return a.fi.fi < b.fi.fi;
    
}
bool cmp2(const pii &a, const pii &b){
    return a.se < b.se;
}
 
void solve(){
    int n,c=1;cin>>n;
    vector<pair<pii,int>> a(n);
    multiset<pii>ms;
    FOR(i,0,n-1) {cin>>a[i].fi.fi>>a[i].fi.se;a[i].se=i;}
    sort(all(a),cmp);
    vi ans(n);
    ans[a[0].se]=1;
    ms.insert({a[0].fi.se,a[0].se});    
    FOR(i,1,n-1){
        if(a[i].fi.fi > (*ms.begin()).fi){
            ans[a[i].se]=ans[(*ms.begin()).se];
            ms.insert({a[i].fi.se,a[i].se});
            ms.erase(ms.begin());
        }else{
            c++;
            ans[a[i].se]=c;
            ms.insert({a[i].fi.se,a[i].se});
        }
    }
    cout<<c<<'\n';
    FOR(i,0,n-1) cout<<ans[i]<<' ';cout<<'\n';
}
signed main(){
    fio
    //tt
    solve();        
}