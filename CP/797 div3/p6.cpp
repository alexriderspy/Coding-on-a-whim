#include<bits/stdc++.h>
using namespace std;

#define int long long

int lcm(int a,int b){
    int lcmf = (a*b)/__gcd(a,b);
    return lcmf;
}

int find_rotations(string s){
    string t=s.back()+s.substr(0,s.size()-1);
    int cnt=1;
    while(t!=s){
        cnt++;
        t=t.back()+t.substr(0,t.size()-1);
    }
    return cnt;
}
void solve(){
    int x,n;cin>>n;
    string s;cin>>s;
    vector<int>a(n),vis(n);
    for(int i=0;i<n;++i) {
        cin>>a[i];
        --a[i];
    }
    vector<int>len;
    int ans=1;
    for(int i=0;i<n;++i){
        if(vis[i]) continue;
        int nex=a[i],c=1;
        string b="";
        b+=s[i];
        while(nex!=i){
            ++c;
            vis[nex]=1;
            b+=s[nex];
            nex=a[nex];
        }
        ans=lcm(ans,find_rotations(b));
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}