#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    string s;cin>>s;
    int x,min;cin>>x;
    int hr=(s[0]-'0')*10 + (s[1]-'0');
    int m=(s[3]-'0')*10 + (s[4]-'0');
    min=m+hr*60;
    map<int,int>mp;
    int cnt=0;
    while(1){
        if(mp[min]){
            break;
        }
        hr=min/60;
        m=min%60;
        //cout<<hr<<' '<<m<<'\n';
        string h="",mi="";
        if(hr<=9){
            h+="0";
            h+=hr+'0';
        }else{
            h+=hr/10+'0';
            h+=hr%10+'0';
        }
        if(m<=9){
            mi+="0";
            mi+=m+'0';
        }else{
            mi+=m/10+'0';
            mi+=m%10+'0';
        }
        mp[min]++;
        min+=x;
        min%=(60*24);
        reverse(mi.begin(),mi.end());
        //cout<<h<<':'<<m<<'\n';
        if(h==mi) {
            cnt++;
        }
    }
    cout<<cnt<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}