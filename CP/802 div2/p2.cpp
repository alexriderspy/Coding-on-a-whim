#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin>>n;
    string s;cin>>s;
    n=s.size();
    string ans;ans=s;

    for(int i=0;i<n;++i){
        ans[i]=(9-(s[i]-'0'))+'0';            
    }
    
    if(s[0]=='9'){
        int c=0;
        string a = "0";
        a+=s;
        s=a;
        for(int i=n;i>0;--i){
            int v1 = s[i]-'0';
            if(1 >= (v1+c)){
                ans[i-1]=(1-(v1+c)) + '0';
                c=0;
            }else{
                ans[i-1] = ((11 - (v1+c)) +'0');
                c=1;
            }
        }
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