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
 
void solve(){
    int n,k;cin>>n>>k;
    vi a(n);
    FOR(i,0,n-1) cin>>a[i];
    vi b=a;
    sort(b.begin(),b.begin()+k);
    multiset<int>s1,s2;
    FOR(i,0,(k-1)/2){
        s1.insert(b[i]);
    }
    FOR(i,((k-1)/2)+1,k-1){
        s2.insert(b[i]);
    }
    int i=0,j=i+k;
    cout<<*s1.rbegin()<<' ';
    while(j<n){
 
        int ls=*s1.rbegin();
        
        if(a[j] > ls ){
            s2.insert(a[j]);
        }
        else{
            s1.insert(a[j]);
        }
        if(a[i]>ls){
            s2.erase(s2.find(a[i]));
        }
        else{
            s1.erase(s1.find(a[i]));
        }
        if(sz(s1) > sz(s2)+1){
            s2.insert(*s1.rbegin());
            s1.erase(s1.find(*s1.rbegin()));
        }
        if(sz(s2) > sz(s1)){
            s1.insert(*s2.begin());
            s2.erase(s2.find(*s2.begin()));
        }
    i++,j++;
    cout<<*s1.rbegin()<<' ';
    }
}   
 
signed main(){
   // fio
   // tt 
    solve();
    
}