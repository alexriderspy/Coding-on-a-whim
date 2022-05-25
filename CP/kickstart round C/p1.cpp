#include<bits/stdc++.h>
using namespace std;

void solve(){
    int sz=0;cin>>sz;
    string s;cin>>s;
    int dig=0,ups=0,downs=0,chs=0;
    for(int i=0;i<s.size();++i){
        if(s[i]-'a'>=0 && s[i]-'a'<26){
            downs++;
        }else if(s[i]-'A'>=0 && s[i]-'A'<26){
            ups++;
        }else if(s[i]=='#'||s[i]=='@'||s[i]=='*'||s[i]=='&'){
            chs++;
        }else if(s[i]-'0'>=0 && s[i]-'0'<=9){
            dig++;
        }
    }
    if(downs==0){
        s+="a";
    }
    if(ups==0){
        s+="A";
    }
    if(dig==0){
        s+="0";
    }
    if(chs==0){
        s+="#";
    }
    while(s.size()<7){
        s+="@";
    }
    cout<<s<<'\n';
}
int main(){
    int t;cin>>t;
    for(int tt=1;tt<=t;++tt){
        cout<<"Case #"<<tt<<":"<<' ';
        solve();
    }
}