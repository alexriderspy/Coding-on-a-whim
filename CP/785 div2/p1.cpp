#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    string s;cin>>s;
    int sum=0,m=25;
    vector<int>c(26);
    for(int i=0;i<s.size();++i) c[s[i]-'a']++,sum+=(s[i]-'a'+1),m=min(m,(int)(s[i]-'a'));
    if(s.size()==1){
        cout<<"Bob "<<s[0]-'a' + 1<<'\n';
    }else{
        if(s.size()%2){
            cout<<"Alice "<<max(sum-2*(s[0]-'a'+1),sum-2*(s[s.size()-1]-'a'+1))<<'\n';
        }else
        cout<<"Alice "<<sum<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--)
    solve();
}