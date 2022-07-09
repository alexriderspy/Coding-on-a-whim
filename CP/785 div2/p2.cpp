#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    string s;cin>>s;
    int n=s.size();
    string a="";
    vector<int>ch(26);
    for(int i=0;i<n;++i){
        if(ch[s[i]-'a']){
            if(ch[s[i]-'a']!=1){
                cout<<"NO\n";return;
            }else{
                a=s.substr(0,i);break;
            }   
        }
        ch[s[i]-'a']=i+1;
    }
    if(a==""){
        cout<<"YES\n";return;
    }
    for(int j=a.size();j<n;++j){
        if(s[j]!=s[j%a.size()]){
            cout<<"NO\n";return;
        }
    }
    cout<<"YES\n";
    return;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--)
    solve();
}