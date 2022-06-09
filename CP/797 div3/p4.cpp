#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    vector<int>p;
    int c=0;
    for(int i=0;i<k;++i){
        if(s[i]=='W') ++c;
    }
    p.push_back(c);
    int l=0,r=k;
    while(l<=r && l<n && r<n){
        if(s[l]=='W'){
            --c;
        }
        ++l;
        if(s[r]=='W'){
            ++c;
        }
        ++r;
        p.push_back(c);
    }
    int m=INT_MAX;
    for(int i=0;i<p.size();++i){
        m=min(m,p[i]);
    }
    cout<<m<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    cin>>t;
    while(t--) solve();
}