#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n,a=0,b=0,c=0,l=-1;cin>>n;
    string s,t;cin>>s>>t;
    for(int i=0;i<n;++i){
        if(l==0 && s[i]=='c'){
            cout<<"NO\n";return;
        }
        if(l==2 && s[i]=='a'){
            cout<<"NO\n";return;
        }
        if(l==0 && s[i]=='b'){
            s[i]='a';
            --b;
            if(b==0){
                l=-1;
            }
        }
        if(l==2 && s[i]=='c'){
            s[i]='b';
            --c;
            if(c==0){
                l=-1;
            }
        }
        if(s[i]!=t[i]){
            if(s[i]=='a' && t[i]=='b'){
                l=0;
                ++b;
            }else if(s[i]=='b' && t[i]=='c'){
                l=2;
                ++c;
            }else{
                cout<<"NO\n";return;
            }
        }
    }
    if(l==-1){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}